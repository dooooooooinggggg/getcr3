#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <inttypes.h>
//#define DEBUG

#define MEM_DEVICE "/dev/getcr3"
#define BUF_SIZE (256)

int main(int argc, char **argv)
{
	char buf[8];
	uint64_t res[5];
	uint64_t cr0, cr2, cr3, cr4;
	int fd;
	int rc, rc0, rc2, rc3, rc4;
	if ((fd = open(MEM_DEVICE, O_RDONLY)) < 0)
	{
		fprintf(stderr, "cannot open %s\n", MEM_DEVICE);
		return 1;
	}
	while (1)
	{
		rc = read(fd, res, 40);
		for (int i = 0; i < 5; i++)
		{
			if (i = 1)
				continue;
			printf("CR%d: 0x%" PRIx64 "\n", i, res[i]);
		}
		sleep(1);
	}

	close(fd);
}
