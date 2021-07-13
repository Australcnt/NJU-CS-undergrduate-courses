#include "cpu/intr.h"
#include "cpu/instr.h"
#include "memory/memory.h"

void raise_intr(uint8_t intr_no)
{
#ifdef IA32_INTR
	// Trigger an exception/interrupt with 'intr_no'
    // 'intr_no' is the index to the IDT
    // Push EFLAGS, CS, and EIP
    // Find the IDT entry using 'intr_no'
    // Clear IF if it is an interrupt
    // Set EIP to the entry of the interrupt handler
    /*cpu.esp = cpu.esp - 4;
    vaddr_write(cpu.esp, SREG_SS, 4, cpu.eflags.val);
    cpu.esp = cpu.esp - 2;
    vaddr_write(cpu.esp, SREG_SS, 2, cpu.cs.val);
    cpu.esp = cpu.esp - 4;
    vaddr_write(cpu.esp, SREG_SS, 4, cpu.eip);
    uint32_t addr = (uint32_t)hw_mem + page_translate(segment_translate(cpu.idtr.base + 8 * intr_no, SREG_SS));
    GateDesc* gatedesc = (void*)addr;
    if(gatedesc->type == 0xe)
        cpu.eflags.IF = 0;
    else if(gatedesc->type == 0xf)
        cpu.eflags.IF = 1;
    cpu.eip = (gatedesc->offset_31_16 << 16) + gatedesc->offset_15_0;
*/

    GateDesc gatedesc;
    gatedesc.val[0] = laddr_read(cpu.idtr.base + intr_no * 8, 4);
    gatedesc.val[1] = laddr_read(cpu.idtr.base + intr_no * 8 + 4, 4); 
    push_(cpu.eflags.val);
    push_(cpu.cs.val);
    push_(cpu.eip);
    if (gatedesc.type == 0xe)
        cpu.eflags.IF = 0;
    else if(gatedesc.type == 0xf)
        cpu.eflags.IF = 1;
    cpu.cs.val = gatedesc.selector;
    load_sreg(1);
    cpu.eip = (gatedesc.offset_31_16 << 16) + gatedesc.offset_15_0;
#endif
}

void raise_sw_intr(uint8_t intr_no)
{
	// return address is the next instruction
	cpu.eip += 2;
	raise_intr(intr_no);
}
