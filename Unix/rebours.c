#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int main(int argc, char** argv)
{
    pid_t pid = getpid();

    assert(argc > 1) ;

    int secondes = atoi(argv[1]);

    assert(secondes > 0);

    printf("%d : début\n", pid);
    while (secondes > 0)
    {
        printf("%d : %d\n", pid, secondes);
        sleep(1);
        secondes--;
    }
    printf("%d : fin\n", pid);

    return 0;
}
