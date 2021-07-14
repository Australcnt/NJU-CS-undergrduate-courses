#include "x86.h"
#include "device.h"

extern TSS tss;
extern ProcessTable pcb[MAX_PCB_NUM];
extern int current;

extern int displayRow;
extern int displayCol;

void GProtectFaultHandle(struct StackFrame *sf);

void timerHandle(struct StackFrame *sf);

void syscallHandle(struct StackFrame *sf);

void syscallWrite(struct StackFrame *sf);
void syscallPrint(struct StackFrame *sf);

void syscallFork(struct StackFrame *sf);
void syscallSleep(struct StackFrame *sf);
void syscallExit(struct StackFrame *sf);


void irqHandle(struct StackFrame *sf) { // pointer sf = esp
	/* Reassign segment register */
	asm volatile("movw %%ax, %%ds"::"a"(KSEL(SEG_KDATA)));
	/*TODO Save esp to stackTop */
	uint32_t tmpStackTop = pcb[current].stackTop;
	pcb[current].prevStackTop = pcb[current].stackTop;
	pcb[current].stackTop = (uint32_t)sf;

	switch(sf->irq) {
		case -1:
			break;
		case 0xd:
			GProtectFaultHandle(sf);
			break;
		case 0x20:
			timerHandle(sf);
			break;
		case 0x80:
			syscallHandle(sf);
			break;
		default:assert(0);
	}
	/*TODO Recover stackTop */
	pcb[current].stackTop = tmpStackTop;
}

void GProtectFaultHandle(struct StackFrame *sf) {
	assert(0);
	return;
}

void timerHandle(struct StackFrame *sf) {
	// 遍历pcb，将状态为STATE_BLOCKED的进程的sleepTime减一，如果进程的sleepTime变为0，重新设为STATE_RUNNABLE
	for (int i = 0; i < MAX_PCB_NUM; i++) {
		if (pcb[i].state == STATE_BLOCKED) {
			pcb[i].sleepTime--;
			if (pcb[i].sleepTime <= 0)
				pcb[i].state = STATE_RUNNABLE;
		}
	}
	// 将当前进程的timeCount加一，如果时间片用完（timeCount==MAX_TIME_COUNT）且有其它状态为STATE_RUNNABLE的进程，切换，否则继续执行当前进程
	if(pcb[current].state == STATE_RUNNING) {
		pcb[current].timeCount++;
		if (pcb[current].timeCount >= MAX_TIME_COUNT) {
			pcb[current].state = STATE_RUNNABLE;
			pcb[current].timeCount = 0;
		}
		else
			return;
	}
	int i;
	for (i = (current + 1) % MAX_PCB_NUM; i != current; i = (i + 1) % MAX_PCB_NUM) {
			if (pcb[i].state == STATE_RUNNABLE)
				break;
		}
	current = i;
	pcb[current].state = STATE_RUNNING;
	// 进程切换
	uint32_t tmpStackTop;
	tmpStackTop = pcb[current].stackTop;
	pcb[current].stackTop = pcb[current].prevStackTop;
	tss.esp0 = (uint32_t)&(pcb[current].stackTop);
	asm volatile("movl %0, %%esp"::"m"(tmpStackTop)); // switch kernel stack
	asm volatile("popl %gs");
	asm volatile("popl %fs");
	asm volatile("popl %es");
	asm volatile("popl %ds");
	asm volatile("popal");
	asm volatile("addl $8, %esp");
	asm volatile("iret");
	return;
}

void syscallHandle(struct StackFrame *sf) {
	switch(sf->eax) { // syscall number
		case 0:
			syscallWrite(sf);
			break; // for SYS_WRITE
		/*TODO Add Fork,Sleep... */
		case 1:
			syscallFork(sf);
			break; // for SYS_FORK
		case 3:
			syscallSleep(sf);
			break; // for SYS_SLEEP
		case 4:
			syscallExit(sf);
			break; // for SYS_EXIT
		default:break;
	}
}

void syscallWrite(struct StackFrame *sf) {
	switch(sf->ecx) { // file descriptor
		case 0:
			syscallPrint(sf);
			break; // for STD_OUT
		default:break;
	}
}

void syscallPrint(struct StackFrame *sf) {
	int sel = sf->ds; //TODO segment selector for user data, need further modification
	char *str = (char*)sf->edx;
	int size = sf->ebx;
	int i = 0;
	int pos = 0;
	char character = 0;
	uint16_t data = 0;
	asm volatile("movw %0, %%es"::"m"(sel));
	for (i = 0; i < size; i++) {
		asm volatile("movb %%es:(%1), %0":"=r"(character):"r"(str+i));
		if(character == '\n') {
			displayRow++;
			displayCol=0;
			if(displayRow==25){
				displayRow=24;
				displayCol=0;
				scrollScreen();
			}
		}
		else {
			data = character | (0x0c << 8);
			pos = (80*displayRow+displayCol)*2;
			asm volatile("movw %0, (%1)"::"r"(data),"r"(pos+0xb8000));
			displayCol++;
			if(displayCol==80){
				displayRow++;
				displayCol=0;
				if(displayRow==25){
					displayRow=24;
					displayCol=0;
					scrollScreen();
				}
			}
		}
		//asm volatile("int $0x20"); //XXX Testing irqTimer during syscall
		//asm volatile("int $0x20":::"memory"); //XXX Testing irqTimer during syscall
	}
	
	updateCursor(displayRow, displayCol);
	//TODO take care of return value
	return;
}

void syscallFork(struct StackFrame *sf) {
    // 在寻找一个空闲的pcb做为子进程的进程控制块
	int i;
	for (i = 0; i < MAX_PCB_NUM; i++) {
		if (pcb[i].state == STATE_DEAD)
			break;
	}
	// 如果没有空闲pcb，则fork失败，父进程返回-1
	if (i == MAX_PCB_NUM) {
		pcb[current].regs.eax = -1;
		return;
	}
	// 将父进程的资源复制给子进程
	enableInterrupt();
	for (int j = 0; j < 0x100000; j++) {
		*(uint8_t *)(j + (i + 1) * 0x100000) = *(uint8_t *)(j + (current + 1) * 0x100000);
		if (j % 0x10000 == 0)
			asm volatile("int $0x20"); //XXX Testing irqTimer during syscall
	}
	disableInterrupt();
	// Set stack
	for (int k = 0; k < MAX_STACK_SIZE; k++) {
		pcb[i].stack[k] = pcb[current].stack[k];
	}
	// Set TrapFrame
	pcb[i].regs.gs = USEL(i * 2 + 2);
	pcb[i].regs.fs = USEL(i * 2 + 2);
	pcb[i].regs.es = USEL(i * 2 + 2);
	pcb[i].regs.ds = USEL(i * 2 + 2);
	pcb[i].regs.edi = pcb[current].regs.edi;
	pcb[i].regs.esi = pcb[current].regs.esi;
	pcb[i].regs.ebp = pcb[current].regs.ebp;
	pcb[i].regs.xxx = pcb[current].regs.xxx;
	pcb[i].regs.ebx = pcb[current].regs.ebx;
	pcb[i].regs.edx = pcb[current].regs.edx;
	pcb[i].regs.ecx = pcb[current].regs.ecx;
	pcb[i].regs.eax = 0; // 成功则子进程返回0
	pcb[i].regs.irq = pcb[current].regs.irq;
	pcb[i].regs.error = pcb[current].regs.error;
	pcb[i].regs.eip = pcb[current].regs.eip;
	pcb[i].regs.cs = USEL(i * 2 + 1);
	pcb[i].regs.eflags = pcb[current].regs.eflags;
	pcb[i].regs.esp = pcb[current].regs.esp;
	pcb[i].regs.ss = USEL(i * 2 + 2);
	// Set stackTop
	pcb[i].stackTop = (uint32_t)&(pcb[i].regs);
	// Set preStackTop
	pcb[i].prevStackTop = (uint32_t)&(pcb[i].stackTop);
	// set State
	pcb[i].state = STATE_RUNNABLE;
	// Set timeCount
	pcb[i].timeCount = 0;
	// Set sleepTime
	pcb[i].sleepTime = 0;
	// Set pid
	pcb[i].pid = i;
	// 成功则父进程返回子进程pid
	pcb[current].regs.eax = i;
	return;
}

void syscallSleep(struct StackFrame *sf) {
	// 若传入的参数合法，则将当前的进程的sleepTime设置为传入的参数，将当前进程的状态设置为STATE_BLOCKED
	if (sf->ecx > 0) {
		pcb[current].sleepTime = sf->ecx;
		pcb[current].state = STATE_BLOCKED;
		// 模拟时钟中断
		asm volatile("int $0x20");
	}
	return;
}

void syscallExit(struct StackFrame *sf) {
	// 将当前进程的状态设置为STATE_DEAD
	pcb[current].state = STATE_DEAD;
	// 模拟时钟中断
	asm volatile("int $0x20");
	return;
}