#include "cpu/instr.h"

make_instr_func(leave) 
{
	int len = 1;
	cpu.esp = cpu.ebp;
	
	OPERAND ebp_copy;
	ebp_copy.type = OPR_MEM;
	ebp_copy.data_size = data_size;
	ebp_copy.sreg = SREG_DS;
	ebp_copy.addr = cpu.esp;
	operand_read(&ebp_copy);
	cpu.ebp = ebp_copy.val;
	cpu.esp = cpu.esp + data_size / 8;

	print_asm_0("leave", "", len);
	return len;
}