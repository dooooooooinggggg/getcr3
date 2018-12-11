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
	uint64_t cr0, cr2, cr3, cr4;
	int fd;
	int rc0, rc2, rc3, rc4;
	if ((fd = open(MEM_DEVICE, O_RDONLY)) < 0)
	{
		fprintf(stderr, "cannot open %s\n", MEM_DEVICE);
		return 1;
	}
	while (1)
	{
		rc0 = read(fd, &cr0, 8);
		rc2 = read(fd, &cr2, 8);
		rc3 = read(fd, &cr3, 8);
		rc4 = read(fd, &cr4, 8);

		printf("CR0=0x%" PRIx64 ", CR2=0x%" PRIx64 ", CR3=0x%" PRIx64 ", CR4=0x%" PRIx64 "\n", cr0, cr2, cr3, cr4);
		// printf("return code(length)=%d  CR3=0x%" PRIx64 "\n", rc3, cr3);
		sleep(1);
	}

	close(fd);
}
