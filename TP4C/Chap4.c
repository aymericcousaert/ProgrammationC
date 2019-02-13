#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Q1
/*
int main(int argc, char* argv[])
{
	char* dest[argc-1];
	for (int i = 1; i < argc; i++)
	{	
		dest[i-1] = malloc(strlen(argv[i]));
		memcpy(dest[i-1], argv[i], strlen(argv[i]));
	}
	for (int i = 0; i < argc-1; i++)
	{	
		printf("%s\n", dest[i]); // reste affiché un caractère étrange à la fin
	}
	return 0;
}
*/
 
// Q2
/*
int main(int argc, char* argv[])
{
	char* ptr = malloc(0);
	char nouveaumot[50];
	int taillePointeur = 0;
	do
	{
		scanf("%s",nouveaumot);
		if (strcmp(nouveaumot,"STOP") == 0)
			break;
		ptr = realloc(ptr, taillePointeur + strlen(nouveaumot) + 1);
		memcpy(ptr + taillePointeur, nouveaumot, strlen(nouveaumot) + 1);
		taillePointeur += strlen(nouveaumot) + 1;
	} while (strcmp(nouveaumot,"STOP") != 0);
	
	for (int i = 0; i < taillePointeur; i++)
		if (ptr[i] != '\0')
			printf("%c", ptr[i]);
		else 
			printf("\n");
	return 0;
}
*/

// Q3 OK

// Q4
/*
int main(int argc, char* argv[])
{
	char* ptr = malloc(0);
	char nouveaumot[50];
	int taillePointeur = 0;
	do
	{
		scanf("%s",nouveaumot);
		if (strcmp(nouveaumot,"STOP") == 0)
			break;
		if (strcmp(nouveaumot,"!") == 0)
			{
                ptr = realloc(ptr, taillePointeur + strlen(nouveaumot) + 1);
                memcpy(ptr + taillePointeur, nouveaumot, strlen(nouveaumot) + 1);
                taillePointeur += 2;
                memset(ptr,'!',taillePointeur);
			}
		ptr = realloc(ptr, taillePointeur + strlen(nouveaumot) + 1);
		memcpy(ptr + taillePointeur, nouveaumot, strlen(nouveaumot) + 1);
		taillePointeur += strlen(nouveaumot) + 1;
	} while (strcmp(nouveaumot,"STOP") != 0);
	
	for (int i = 0; i < taillePointeur; i++)
    {
        if (ptr[i] == '!')
        {
            if (ptr[i+1] == '\0')
                ;
        }
		else if (ptr[i] != '\0')
        {
            printf("%c", ptr[i]);
        }
		else 
			printf("\n");
    }
	return 0;
}
*/

typedef struct word_s
{
	char* mot;
	int taille;
} value_type_t;

struct node_s
{
	value_type_t value;
	struct node_s* motSuivant;
};

struct node_s* insert_node_end(struct node_s* list_head, value_type_t* value) {
	struct node_s* tmp = list_head;
	while (tmp != NULL)
	{
		tmp = tmp->motSuivant;
	}
	tmp->motSuivant = malloc(sizeof(value));
	tmp->motSuivant->value = *value;
	return list_head;
}

int getLength(struct node_s* list_head)
{
    struct node_s* tmp = list_head;
    int lentgh = 0;
    while (tmp != NULL)
    {
        tmp = tmp->motSuivant;
        lentgh++;
    }
    return lentgh;
}


int main(int argc, char* argv[])
{
	FILE * fichier = fopen("discours.txt","r");
	char mot[50];
    fgets(mot,50,fichier);
	struct node_s* list_head = NULL;
	while(fgets(mot,50,fichier) != NULL)
    {
        value_type_t* value = NULL;
		value->mot = mot;
		value->taille = strlen(mot);
		insert_node_end(list_head, value);
	}
	return 0;
}




