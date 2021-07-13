#include "cpu/instr.h"
#include "device/port_io.h"

make_instr_func(out_b)
{
    pio_write(cpu.gpr[2]._16, 1, cpu.gpr[0]._8[0]);
    return 1;
}

make_instr_func(out_v)
{
    pio_write(cpu.gpr[2]._16, data_size >> 3, cpu.eax & (0xFFFFFFFF >> (32-data_size)));
    return 1;
}
