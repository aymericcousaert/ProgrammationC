#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int main(void)
{
	printf("A\n");
	execl("/bin/ls", "ls", "-l", ".", NULL);
	printf("A\n");
	return 0;
}