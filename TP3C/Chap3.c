#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h> // pour avoir accès à UINT_MAX

// Q1 char *fgets(char *s, int size, FILE *stream);
// Permet de lire un fichier. S'arrete à :
// - size characters read : la taille spécifiée est atteinte
// - EOF : end of file, fin de fichier
// - newline : nouvelle ligne

void q2()
{
    FILE* fichier = fopen("makefile","r");
    char a = fgetc(fichier);
    while (a != EOF)
    {
      printf("%c",a);
      a = fgetc(fichier);
    }
    printf("\n");
    fclose(fichier);
}

void q3q4()
{
    int x = 0;
    char chaine[200];
    srand(time(NULL));
    FILE* fichier1 = fopen("colonne1.txt","r");
    FILE* fichier2 = fopen("colonne2.txt","r");
    FILE* fichier3 = fopen("colonne3.txt","r");
    FILE* fichier4 = fopen("colonne4.txt","r");
    FILE* tab[4] = {fichier1,fichier2,fichier3,fichier4};
    FILE* discours = fopen("discours.txt","w");
    for (int i = 0; i < 5; i++) // Le discours doit faire 5 phrases
    {
        for (int j = 0; j < 4; j++)
        {
            x = rand() % 8;
            int a = 0;
            while (fgets(chaine, 200, tab[j])) // Vaut 0 si on arrive à la fin du fichier
            {
                if (a == x) fputs(chaine, discours);
                a++;
            }
            rewind(tab[j]);
        }
    }
    fclose(tab[0]);
    fclose(tab[1]);
    fclose(tab[2]);
    fclose(tab[3]);
    fclose(discours);
}

void print_unsigned_int(unsigned int value)
{
    int compteur = 0;
    int tab[10];
    if (value == 0)
    putchar(48);
    while (value != 0)
    {
        tab[compteur++] = value % 10;
        value /= 10;
    }
    for (int i = (compteur - 1); i >= 0; i--)
        putchar(48+tab[i]);
}

void print_signed_int(signed int value)
{
    if (value < 0)
    {
        putchar(45);
        value = (-1) * value;
    }
    print_unsigned_int(value);
}

void print_float(float value) // Cela fonctionne pour les petits nombres positifs ou négatifs mais pas pour 10000000000000000
{
    // Affichage de la partie entière
    int acc = 0;
    long long signed int valeurEntiere = (long long signed int)value;
    int valDetruite = valeurEntiere;
    //printf("\n%lld\n",valeurEntiere);
    if (value < 0)
    {
        putchar(45);
        valeurEntiere = (-1) * valeurEntiere;
    }
    int tabPartieEntiere[37];
    if (valeurEntiere == 0)
        putchar(48);
    while (valDetruite != 0)
    {
        tabPartieEntiere[acc++] = valDetruite % 10;
        valDetruite = valDetruite / 10;
    }
    if (valeurEntiere < 0)
        putchar(45);
    for (int i = (acc - 1); i >= 0; i--)
        putchar(48+tabPartieEntiere[i]);
    
    // Affichage de la partie décimale
    int partieDecimale = 0;
    if (value > 0)
        partieDecimale = (int)1000000*(value - valeurEntiere);
    else
        partieDecimale = (int)1000000*((-1)*value - valeurEntiere);
    
    
    int val = partieDecimale;
    int tab[6] = {0, 0, 0, 0, 0, 0};
    int compteur = 0;
    while (val != 0)
    {
        tab[compteur++] = val % 10;
        val /= 10;
    }
    int nbZero = 0;
    for (int i = 0; i <6; i++)
        if (tab[i] == 0) nbZero++;
    if (nbZero != 6)
    {
        putchar(46);
        int marqueur = 1;
        if (tab[5] == 0) marqueur = 0;
        for (int i = 5; i >= 0; i--)
        {
            if (tab[i] == 0 && marqueur == 0)
            {
                tab[i] = -1;
            }
            else marqueur = 1;
            
        }
        for (int i = 0; i < 6; i++)
            if (tab[i] == -1)
                putchar(48);
        for (int i = 6; i < 6; i++)
        {
            if (tab[i] != -1)
            {
                putchar(48+tab[i]);
            }
        }
        print_unsigned_int(partieDecimale);
    }
}

void print_float_list(int count, ...)
{
    va_list ap;
    va_start(ap,count);
    for (int i = 0; i < count; i++)
    {
        print_float(va_arg(ap, double));
        putchar(' ');
    }
    putchar('\n');
    va_end(ap);
}

void mon_printf(char *string, ...)
{
    va_list ap;
    int i = 0;
    char a = string[i];
    va_start(ap,string);
    while (a != '\0')
    {
        if (a == '%')
        {
            i++;
            a = string[i];
            switch (a)
            {
                case 'd':
                {
                    print_signed_int(va_arg(ap,signed int));
                    break;
                }
                case 'u':
                {
                    print_unsigned_int(va_arg(ap,unsigned int));
                    break;
                }
                case 'f':
                {
                    print_float(va_arg(ap,double));
                    break;
                }
                case 'c':
                {
                    putchar(va_arg(ap,int));
                    break;
                }
                case 's':
                {
                    char* unString = va_arg(ap,char*);
                    char b = unString[0];
                    int ind = 1;
                    while (b != '\0')
                    {
                        putchar(b);
                        b = unString[ind++];
                    }
                    break;
                }
            }
            i++;
            a = string[i];

        }
        else
        {
            putchar(a);
            i++;
            a = string[i];
        }
    }
    va_end(ap);
}

int main()
{
    print_unsigned_int(UINT_MAX);
    putchar('\n');
    print_float(0.000123);
    putchar('\n');
    print_float_list(3,2.15,3.14,1.589);
    mon_printf("Je vais bien : %d, et ca marche %s\n",3,"yolo");
    return 0;
}
