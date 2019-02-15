

# si on tape "make" sans préciser de cible, make va chercher à
# construire la *première* cible du Makefile.
default: all

all: rebours parexec fourche fork exec doublerebours

##########################################
# compilation des programmes

rebours: rebours.c
	gcc -Wall -Werror -o rebours   rebours.c 

fork: fork.c
	gcc -Wall -Werror -o fork   fork.c 

exec: exec.c
	gcc -Wall -Werror -o exec   exec.c 

fourche: fourche.c
	gcc -Wall -Werror -o fourche fourche.c

doublerebours: doublerebours.c
	gcc -Wall -Werror -o doublerebours   doublerebours.c 

parexec: parexec.c
	gcc -Wall -Werror -o parexec   parexec.c

##########################################
# nettoyage des fichiers générés

clean:
	rm -f *.o parexec rebours
