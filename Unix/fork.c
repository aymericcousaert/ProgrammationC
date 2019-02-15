#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int main(void)
{
	fork();
	if ( fork() )
	{
		fork();
	}
	printf("A\n");
	return 0;
}