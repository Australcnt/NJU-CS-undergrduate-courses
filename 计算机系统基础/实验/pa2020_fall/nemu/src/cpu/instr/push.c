#include "cpu/instr.h"

void push_(uint32_t val)
{
    OPERAND src_copy;
	src_copy.type = OPR_MEM;
	src_copy.sreg = SREG_SS;
	src_copy.val = val;
	src_copy.data_size = data_size;
	cpu.esp = cpu.esp - data_size / 8;
	src_copy.addr = cpu.esp;
	operand_write(&src_copy);
}

static void instr_execute_1op()
{
    operand_read(&opr_src);
    push_(sign_ext(opr_src.val, opr_src.data_size));
}

/*
static void instr_execute_1op()
{
    operand_read(&opr_src);
    src_copy.type = OPR_MEM;
	src_copy.sreg = SREG_SS;
	src_copy.val = opr_src.val;
	src_copy.data_size = data_size;
	cpu.esp = cpu.esp - data_size / 8;
	src_copy.addr = cpu.esp;
	operand_write(&src_copy);
}
*/

make_instr_impl_1op(push, i, v)
make_instr_impl_1op(push, r, v)
make_instr_impl_1op(push, rm, v)
make_instr_impl_1op(push, i, b)

/*
make_instr_func(pusha)
{
	print_asm_0("pusha", "", 1);
	
	opr_dest.type = OPR_MEM;
	opr_dest.data_size = 32;
	opr_dest.sreg = SREG_SS;

    //uint32_t temp = cpu.esp;

    // push EAX
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.eax;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);

    // push ECX
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.ecx;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);

    // push EDX
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.edx;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);

    // push EBX
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.ebx;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);

    // push ESP
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.esp;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);

    // push EBP
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.ebp;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);

    // push ESI
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.esi;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);

    // push EDI
	cpu.esp = cpu.esp - data_size / 8;
	opr_dest.val = cpu.edi;
	opr_dest.addr = cpu.esp;
	operand_write(&opr_dest);
	
	return 1;
}
*/

make_instr_func(pusha) 
{
    int len = 1;
    //uint32_t temp = cpu.esp;
    for (int i = 0; i < 8; i++)
    {
        //if(i == 4)
            //push_(sign_ext(temp, data_size));
        //else
            push_(sign_ext(cpu.gpr[i].val, data_size));
    }
    return len;
}
