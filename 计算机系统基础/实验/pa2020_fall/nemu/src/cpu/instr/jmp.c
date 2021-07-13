#include "cpu/instr.h"

make_instr_func(jmp_near)
{
    OPERAND rel;
    rel.type = OPR_IMM;
    rel.sreg = SREG_CS;
    rel.data_size = data_size;
    rel.addr = eip + 1;

    operand_read(&rel);

    int offset = sign_ext(rel.val, data_size);
    // thank Ting Xu from CS'17 for finding this bug
    print_asm_1("jmp", "", 1 + data_size / 8, &rel);

    cpu.eip += offset;

    return 1 + data_size / 8;
}

make_instr_func(jmp_short)
{
    OPERAND rel;
    rel.type = OPR_IMM;
    rel.sreg = SREG_CS;
    rel.data_size = 8;
    rel.addr = eip + 1;

    operand_read(&rel);

    int offset = sign_ext(rel.val, 8);
    print_asm_1("jmp", "", 1 + 8 / 8, &rel);

    cpu.eip += offset;

    return 1 + 8 / 8;
}

make_instr_func(jmp_near_indirect)
{
    OPERAND abs;
    abs.type = OPR_IMM;
    abs.sreg = SREG_CS;
    abs.data_size = data_size;
    int len = 1 + modrm_rm(eip + 1, &abs);
    operand_read(&abs);

    print_asm_1("jmp", "", len, &abs);

    if(data_size == 16)
        cpu.eip = abs.val & 0xffff;
    else
        cpu.eip = abs.val;

    return 0;
}

make_instr_func(jmp_far_imm)
{
    OPERAND src;
    src.type = OPR_IMM;
    src.sreg = SREG_CS;
    src.data_size = 16;
    src.addr = eip + 5;
    
    OPERAND dest;
    dest.type = OPR_IMM;
    dest.sreg = SREG_CS;
    dest.data_size = 32;
    dest.addr = eip + 1;
    
    operand_read(&src);
    operand_read(&dest);
    
    print_asm_2("ljmp", "", 7, &src, &dest);
    
    cpu.cs.val = src.val;
    load_sreg(1);
    
    if(data_size == 16)
        cpu.eip = dest.val & 0xffff;
    else
        cpu.eip = dest.val;
    
    return 0;
}