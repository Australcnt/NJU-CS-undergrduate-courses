/* Real Mode Hello World */
/*.code16
.global start
start:
    movw %cs, %ax
    movw %ax, %ds
    movw %ax, %es
    movw %ax, %ss
    movw $0x7d00, %ax
    movw %ax, %sp # setting stack pointer to 0x7d00
    pushw $13 # pushing the size to print into stack
    pushw $message # pushing the address of message into stack
    callw displayStr # calling the display function
loop:
    jmp loop

message:
    .string "Hello, World!\n\0"

displayStr:
    pushw %bp
    movw 4(%esp), %ax
    movw %ax, %bp
    movw 6(%esp), %cx
    movw $0x1301, %ax
    movw $0x000c, %bx
    movw $0x0000, %dx
    int $0x10
    popw %bp
    ret
*/

/* Protected Mode Hello World */
/*.code16

.global start
start:
	movw %cs, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %ss

.code32
start32:
	movw $0x10, %ax # setting data segment selector
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %ss
loop32:
	jmp loop32


.p2align 2
*/

/* Protected Mode Loading Hello World APP */
.code16

.global start
start:
	movw %cs, %ax
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %ss
	#TODO: Protected Mode Here
        cli                             #关闭中断
        inb $0x92, %al                  #启动A20总线
        orb $0x02, %al
	outb %al, $0x92
        data32 addr32 lgdt gdtDesc      #加载GDTR
        movl %cr0, %eax                 #启动保护模式
	orb $0x01, %al
	movl %eax, %cr0                 #设置CR0的PE位（第0位）为1
        data32 ljmp $0x08, $start32     #长跳转切换至保护模式

.code32
start32:
	movw $0x10, %ax # setting data segment selector
	movw %ax, %ds
	movw %ax, %es
	movw %ax, %fs
	movw %ax, %ss
	movw $0x18, %ax # setting graphics data segment selector
	movw %ax, %gs
	
	movl $0x8000, %eax # setting esp
	movl %eax, %esp
	jmp bootMain # jump to bootMain in boot.c

.p2align 2
gdt: 
	#GDT definition here
        .word 0,0                       #GDT第一个表项必须为空
	.byte 0,0,0,0

	.word 0xffff,0                  #代码段描述符
	.byte 0,0x9a,0xcf,0

	.word 0xffff,0                  #数据段描述符
	.byte 0,0x92,0xcf,0

	.word 0xffff,0x8000             #视频段描述符
	.byte 0x0b,0x92,0xcf,0

gdtDesc: 
	#gdtDesc definition here
        .word (gdtDesc - gdt -1)
        .long gdt
