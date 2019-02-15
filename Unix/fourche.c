#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char** argv)
{
    pid_t pidParent = getpid();
    printf("%d : hello word\n", pidParent);
    printf("%d : je suis le parent\n", pidParent);
    pid_t pidEnfant = fork();

    if(0 != pidEnfant)
    {
        printf("%d : je suis l'enfant\n", pidEnfant);
    }

    return 0;
}
