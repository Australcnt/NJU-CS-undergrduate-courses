#include "cpu/cpu.h"

uint32_t alu_add(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint32_t res = 0;
    res = dest + src;
    
    set_CF_add(res, src, data_size);
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    set_OF_add(res, src, dest, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));
}

uint32_t alu_adc(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint32_t res = 0;
    res = dest + src + cpu.eflags.CF;
    
    set_CF_adc(res, src, data_size);
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    set_OF_adc(res, src, dest, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));
}

uint32_t alu_sub(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint32_t src_c = 0;
    uint32_t res = 0;
    src_c = (src ^ 0xFFFFFFFF) & (0xFFFFFFFF >> (32 - data_size));
    res = dest + src_c + 1;

    if(dest < src)
        cpu.eflags.CF = 1;
    else
        cpu.eflags.CF = 0;
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    set_OF_sub(res, src_c, dest, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));
}

uint32_t alu_sbb(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint32_t src_c = 0;
    uint32_t res = 0;
    src_c = (src ^ 0xFFFFFFFF) & (0xFFFFFFFF >> (32 - data_size));
    res = dest - (src + cpu.eflags.CF);
    
    if(cpu.eflags.CF == 0)
    {
        if(dest < src)
            cpu.eflags.CF = 1;
        else
            cpu.eflags.CF = 0;
    }
    else
    {
        if(dest <= src)
            cpu.eflags.CF = 1;
        else
            cpu.eflags.CF = 0;
    }
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    set_OF_sbb(res, src_c, dest, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));
}

uint64_t alu_mul(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint64_t res = 0;
    res = (uint64_t)dest * (uint64_t)src;
    
    switch(data_size)
    {
        case 8:
            cpu.eflags.CF = ((res & 0xFFFFFFFFFFFFFF00) != 0);
            break;
        case 16:
            cpu.eflags.CF = ((res & 0xFFFFFFFFFFFF0000) != 0);
            break;
        case 32:
            cpu.eflags.CF = ((res & 0xFFFFFFFF00000000) != 0);
            break;
    }
    cpu.eflags.OF = cpu.eflags.CF;
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    
    return res & (0xFFFFFFFFFFFFFFFF >> (64 - data_size * 2));
}

int64_t alu_imul(int32_t src, int32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    int64_t res = 0;
    switch(data_size)
    {
        case 8:
            res = (int16_t)(int8_t)dest * (int16_t)(int8_t)src;
            break;
        case 16:
            res = (int32_t)(int16_t)dest * (int32_t)(int16_t)src;
            break;
        case 32:
            res = (int64_t)dest * (int64_t)src;
            break;
    }
    
    return res;
}

// need to implement alu_mod before testing
uint32_t alu_div(uint64_t src, uint64_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFFFFFFFFFF >> (64 - data_size));
    src = src & (0xFFFFFFFFFFFFFFFF >> (64 - data_size));
    
    if(src == 0)
    {
        printf("Floating point exception");
        assert(0);
    }
    
    uint64_t res = 0;
    res = dest / src;
    
    return res;
}

// need to implement alu_imod before testing
int32_t alu_idiv(int64_t src, int64_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFFFFFFFFFF >> (64 - data_size));
    src = src & (0xFFFFFFFFFFFFFFFF >> (64 - data_size));
    
    if(src == 0 || (dest == 0xFFFFFFFF80000000 && src == -1))
    {
        printf("Floating point exception");
        assert(0);
    }
    
    int32_t res = 0;
    switch(data_size)
    {
        case 8:
            res = (int32_t)(int8_t)dest / (int32_t)(int8_t)src;
            break;
        case 16:
            res = (int32_t)(int16_t)dest / (int32_t)(int16_t)src;
            break;
        case 32:
            res = (int32_t)dest / (int32_t)src;
            break;
        case 64:
            res = (int32_t)(dest / src);
            break;
    }
    
    return res;
}

uint32_t alu_mod(uint64_t src, uint64_t dest)
{
    uint64_t res = 0;
    res = dest % src;

    return res;
}

int32_t alu_imod(int64_t src, int64_t dest)
{
    int32_t res = 0;
    res = (int32_t)(dest % src);

    return res;
}

uint32_t alu_and(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint32_t res = 0;
    res = dest & src;
    
    cpu.eflags.CF = 0;
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    cpu.eflags.OF = 0;
    
    return res & (0xFFFFFFFF >> (32 - data_size));
}

uint32_t alu_xor(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint32_t res = 0;
    res = dest ^ src;
    
    cpu.eflags.CF = 0;
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    cpu.eflags.OF = 0;
    
    return res & (0xFFFFFFFF >> (32 - data_size));
}

uint32_t alu_or(uint32_t src, uint32_t dest, size_t data_size)
{
    dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & (0xFFFFFFFF >> (32 - data_size));
    
    uint32_t res = 0;
    res = dest | src;
    
    cpu.eflags.CF = 0;
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    cpu.eflags.OF = 0;
    
    return res & (0xFFFFFFFF >> (32 - data_size));
}

uint32_t alu_shl(uint32_t src, uint32_t dest, size_t data_size)
{
    /*dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & 0x0000001F;
    
    uint32_t res = dest;
    
    for(int i = src; i > 0; i--)
    {
        set_SF(res, data_size);
        cpu.eflags.CF = cpu.eflags.SF;
        res = res * 2;
    }
    
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));*/
	if (src == 0)
		return dest & (0xFFFFFFFF >> (32 - data_size));
    else
    {
	    uint32_t temp = dest << (src - 1);
	    uint32_t res = temp << 1;
	    temp = sign_ext(temp & (0xFFFFFFFF >> (32 - data_size)), data_size);
	    cpu.eflags.CF = sign(temp);
	    set_PF(res);
        // set_AF();
	    set_ZF(res, data_size);
	    set_SF(res, data_size);
	    cpu.eflags.OF = 0;
	    return res & (0xFFFFFFFF >> (32 - data_size));
    }
}

uint32_t alu_shr(uint32_t src, uint32_t dest, size_t data_size)
{
    /*dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & 0x0000001F;
    
    uint32_t res = dest;
    
    for(int i = src; i > 0; i--)
    {
        if(res % 2 == 0)
            cpu.eflags.CF = 0;
        else
            cpu.eflags.CF = 1;
        res = res / 2;
    }
    
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));*/
	if (src == 0)
		return dest & (0xFFFFFFFF >> (32 - data_size));
    else
    {
	    dest = dest & (0xFFFFFFFF >> (32 - data_size));
	    uint32_t temp = dest >> (src - 1);
	    uint32_t res = temp >> 1;
	    cpu.eflags.CF = temp & 0x1;
	    set_PF(res);
        // set_AF();
	    set_ZF(res, data_size);
	    set_SF(res, data_size);
	    cpu.eflags.OF = 0;
	    return res & (0xFFFFFFFF >> (32 - data_size));
    }
}

uint32_t alu_sar(uint32_t src, uint32_t dest, size_t data_size)
{
    /*dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & 0x0000001F;
    
    uint32_t res = dest;
    
    for(int i = src; i > 0; i--)
    {
        if(res % 2 == 0)
            cpu.eflags.CF = 0;
        else
            cpu.eflags.CF = 1;
        set_SF(res, data_size);
        if(cpu.eflags.SF == 0)
            res = res / 2;
        else
        {
            if(data_size == 8)
                res = res / 2 + 0x00000080;
            else if(data_size == 16)
                res = res / 2 + 0x00008000;
            else
                res = res / 2 + 0x80000000;
        }
    }
    
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));*/
	if (src == 0)
		return dest & (0xFFFFFFFF >> (32 - data_size));
    else
    {
	    dest = dest & (0xFFFFFFFF >> (32 - data_size));
        uint32_t res = 0;
	    switch (data_size)
	    {
	        case 32:
	        {
		        int32_t temp = (int32_t)dest >> (src - 1);
		        res = temp >> 1;
		        cpu.eflags.CF = temp & 0x1;
		        break;
	        }
	        case 16:
	        {
		        int16_t temp = (int16_t)dest >> (src - 1);
		        res = temp >> 1;
		        cpu.eflags.CF = temp & 0x1;
		        break;
	        }
            case 8:
	        {
		        int8_t temp = (int8_t)dest >> (src - 1);
		        res = temp >> 1;
		        cpu.eflags.CF = temp & 0x1;
		        break;
	        }
	        default:
		        break;
	    }
	    set_PF(res);
        // set_AF();
	    set_ZF(res, data_size);
	    set_SF(res, data_size);
	    cpu.eflags.OF = 0;
	    return res & (0xFFFFFFFF >> (32 - data_size));
    }
}

uint32_t alu_sal(uint32_t src, uint32_t dest, size_t data_size)
{
    /*dest = dest & (0xFFFFFFFF >> (32 - data_size));
    src = src & 0x0000001F;
    
    uint32_t res = dest;
    
    for(int i = src; i > 0; i--)
    {
        set_SF(res, data_size);
        cpu.eflags.CF = cpu.eflags.SF;
        res = res * 2;
    }
    
    set_PF(res);
    // set_AF();
    set_ZF(res, data_size);
    set_SF(res, data_size);
    
    return res & (0xFFFFFFFF >> (32 - data_size));*/
	if (src == 0)
		return dest & (0xFFFFFFFF >> (32 - data_size));
    else
    {
	    uint32_t temp = dest << (src - 1);
	    uint32_t res = temp << 1;
	    temp = sign_ext(temp & (0xFFFFFFFF >> (32 - data_size)), data_size);
	    cpu.eflags.CF = sign(temp);
	    set_PF(res);
        // set_AF();
	    set_ZF(res, data_size);
	    set_SF(res, data_size);
	    cpu.eflags.OF = 0;
	    return res & (0xFFFFFFFF >> (32 - data_size));
    }
}


//辅助函数

//CF contains information relevant to unsigned integers
void set_CF_add(uint32_t result, uint32_t src, size_t data_size)
{
    result = sign_ext(result & (0xFFFFFFFF >> (32 - data_size)), data_size);
    src = sign_ext(src & (0xFFFFFFFF >> (32 - data_size)), data_size);
    cpu.eflags.CF = result < src;
}

void set_CF_adc(uint32_t result, uint32_t src, size_t data_size)
{
    result = sign_ext(result & (0xFFFFFFFF >> (32 - data_size)), data_size);
    src = sign_ext(src & (0xFFFFFFFF >> (32 - data_size)), data_size);
    if(cpu.eflags.CF == 0)
        cpu.eflags.CF = result < src;
    else
        cpu.eflags.CF = result <= src;
}

void set_CF_sub(uint32_t result, uint32_t src, size_t data_size)
{
    result = sign_ext(result & (0xFFFFFFFF >> (32 - data_size)), data_size);
    src = sign_ext(src & (0xFFFFFFFF >> (32 - data_size)), data_size);
    cpu.eflags.CF = result < src;
}

void set_ZF(uint32_t result, size_t data_size)
{
    result = result & (0xFFFFFFFF >> (32 - data_size));
    cpu.eflags.ZF = (result == 0);
}

//SF and OF contain information rlevant to signed integers
void set_SF(uint32_t result, size_t data_size)
{
    result = sign_ext(result & (0xFFFFFFFF >> (32 - data_size)), data_size);
    cpu.eflags.SF = sign(result);
}

void set_PF(uint32_t result)
{
    result = result & 0x000000FF;
    int count_one = 0;
    while(result != 0)
    {
        result = result & (result - 1);
        count_one++;
    }
    if(count_one % 2 == 0)
        cpu.eflags.PF = 1;
    else
        cpu.eflags.PF = 0;
}

void set_OF_add(uint32_t result, uint32_t src, uint32_t dest, size_t data_size)
{
    switch(data_size)
    {
        case 8:
            result = sign_ext(result & 0xFF, 8);
            src = sign_ext(src & 0xFF, 8);
            dest = sign_ext(dest & 0xFF, 8);
            break;
        case 16:
            result = sign_ext(result & 0xFFFF, 16);
            src = sign_ext(src & 0xFFFF, 16);
            dest = sign_ext(dest & 0xFFFF, 16);
            break;
        default:
            break; //do nothing
    }
    if(sign(src) == sign(dest))
    {
        if(sign(src) != sign(result))
            cpu.eflags.OF = 1;
        else
            cpu.eflags.OF = 0;
    }
    else
    {
        cpu.eflags.OF = 0;
    }
}

void set_OF_adc(uint32_t result, uint32_t src, uint32_t dest, size_t data_size)
{
    switch(data_size)
    {
        case 8:
            result = sign_ext(result & 0xFF, 8);
            src = sign_ext(src & 0xFF, 8);
            dest = sign_ext(dest & 0xFF, 8);
            break;
        case 16:
            result = sign_ext(result & 0xFFFF, 16);
            src = sign_ext(src & 0xFFFF, 16);
            dest = sign_ext(dest & 0xFFFF, 16);
            break;
        default:
            break; //do nothing
    }
    if(sign(src) == sign(dest))
    {
        if(sign(src) != sign(result))
            cpu.eflags.OF = 1;
        else
            cpu.eflags.OF = 0;
    }
    else
    {
        cpu.eflags.OF = 0;
    }
}

void set_OF_sub(uint32_t result, uint32_t src, uint32_t dest, size_t data_size)
{
    switch(data_size)
    {
        case 8:
            result = sign_ext(result & 0xFF, 8);
            src = sign_ext(src & 0xFF, 8);
            dest = sign_ext(dest & 0xFF, 8);
            break;
        case 16:
            result = sign_ext(result & 0xFFFF, 16);
            src = sign_ext(src & 0xFFFF, 16);
            dest = sign_ext(dest & 0xFFFF, 16);
            break;
        default:
            break; //do nothing
    }
    if(sign(src) == sign(dest))
    {
        if(sign(src) != sign(result))
            cpu.eflags.OF = 1;
        else
            cpu.eflags.OF = 0;
    }
    else
    {
        cpu.eflags.OF = 0;
    }
}

void set_OF_sbb(uint32_t result, uint32_t src, uint32_t dest, size_t data_size)
{
    switch(data_size)
    {
        case 8:
            result = sign_ext(result & 0xFF, 8);
            src = sign_ext(src & 0xFF, 8);
            dest = sign_ext(dest & 0xFF, 8);
            break;
        case 16:
            result = sign_ext(result & 0xFFFF, 16);
            src = sign_ext(src & 0xFFFF, 16);
            dest = sign_ext(dest & 0xFFFF, 16);
            break;
        default:
            break; //do nothing
    }
    if(sign(src) == sign(dest))
    {
        if(sign(src) != sign(result))
            cpu.eflags.OF = 1;
        else
            cpu.eflags.OF = 0;
    }
    else
    {
        cpu.eflags.OF = 0;
    }
}
