#include "cpu/instr.h"

make_instr_func(ret_near) 
{
	OPERAND eip_copy;
	eip_copy.type = OPR_MEM;
	eip_copy.sreg = SREG_SS;
	eip_copy.addr = cpu.esp;
	eip_copy.data_size = data_size;
	operand_read(&eip_copy);
	cpu.esp = cpu.esp + data_size / 8;
	print_asm_0("ret", "", 1);
	
	cpu.eip = eip_copy.val;
	if(data_size == 16)
	    cpu.eip = cpu.eip & 0x0000FFFF;

	return 0;
}

make_instr_func(ret_near_imm16) 
{
	OPERAND eip_copy;
	eip_copy.type = OPR_MEM;
	eip_copy.sreg = SREG_SS;
	eip_copy.addr = cpu.esp;
	eip_copy.data_size = data_size;
	operand_read(&eip_copy);
	cpu.esp = cpu.esp + data_size / 8;
    opr_src.data_size = 16;
	operand_read(&opr_src);
	cpu.esp = cpu.esp + opr_src.val;
	print_asm_1("ret", "", 2, &opr_src);
	
	cpu.eip = eip_copy.val;
	if(data_size == 16)
	    cpu.eip = cpu.eip & 0x0000FFFF;
	
	return 0;
}
