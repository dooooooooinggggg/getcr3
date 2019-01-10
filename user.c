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

#define CR_NUMBER 5

int main(int argc, char **argv)
{
	// Only 64bit
	uint64_t cr[CR_NUMBER];
	int fd, rc;
	if ((fd = open(MEM_DEVICE, O_RDONLY)) < 0)
	{
		fprintf(stderr, "cannot open %s\n", MEM_DEVICE);
		return 1;
	}

	int a = 456;

	while (1)
	{
		printf("a:%d at 0x%p\n", a, &a);
		rc = read(fd, cr, 40);
		for (int i = 0; i < CR_NUMBER; i++)
		{
			// cr1 cannot see
			if (i == 1)
				continue;
			printf("CR%d: 0x%" PRIx64 "\n", i, cr[i]);
		}
		sleep(1);
	}

	close(fd);
}
