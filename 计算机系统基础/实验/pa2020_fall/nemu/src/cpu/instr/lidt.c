#include "cpu/instr.h"

make_instr_func(lidt)
{
	int len = 1;
	OPERAND res;
    res.type = OPR_IMM;
    res.sreg = SREG_DS;
    res.data_size = 16;

    len += modrm_rm(eip + 1, &res);
	operand_read(&res);
	cpu.idtr.limit = res.val & 0xffff;

	res.data_size = 32;
    res.addr += 2;
	operand_read(&res);
	cpu.idtr.base = res.val;
    if(data_size == 16)
    {
        cpu.idtr.base = cpu.idtr.base & 0xffffff;
    }

	print_asm_1("lidt", "", len, &res);

 	return len;
}
