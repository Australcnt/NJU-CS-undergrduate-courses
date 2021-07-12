#include <stdlib.h>
#include "memory/mmu/cache.h"
#include "memory/memory.h"

extern uint8_t hw_mem[];
extern uint32_t hw_mem_read(paddr_t paddr, size_t len);
extern void hw_mem_write(paddr_t paddr, size_t len, uint32_t data);

#ifdef CACHE_ENABLED
CacheLine cache[1024];

// init the cache
void init_cache()
{
	// implement me in PA 3-1
	for(int i = 0; i < 1024; i++)
	{
	    cache[i].valid = false;
	}
}

// write data to cache
void cache_write(paddr_t paddr, size_t len, uint32_t data)
{
	// implement me in PA 3-1
	uint32_t addr = paddr & 0x3f; //块内地址为 0 ~ 5 位
	uint32_t group = (paddr >> 6) & 0x7f; //cache组号为 6 ~ 12 位
	uint32_t sign = (paddr >> 13) & 0x7ffff; //标记为 13 ~ 31 位
	hw_mem_write(paddr, len, data); //采用全写法，同时写入主存
	for(int i = 0; i < 8; i++)
	{
	    if(cache[group * 8 + i].sign == sign && cache[group * 8 + i].valid == true) //命中
	    {
	        for(int j = 0; j < len; j++) //逐位写入（cache中小端存储，写入cache需反向）
	        {
	            if(addr + j < 64) //行内写入
	            {
	                cache[group * 8 + i].data[addr + j] = (data & 0xff);
	                data = data >> 8;
	            }
	            else //跨行写入
	            {
	                cache_write(paddr + j, len - j, data);
                    break;
	            }
	        }
	        break;
	    }
	}
}

// read data from cache
uint32_t cache_read(paddr_t paddr, size_t len)
{
	// implement me in PA 3-1
	uint32_t addr = paddr & 0x3f; //块内地址为 0 ~ 5 位
	uint32_t group = (paddr >> 6) & 0x7f; //cache组号为 6 ~ 12 位
	uint32_t sign = (paddr >> 13) & 0x7ffff; //标记为 13 ~ 31 位
	uint32_t res = 0;
	int i = 0;
	for(; i < 8; i++)
	{
	    if(cache[group * 8 + i].sign == sign && cache[group * 8 + i].valid == true) //命中
	    {
	        for(int j = 0; j < len; j++) //逐位读取（cache中小端存储，读入res需反向）
	        {
	            if(addr + j < 64) //行内读取
	            {
	                res |= ((uint32_t)cache[group * 8 + i].data[addr + j]) << (8 * j);
	            }
	            else //跨行读取
	            {
	                res |= (cache_read(paddr + j, len - j) << (8 * j));
                    break;
	            }
	        }
	        break;
	    }
	}
	if(i == 8) //未命中（缺失），则先从主存中写入cache，再读出
	{
	    res = hw_mem_read(paddr, len);
	    paddr = paddr & 0xffffffc0; //从addr = 0处开始，将整块写入cache
	    int k = 0;  
	    for(; k < 8; k++)
	    {
	        if(cache[group * 8 + k].valid == false)
	        {
	            cache[group * 8 + k].valid = true;
	            cache[group * 8 + k].sign = sign;
	            memcpy(cache[group * 8 + k].data, hw_mem + paddr, 64);
	            break;
	        }
	    }
	    if(k == 8) //组满，则随机替换
	    {
	        k = rand() % 8; //随机选取组内的一行进行替换
	        cache[group * 8 + k].valid = true;
	        cache[group * 8 + k].sign = sign;
	        memcpy(cache[group * 8 + k].data, hw_mem + paddr, 64);
	    }
	}
	return res;
}
#endif
