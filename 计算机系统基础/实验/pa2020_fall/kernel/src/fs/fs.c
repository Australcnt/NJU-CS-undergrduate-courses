#include "common.h"
#include "string.h"

typedef struct
{
	char *name;
	uint32_t size;
	uint32_t disk_offset;
} file_info;

typedef struct
{
	bool used;
	uint32_t index;
	uint32_t offset;
} Fstate;

enum
{
	SEEK_SET,
	SEEK_CUR,
	SEEK_END
};

static const file_info file_table[] = {
	{"1.rpg", 188864, 1048576}, {"2.rpg", 188864, 1237440}, {"3.rpg", 188864, 1426304}, {"4.rpg", 188864, 1615168}, {"5.rpg", 188864, 1804032}, {"abc.mkf", 1022564, 1992896}, {"ball.mkf", 134704, 3015460}, {"data.mkf", 66418, 3150164}, {"desc.dat", 16027, 3216582}, {"fbp.mkf", 1128064, 3232609}, {"fire.mkf", 834728, 4360673}, {"f.mkf", 186966, 5195401}, {"gop.mkf", 11530322, 5382367}, {"map.mkf", 1496578, 16912689}, {"mgo.mkf", 1577442, 18409267}, {"m.msg", 188232, 19986709}, {"mus.mkf", 331284, 20174941}, {"pat.mkf", 8488, 20506225}, {"rgm.mkf", 453202, 20514713}, {"rng.mkf", 4546074, 20967915}, {"sss.mkf", 557004, 25513989}, {"voc.mkf", 1997044, 26070993}, {"wor16.asc", 5374, 28068037}, {"wor16.fon", 82306, 28073411}, {"word.dat", 5650, 28155717}, {"credits_bgm.wav", 6631340, 1048576},
};

#define NR_FILES (sizeof(file_table) / sizeof(file_table[0]))

Fstate files[NR_FILES + 3];

void ide_read(uint8_t *, uint32_t, uint32_t);
void ide_write(uint8_t *, uint32_t, uint32_t);

/* Please implement a simple file system here */

int fs_open(const char *pathname, int flags)
{
	//panic("Please implement fs_open at fs.c");
    for (int i = 3; i < NR_FILES + 3; i++)
    {
        if(!strcmp(file_table[i - 3].name, pathname))
        {
            files[i].used = 1;
            files[i].index = i - 3;
            files[i].offset = 0;
            return i;
        }
    }
    assert(0);
    return -1;
}

size_t fs_read(int fd, void *buf, size_t len)
{
	assert(fd > 2);
	//panic("Please implement fs_read at fs.c");
    assert(files[fd].used == 1);
	assert(files[fd].offset <= file_table[files[fd].index].size);
	size_t length;
	if(files[fd].offset + len - 1 >= file_table[files[fd].index].size)
	    length = file_table[files[fd].index].size - files[fd].offset;
    else
        length = len;
    files[fd].offset = files[fd].offset + length;
	ide_read(buf, file_table[files[fd].index].disk_offset + files[fd].offset, length);
	memset(buf + length, 0, len - length);
	assert(files[fd].offset <= file_table[files[fd].index].size);
	return length;
}

size_t fs_write(int fd, void *buf, size_t len)
{
	assert(fd <= 2);
#ifdef HAS_DEVICE_SERIAL
	int i;
	extern void serial_printc(char);
	for (i = 0; i < len; i++)
	{
		serial_printc(((char *)buf)[i]);
	}
#else
	asm volatile(".byte 0x82"
				 : "=a"(len)
				 : "a"(4), "b"(fd), "c"(buf), "d"(len));
#endif

	return len;
}

off_t fs_lseek(int fd, off_t offset, int whence)
{
	//panic("Please implement fs_lseek at fs.c");
    assert(files[fd].used == 1);
	assert(files[fd].offset <= file_table[files[fd].index].size);
	if(whence == SEEK_SET)
        files[fd].offset = offset;
    else if(whence == SEEK_CUR)
        files[fd].offset = files[fd].offset + offset;
    else if(whence == SEEK_END)
        files[fd].offset = file_table[files[fd].index].size + offset;
    else
        assert(0);
	assert(files[fd].offset <= file_table[files[fd].index].size);
	return files[fd].offset;
}

int fs_close(int fd)
{
	//panic("Please implement fs_close at fs.c");
    if (files[fd].used == 1 && fd >= 0 && fd < NR_FILES + 3)
    {
	    files[fd].used = 0;
	    return 0;
	}
    return -1;
}
