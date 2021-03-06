#include "cpu/instr.h"

make_instr_func(lgdt)
{
    int len = 1;
    OPERAND rel;
    rel.type = OPR_IMM;
    
    rel.data_size = 16;
    len += modrm_rm(eip + 1, &rel);
    operand_read(&rel);
    cpu.gdtr.limit = rel.val;
    
    rel.data_size = 32;
    rel.addr += 2;
    operand_read(&rel);
    cpu.gdtr.base = rel.val;
    
    print_asm_1("lgdt", "", len, &rel);
    return len;
}
