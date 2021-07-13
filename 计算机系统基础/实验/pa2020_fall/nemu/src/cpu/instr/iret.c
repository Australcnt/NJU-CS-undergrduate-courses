#include "cpu/instr.h"

make_instr_func(iret)
{
	print_asm_0("iret", "", 1);

	cpu.eip = vaddr_read(cpu.esp, SREG_SS, 4);
	cpu.esp = cpu.esp + 4;
	cpu.cs.val = vaddr_read(cpu.esp, SREG_SS, 4);
	cpu.esp = cpu.esp + 4;
	cpu.eflags.val = vaddr_read(cpu.esp, SREG_SS, 4);
	cpu.esp = cpu.esp + 4;

	return 0;
}
