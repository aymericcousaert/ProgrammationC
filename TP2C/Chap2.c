#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h> // Pour malloc

/*
 * Explications
 * Non initialisée : taille très réduite (stockée dans BSS)
 * char s3[10000000];
 * Initialisée : taille très importante (stockée dans le data Segment)
 * char s4[10000000]={1,2,3,4,5};
 */

// Q1
// La fonction main se trouve dans la section Text Segment (Binaire)
void q1()
{
    extern int main();
    printf("%d\n", &main);
}

// Q2
int intNotInitialized;  //  Non initialisée : stockée en mémoire dans : bss segment
int intInitialized = 0; // Initialisée : stockée en mémoire dans : data segment

void q2()
{
    printf("Question 2\n");
    intNotInitialized;
    intInitialized = 5;
    printf("Valeur : %d, Adresse: %p\n",intNotInitialized, &intNotInitialized);
    printf("Valeur : %d, Adresse: %p\n",intInitialized, &intInitialized);
}

// Q3
// Mêmes adresses :
void q3()
{
    printf("Question 3\n");
    int* pt;
    pt = &intNotInitialized;
    int* pt1;
    pt1 = &intInitialized;
    printf("Valeur : %d, Adresse: %p\n",*pt, pt);
    printf("Valeur : %d, Adresse: %p\n", *pt1, pt1);
}

void q4()
{
    printf("Question 4\n");
    int* pt;
    pt = &intNotInitialized;
    int* pt1;
    pt1 = &intInitialized;
    *pt = 54;
    *pt1 =5;
    printf("Grace aux pointeurs\n");
    printf("Valeur : %d, Adresse: %p\n",*pt, pt);
    printf("Valeur : %d, Adresse: %p\n", *pt1, pt1);
    printf("Grace aux variables\n");
    printf("Valeur : %d, Adresse: %p\n",intNotInitialized, &intNotInitialized);
    printf("Valeur : %d, Adresse: %p\n",intInitialized, &intInitialized);
}

// Q5 : mémoire locale : la pile
void q5()
{
    printf("Question 5\n");
    int var1 = 1;
    printf("Adresse de var1 : \n",&var1);
}

// Q6 : sizeof() renvoit le nombre d'octets qu'occupe le tableau
void q6()
{
    int tableau[5];
    printf("%d\n", sizeof(tableau)); // 20 si nb d'octets occupés par le tableau, 5 si nb d'éléments du tableau
    printf("%d\n", sizeof(&tableau)); // nb d'octets occupés par l'adresse du tableau
}
// Q7

#define MAT_MAX 5 // fonctionne
// unsigned int MAT_MAX = 50; ne fonctionne pas
// const unsigned int MAT_MAX = 50; ne fonctionne pas

typedef
struct
{
    int tab[MAT_MAX][MAT_MAX];
}
Matrice;

void q7()
{
    Matrice mat1;
}

void afficheMatrice(Matrice mat)
{
    printf("Taille de la matrice : %u octets (%d * %d * 4 (octets car INT)) \n", sizeof(mat), MAT_MAX, MAT_MAX);

    for (int i = 0; i < MAT_MAX; i++)
    {
        for (int j = 0; j < MAT_MAX; j++)
            printf("%3d ",mat.tab[i][j]);
        printf("\n");
    }
}


void q8()
{
    Matrice mat1;
    
    for (int i = 0; i < MAT_MAX; i++)
        for (int j = 0; j < MAT_MAX; j++)
            mat1.tab[i][j] = i;

    afficheMatrice(mat1);
}

void q9q10q11()
{
    char* my_string = "<-_->";
    for (int i = 0; i < strlen(my_string) ; i ++)
        printf("%c", my_string[i]);

    printf("\n");

    int i = 0;
    while(my_string[i] != '\0'){
        printf("%c", my_string[i]);
        i++;
    }

    printf("\n");

    while(*my_string != '\0'){
        printf("%c", *my_string);
        my_string++;
    }
}

void q12()
{
    char saisie[40];
    printf("Tapez le char que vous souhaitez convertir ! \n");
    scanf("%s", &saisie);

    char * result;
    printf("Caractère converti en entier : %lu\n", strtoimax(saisie, &result, 10));
    printf("Fin\n");
}

// chaine1 < chaine2 : renvoie 1
// chaine1 > chaine2 : renvoie -1
// chaine1 = chaine2 : renvoie 0
int tp_strcmp(const char* chaine1, const char* chaine2)
{
    int c1 = 0;
    while(chaine1[c1] != '\0' && chaine2[c1] != '\0' && chaine1[c1] == chaine2[c1])
        c1++;
    if(chaine1[c1] == '\0' && chaine2[c1] == '\0') return 0;
    else if(chaine1[c1] == '\0') return -1;
    else return 1;
}

void q13()
{
    char chaine1[50];
    char chaine2[50];

    printf("Chaine 1 : ");
    scanf("%s", &chaine1);
    printf("\n");
    printf("Chaine 2 : ");
    scanf("%s", &chaine2);
    printf("\n");
    int result = tp_strcmp(chaine1, chaine2);
    printf("Comparaison entre chaine1 et chaine2 : %d \r\n", result);
}

// Les 3 notions sont équivalentes
void q14()
{
    int tab[5][7];
    int* tab_addr = &tab;
    int* tab_point = tab;
    int* tab_point_elt = &tab[0];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 7; j++)
            tab[i][j] = i;

    printf("tab_addr %p\n", tab_addr);
    printf("tab_point %p\n", tab_point);
    printf("tab_point_elt %p\n", tab_point_elt);

    int* test = (tab_point_elt + 12); // Permet d'acceder à tab_point_elt[1][5]

    *test = 99;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++)
            printf(" %2d ", tab[i][j]);
        printf("\n");
    }
    printf("Test: %d \n", test);
}

// Q16
enum mois
{
    Janvier, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre
};

typedef
struct
{
    int date;
    enum mois Mois;
    int Annee;
}
dateDeNaissance;

// Q17
typedef
struct
{
    int identifiant;
    dateDeNaissance date;
    char boisson[20];
}
etudiant;

// Q18
etudiant etudiants[3];

// Q19 : pas de question

void q20()
{
    int A[] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int *P;
    P = A; // équivalent à P = &A[0];
    int i1 = *P+2; // 14
    int i2 = *(P+2); // 34
    int* a1 = &A[4]-3; // -> 23
    int* a2= A+3; // -> 45
    int i3 = &A[7]-P; // 7
    int* a3 = P+(*P-10); // -> 34
    int i4 = *(P+*(P+8)-A[7]); // 23
    printf("%d\n",i1);
    printf("%d\n",i2);
    printf("%d\n",*a1);
    printf("%d\n",*a2);
    printf("%d\n",i3);
    printf("%d\n",*a3);
    printf("%d\n",i4);
}

// Q22
// Deux visions à avoir si l'on attribue une valeur à une variable ou pointeur
// * est prioritaire sur + / -
// + / - est prioritaire sur &

// Q26 : sont mis en commentaire les parties de code incorrect
// foo() = 2;

// int var = 0; 4 = var;

// int var = 0; (var + 1) = 4;

int arr[] = {1, 2};
int* p = &arr[0];
// *(p + 1) = 10;

int var = 10;
// int* addr = &(var + 1);

enum color{red, green, blue};
enum color c;
// c = green; impossible de redéfinir en dehors du main : pourquoi ?
// blue = green;

// &var = 40;

// Q27
int fois_deux(int entier)
{
    return 2*entier;
}

// Q28
int* appliquer_tableau(int pfunc(int), int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        tab[i] = pfunc(tab[i]);
    }
    return tab;
}

void q29()
{
    int *tab = malloc(3);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab = appliquer_tableau(fois_deux, tab, 3);
    for (int i = 0; i < 3; i++) printf("%d ",tab[i]);
    printf("\n");
    free(tab);
}

int superieur(int a, int b)
{
    if (a > b) return 1;
    else if (a == b) return 0;
    else return -1;
}

int inferieur(int a, int b)
{
    if (a > b) return -1;
    else if (a == b) return 0;
    else return 1;
}

// Il est demandé une fonction tri

// Q31
enum couleur {coeur, carreau, pique, trefle};

// Q32
enum valeur {sept, huit, neuf, dix, valet, dame, roi, as};

// Q33
struct carte
{
    enum couleur uneCouleur;
    enum valeur uneValeur;
};

// Q34
void init_jeu(struct carte** unJeu)
{
    for (int i = 0; i < 8; i++)
    {
        unJeu[i]->uneCouleur = coeur;
    }
    for (int i = 8; i < 16; i++)
    {
        unJeu[i]->uneCouleur = carreau;
    }
    for (int i = 16; i < 24; i++)
    {
        unJeu[i]->uneCouleur = pique;
    }
    for (int i = 24; i < 32; i++)
    {
        unJeu[i]->uneCouleur = trefle;
    }
    for (int i = 0; i < 4; i++)
    {
        unJeu[8*i]->uneValeur = sept;
        unJeu[8*i + 1]->uneValeur = huit;
        unJeu[8*i + 2]->uneValeur = neuf;
        unJeu[8*i + 3]->uneValeur = dix;
        unJeu[8*i + 4]->uneValeur = valet;
        unJeu[8*i + 5]->uneValeur = dame;
        unJeu[8*i + 6]->uneValeur = roi;
        unJeu[8*i + 7]->uneValeur = as;
    }
}

// Q35
void affiche_carte(struct carte uneCarte)
{
    char* chaines_couleur[4] = {"coeur", "carreau", "pique", "trefle"};
    char* chaines_valeur[8]={"sept", "huit", "neuf", "dix", "valet", "dame", "roi", "as"};
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            if (uneCarte.uneCouleur == i && uneCarte.uneValeur == j)
                printf("La carte est un %s de %s\n", chaines_valeur[j], chaines_couleur[i]);
}

// Q36
#include <stdlib.h> // Pour le random
struct carte tabJoueur1[10];
struct carte tabJoueur2[10];
void distribue_main(struct carte** unJeu)
{
    int ind1 = 0;
    int ind2 = 0;
    while (ind1 != 9)
    {
        srandom(time(NULL)); /* initialise la graine d’aléa */
        int nb_entre_0_et_32  = random() % 32;
        if (unJeu[nb_entre_0_et_32]->uneValeur != 10)
        {
            tabJoueur1[ind1] = *unJeu[nb_entre_0_et_32];
            unJeu[nb_entre_0_et_32]->uneValeur = 10;
            ind1++;
        }
    }
    while (ind2 != 9)
    {
        srandom(time(NULL)); /* initialise la graine d’aléa */
        int nb_entre_0_et_32  = random() % 32;
        if (unJeu[nb_entre_0_et_32]->uneValeur != 10)
        {
            tabJoueur2[ind2] = *unJeu[nb_entre_0_et_32];
            unJeu[nb_entre_0_et_32]->uneValeur = 10;
            ind1++;
        }
    }
}

// Q37 : il faut implementer le jeu, l'ordi joue au hasard (dans l'ordre où les cartes ont été distribuées par exemple), l'utilisateur choisit
// Ne fonctionne pas pour le moment
void jouons()
{
    printf("L'ordinateur joue\n");
    //distribue_main(&jeu_complet);
    printf("L'ordinateur joue\n");
    
    for (int i = 0; i < 10; i++)
    {
        printf("L'ordinateur joue\n");
    }
}

void q38(int hauteurCone, int hauteurTronc, int largeurTronc)
{
    int boule = 1;
    int coord1[3]; // On limite à 3 boules
    int coord2[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Faut-il ajouter des boules ? (0 - Non, 1 - Oui)\n");
        scanf("%d", &boule);
        if (boule == 0)
            break;
        scanf("%d %d", &coord2[i], &coord1[i]);
        
    }
    // On émet l'hypothèse simplificatrice que l'on ne met pas de boules en bas de l'arbre
    for (int j = 0; j < hauteurCone - 1; j++)
    {
        for (int i = 0; i < hauteurCone - (j + 1); i++)
            printf(" ");
        for (int i = 0; i < 1 + 2*j; i++)
        {
            if (i == (coord1[0] - 1) & j == hauteurCone - (coord2[0]))
                printf("0");
            else if (i == (coord1[1] - 1) & j == hauteurCone - (coord2[1]))
                printf("0");
            else if (i == (coord1[2] - 1) & j == hauteurCone - (coord2[2]))
                printf("0");
            else
                printf("*");
        }
        
        for (int i = 0; i < hauteurCone - (j+1); i++)
            printf(" ");
        printf("\n");
    }
    for (int i = 0; i < 1 + 2*(hauteurCone - 1); i++)
        printf("*");
    printf("\n");
    for (int j = 0; j < hauteurTronc; j++)
    {
        for (int i = 0; i < (1 + 2*(hauteurCone - 1) - largeurTronc)/2 ; i++)
            printf(" ");
        for (int i = 0; i < largeurTronc; i++)
            printf("|");
        for (int i = 0; i < (hauteurCone - 1) ; i++)
            printf(" ");
        printf("\n");
    }
}

// Q40 : il faut maintenant créer une fonction qui crée un arbre de taille aléatoire et qui place les boules de manière aléatoire
void generate_pine()
{
    srandom(time(NULL));
    int hauteurCone = random() % 13 + 3; // Inutile d'avoir un sapin trop grand tout de même
    int hauteurTronc = random() % 3 + 1;
    int largeurTronc = 2*random()% 3 + 1;
    int coord1[3] = {random() % hauteurCone, random() % hauteurCone, random() % hauteurCone}; // On limite à 3 boules
    int coord2[3] = {random() % hauteurCone, random() % hauteurCone, random() % hauteurCone};
  
    // On émet l'hypothèse simplificatrice que l'on ne met pas de boules en bas de l'arbre
    for (int j = 0; j < hauteurCone - 1; j++)
    {
        for (int i = 0; i < hauteurCone - (j + 1); i++)
            printf(" ");
        for (int i = 0; i < 1 + 2*j; i++)
        {
            if (i == (coord1[0] - 1) & j == hauteurCone - (coord2[0]))
                printf("0");
            else if (i == (coord1[1] - 1) & j == hauteurCone - (coord2[1]))
                printf("0");
            else if (i == (coord1[2] - 1) & j == hauteurCone - (coord2[2]))
                printf("0");
            else
                printf("*");
        }
        
        for (int i = 0; i < hauteurCone - (j+1); i++)
            printf(" ");
        printf("\n");
    }
    for (int i = 0; i < 1 + 2*(hauteurCone - 1); i++)
        printf("*");
    printf("\n");
    for (int j = 0; j < hauteurTronc; j++)
    {
        for (int i = 0; i < (1 + 2*(hauteurCone - 1) - largeurTronc)/2 ; i++)
            printf(" ");
        for (int i = 0; i < largeurTronc; i++)
            printf("|");
        for (int i = 0; i < (hauteurCone - 1) ; i++)
            printf(" ");
        printf("\n");
    }
}

// Q41
struct sapinDeNoel
{
    int hauteurCone;
    int hauteurTronc;
    int largeurTronc;
    int coord1[3];
    int coord2[3];
};

// Q42
struct sapinDeNoel populate_forest(struct sapinDeNoel* unSapin)
{
    srand(time(NULL));
    unSapin->hauteurCone = random() % 13 + 3; // Inutile d'avoir un sapin trop grand tout de même
    unSapin->hauteurTronc = random() % 3 + 1;
    unSapin->largeurTronc = 2*random()% 3 + 1;
    for (int i = 0; i < 3; i++)
    {
        unSapin->coord1[i] = random() % unSapin->hauteurCone;
        unSapin->coord2[i] = random() % unSapin->hauteurCone;
    }
    return *unSapin;
}

// Q43
void print_pine(struct sapinDeNoel* unSapin)
{
    for (int j = 0; j < unSapin->hauteurCone - 1; j++)
    {
        for (int i = 0; i < unSapin->hauteurCone - (j + 1); i++)
            printf(" ");
        for (int i = 0; i < 1 + 2*j; i++)
        {
            if (i == (unSapin->coord1[0] - 1) & j == unSapin->hauteurCone - (unSapin->coord2[0]))
                printf("0");
            else if (i == (unSapin->coord1[1] - 1) & j == unSapin->hauteurCone - (unSapin->coord2[1]))
                printf("0");
            else if (i == (unSapin->coord1[2] - 1) & j == unSapin->hauteurCone - (unSapin->coord2[2]))
                printf("0");
            else
                printf("*");
        }
        
        for (int i = 0; i < unSapin->hauteurCone - (j+1); i++)
            printf(" ");
        printf("\n");
    }
    for (int i = 0; i < 1 + 2*(unSapin->hauteurCone - 1); i++)
        printf("*");
    printf("\n");
    for (int j = 0; j < unSapin->hauteurTronc; j++)
    {
        for (int i = 0; i < (1 + 2*(unSapin->hauteurCone - 1) - unSapin->largeurTronc)/2 ; i++)
            printf(" ");
        for (int i = 0; i < unSapin->largeurTronc; i++)
            printf("|");
        for (int i = 0; i < (unSapin->hauteurCone - 1) ; i++)
            printf(" ");
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    // Q44 : Ca marche !!!
    struct sapinDeNoel forest[8];
    for (int i = 0; i < 8; i++)
    {
        forest[i] = populate_forest(&forest[i]);
        print_pine(&forest[i]);
    }
    
    // Un test
    struct carte AsPique;
    AsPique.uneCouleur = pique;
    AsPique.uneValeur = as;
    affiche_carte(AsPique);
    
    // Q37
    // Ne fonctionne pas
    
    // Q23
    printf("Main appelé avec %d argument(s) \n", argc);
    for (int i = 0; i < argc; i++)
        printf("L'argument était : %s \n", argv[i]);
    // Q24 Le premier parametre est le nom de l'executable
    if (argc == 1+1)
    {
        int* result;
        int nbEtoiles = strtol(argv[1], &result, 10);
        // Q25
        for (int i = 0; i < nbEtoiles; i++)
            printf("*");
        printf("\n");
    }
    else
        printf("Spécifiez un paramètre \n");
    return 0;
}


