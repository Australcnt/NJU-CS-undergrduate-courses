#include "cpu/intr.h"
#include "cpu/instr.h"

make_instr_func(int_)
{
    OPERAND res;
    res.type = OPR_IMM;
    res.data_size = 8;
    res.addr = eip + 1;
    res.sreg = SREG_CS;
    operand_read(&res);

    print_asm_1("int", "", 2, &res);

    if(cpu.cr0.pe == 1)
        raise_sw_intr(res.val);

    return 0;
}
