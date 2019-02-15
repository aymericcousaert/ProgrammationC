#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>


int main(int argc, char** argv)
{
    printf("Bonjour je suis '%s'\n",argv[0]);
    if(!fork()) // Si on est dans l'enfant
    {
        execl("./rebours", "rebours", "4",NULL);
    }
    execl("./rebours", "rebours", "2",NULL);

    return 0;
}
