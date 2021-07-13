#include "cpu/cpu.h"
#include "memory/memory.h"

// return the linear address from the virtual address and segment selector
uint32_t segment_translate(uint32_t offset, uint8_t sreg)
{
	/* TODO: perform segment translation from virtual address to linear address
	 * by reading the invisible part of the segment register 'sreg'
	 */
	return cpu.segReg[sreg].base + offset;
}

// load the invisible part of a segment register
void load_sreg(uint8_t sreg)
{
	/* TODO: load the invisibile part of the segment register 'sreg' by reading the GDT.
	 * The visible part of 'sreg' should be assigned by mov or ljmp already.
	 */
	SegDesc segdesc;
	segdesc.val[0] = laddr_read(cpu.gdtr.base + (uint32_t)cpu.segReg[sreg].index * sizeof(SegDesc), 4);
	segdesc.val[1] = laddr_read(cpu.gdtr.base + (uint32_t)cpu.segReg[sreg].index * sizeof(SegDesc) + 4, 4);
	cpu.segReg[sreg].base = (segdesc.base_31_24 << 24) + (segdesc.base_23_16 << 16) + segdesc.base_15_0;
	cpu.segReg[sreg].limit = (segdesc.limit_19_16 << 16) + segdesc.limit_15_0;
	cpu.segReg[sreg].privilege_level = segdesc.privilege_level;
	assert(segdesc.present == 1);
	assert(cpu.segReg[sreg].base == 0);
	assert(cpu.segReg[sreg].limit == 0xfffff);
	assert(segdesc.granularity == 1);
}
