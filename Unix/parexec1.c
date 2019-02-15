#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    
	assert(argc > 1);
	char* prog = argv[1];
	char* nomProg = malloc(sizeof(prog) - 2);
	for (int i = 2; i < sizeof(prog); i++)
	{
	nomProg[i - 2] = prog[i];
	}
	for (int i = 2; i < argc; i++)
	{
		if(!fork()) // Si on est dans l'enfant
		{
		    execl(prog, nomProg, argv[i],NULL);
    		}
		
	}
	for (int i = 2; i < argc; i++){
		wait(NULL);
	}

    return 0;
}
