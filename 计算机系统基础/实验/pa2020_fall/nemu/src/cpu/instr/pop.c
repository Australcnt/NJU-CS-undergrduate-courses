#include "cpu/instr.h"

uint32_t pop_()
{
    OPERAND dest_copy;
	dest_copy.type = OPR_MEM;
	dest_copy.sreg = SREG_SS;
	dest_copy.addr = cpu.esp;
	dest_copy.data_size = data_size;
	operand_read(&dest_copy);
	cpu.esp = cpu.esp + data_size / 8;
    return dest_copy.val;
}

static void instr_execute_1op()
{
    opr_src.val = pop_();
    operand_write(&opr_src);
}

make_instr_impl_1op(pop, rm, v)
make_instr_impl_1op(pop, r, v)

/*
static void instr_execute_1op() 
{
    OPERAND dest_copy;
	dest_copy.type = OPR_MEM;
	dest_copy.sreg = SREG_SS;
	dest_copy.addr = cpu.esp;
	dest_copy.data_size = data_size;
	operand_read(&dest_copy);
	cpu.esp = cpu.esp + data_size / 8;
	opr_src.val = dest_copy.val;
	operand_write(&opr_src);
}
*/

/*
make_instr_func(popa)
{
	print_asm_0("popa", "", 1);

	opr_src.type = OPR_MEM;
	opr_src.data_size = 32;
	opr_src.sreg = SREG_SS;

    //uint32_t throwaway = cpu.esp;

    // pop EDI
	opr_src.addr = cpu.esp;
	operand_read(&opr_src);
	cpu.edi = opr_src.val;
	cpu.esp = cpu.esp + data_size / 8;

    // pop ESI
	opr_src.addr = cpu.esp;
	operand_read(&opr_src);
	cpu.esi = opr_src.val;
	cpu.esp = cpu.esp + data_size / 8;

    // pop EBP
	opr_src.addr = cpu.esp;
	operand_read(&opr_src);
	cpu.ebp = opr_src.val;
	cpu.esp = cpu.esp + data_size / 8;

    // pop ESP
    opr_src.addr = cpu.esp;
    operand_read(&opr_src);
    //throwaway = opr_src.val;// skip ESP
	cpu.esp = cpu.esp + data_size / 8;
   

    // pop EBX
	opr_src.addr = cpu.esp;
	operand_read(&opr_src);
	cpu.ebx = opr_src.val;
	cpu.esp = cpu.esp + data_size / 8;

    // pop EDX
	opr_src.addr = cpu.esp;
	operand_read(&opr_src);
	cpu.edx = opr_src.val;
	cpu.esp = cpu.esp + data_size / 8;

    // pop ECX
	opr_src.addr = cpu.esp;
	operand_read(&opr_src);
	cpu.ecx = opr_src.val;
	cpu.esp = cpu.esp + data_size / 8;

    // pop EAX
	opr_src.addr = cpu.esp;
	operand_read(&opr_src);
	cpu.eax = opr_src.val;
	cpu.esp = cpu.esp + data_size / 8;

	return 1;
}
*/

make_instr_func(popa)
{
    int len = 1;
    for (int i = 7; i >= 0; i--)
    {
        uint32_t val = pop_(data_size);
        if (i == 4)
            continue;
        if (data_size == 16)
            cpu.gpr[i]._16 = val;
        else
            cpu.gpr[i]._32 = val;
    }
    return len;
}
