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
	uint64_t cr3;
	int fd, rc, i;
	if ((fd = open(MEM_DEVICE, O_RDONLY)) < 0)
	{
		fprintf(stderr, "cannot open %s\n", MEM_DEVICE);
		return 1;
	}
	while (1)
	{
		rc = read(fd, &cr3, 8); // cr3という変数に，8Byte読み込む
		printf("return code(length)=%d  CR3=0x%" PRIx64 "\n", rc, cr3);
		sleep(1);
	}

	close(fd);
}
