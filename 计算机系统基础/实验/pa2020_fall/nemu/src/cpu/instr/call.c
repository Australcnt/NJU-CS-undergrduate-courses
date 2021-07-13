#include "cpu/instr.h"

make_instr_func(call_near)
{
	int len = 1;
	opr_src.type = OPR_IMM;
	opr_src.sreg = SREG_CS;
	opr_src.addr = eip + 1;
	opr_src.data_size = data_size;
	operand_read(&opr_src);
	print_asm_1("call", "", len + data_size / 8, &opr_src);
	
	
	OPERAND eip_copy;
	eip_copy.type = OPR_MEM;
	eip_copy.val = eip + len + data_size / 8;
	eip_copy.data_size = data_size;
	
	cpu.esp = cpu.esp - data_size / 8;
	eip_copy.addr = cpu.esp;
	operand_write(&eip_copy);
	
	eip = eip + len + data_size / 8;
	cpu.eip = eip + opr_src.val;
	if(data_size == 16)
	    cpu.eip = cpu.eip & 0x0000FFFF;
	    
	return 0;
}

make_instr_func(call_near_indirect)
{
	OPERAND abs;
    abs.type = OPR_IMM;
    abs.sreg = SREG_CS;
    abs.data_size = data_size;
    int len = 1 + modrm_rm(eip + 1, &abs);
    operand_read(&abs);
        
    int offset = sign_ext(abs.val, data_size);

    print_asm_1("jmp", "", 1 + data_size / 8, &abs);
    
    OPERAND eip_copy;
    eip_copy.type = OPR_MEM;
    eip_copy.data_size = data_size;
    eip_copy.addr = cpu.esp - data_size / 8;
    eip_copy.val = cpu.eip + len;
    cpu.esp = cpu.esp - data_size / 8;
    operand_write(&eip_copy);

    cpu.eip = offset;
    if(data_size == 16)
	    cpu.eip = cpu.eip & 0x0000FFFF;

    return 0;
}