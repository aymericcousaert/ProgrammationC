#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Q1
// Test : le type char est-il signé ou non ?
int q1()
{
    char a;
    a = 127;
    a+=1;
    printf("%d\n", a<0);
    return 0;
}

// Q2
// Tailles (max/min) d'un entier signé et d'un entier non signé
void q2()
{
    int nbBitsInt = sizeof(int)*8;
    int nbBitsUnsignedInt = sizeof(unsigned int)*8;
    int a = -pow(2,nbBitsInt-1);
    int b = pow(2, nbBitsInt-1) -1;
    unsigned int c = pow(2, nbBitsUnsignedInt) -1;

    printf(" Taille d'un int : %d\r\n", nbBitsInt);
    printf(" Valeur min d'un int : %d\r\n", a);
    printf(" Valeur max d'un int : %d\r\n", b);

    printf(" Taille d'un unsigned int : %d\r\n", nbBitsUnsignedInt);
    printf(" Valeur min d'un unsigned int : 0\r\n");
    printf(" Valeur max d'un unsigned int : %u\r\n", c);
}

// Q3
void q3()
{
    int super = 0x17;
    int bof = 0b1010;
    int superman = 0b10110;
    int naze = 8;
    int sousleau = 0x2;

    printf("super : %d\r\nbof : %d\r\n naze : %d\r\nsuperman : %d\r\n sousleau : %d",super,bof,naze,superman,sousleau);

    /**
      * 1. Caractère Ascii : char
      * 2. Nombre d'atomes de la Terre (10 puissances 50) : unsigned long long int ne correspond pas
      * 3. Le numéro d'une adresse : short int
      * 4. Nb de cartons de vins dans un hangar : short int
      * 5. Nb de vues vidéo yt : unsigned long long
      */
}

// Q4
// Affiche le nombre de bits sur lesquels sont codés le types long et long long (64)
void q4()
{
    printf("%lu\r\n",sizeof(long int));
    printf("%lu\r\n",sizeof(long long int));
}

// Q5
// Overflow sur un unsigned char : pas en complément à 2 donc 255+1 = 0
void q5()
{
    unsigned char a = pow(2,sizeof(unsigned char)*8)-1;
    printf("%d\r\n", a);
    a+=1;
    printf("%d\r\n", a);
}

// Q6
// Ajouter 1 a la valeur max renvoit la valeur min

//Q7
void q7()
{
    uint32_t a, b = 4000000000, c = 5000000000, d = 0;
    a = (b + c) - d;
    printf("%d\n",a);
    // Le résultat étrange est expliqué dans un warning
}


// Q8
void q8()
{
    if (sizeof(int) < -1)
        printf("Bizarre, bizarre ... ??\n");
    else
        printf ("Tout semble normal\n");
    if ((signed int)sizeof(int) < -1)
        printf("Bizarre, bizarre ... ??\n");
    else
        printf ("Tout semble normal\n");
}

// Q9 & Q10

void q9()
{
   int pi = 3.14;
   float pi1 = 3.14;
   float pi2 = 3.1415926535897932384626433832; // 23 bits de mantisse, le 8e chiffre est faux
   double pi3 = 3.1415926535897932384626433832; // 52 bits de mantisse, + une partie hors module

   int rayon = 5;

   float perim1 = 2*pi*rayon;
   float perim2 = 2*pi1*rayon;
   float perim3 = 2*pi2*rayon;
   float perim4 = 2*pi3*rayon;

   printf("Pi = %d, Rayon = %d => Perimètre = %f \r\n",pi, rayon, perim1);
   printf("Pi = %0.2f, Rayon = %d => Perimètre = %f \r\n",pi1, rayon, perim2);
   printf("Pi = %0.28f, Rayon = %d => Perimètre = %f \r\n",pi2, rayon, perim3);
   printf("Pi = %0.28f, Rayon = %d => Perimètre = %f \r\n",pi3, rayon, perim4);
}

// Q11

void q11()
{
    printf("Taille en octet(s) d'un booléen : %d\r\n",sizeof(bool));
    bool vrai = true;

    printf("%s", vrai?"true" : "false");
    printf("\r\n");

    printf("Valeur entière codant le booléen : %d\r\n", vrai);
}

// Q12
// On peut considérer un char comme un nombre
void q12()
{
    char lettre = 'A';
    lettre++;

    // Affichera B
    printf("%c\r\n", lettre);
}

// Q13
// Renvoie 4294902761 (on a fait le tour)
// Le résultat de la soustraction n'est pas de type unint16_t
// Le résultat est une variable de type uint32_t
void q13()
{
    uint16_t a = 413;
    uint16_t b = 64948;
    fprintf(stdout, "%u\n", (a - b));
}

void questpers()
{
    printf("%d %d\n",sizeof(float),sizeof(double));
}

// Q15
// La mantisse est codée sur un nombre limité de bits (donc si on dépasse : on perd de l'information), pour un float, la plus grande mantisse est 8388607
void q15()
{
    long a = 80000002;
    printf("A EN FLOAT : %f \r\n", (float)a);
    float b = 2;
    long c = a / b;
    printf("res : %li\n", c);
}

// Q16 : Le long est transformé en float

// Q17 : 1.618 est transformé en int 1
void q17()
{
    int i = 1.618;
    printf("%d\n",i);
}

// Q18 OK

void q19()
{
    int i = 42;
    char j = 42;

    printf("i (int) : %d -> %c \r\n",i, (char)i);
    printf("j (char) : %c -> %d \r\n",i, (int)i);
}

void q20()
{
    int i = -42; // int est par défaut signed int
    unsigned int j = i;

    printf("%d -> %u\r\n", i, j);

    int e = 0x2a3b;
    char f = e;
    // Est un point virgule, le code ascii traduit 3b en ; donc sont conservés les éléments les plus à droite
    printf("%d -> en char : %c \r\n", e, f);
}

void q21()
{
    char A=3;
    int B=4;
    float C = (float)A/(float)B;
    printf("%c / %d = %f\r\n", A, B, C);
}

// Q26 et Q27
typedef
struct
{
    long chambres:52;
}
ensemble_t;


// Q22 : Gestion de chambres et de jacouzi
ensemble_t printRoomsState(ensemble_t allRooms)
{
    long mask = 1; // 000000000....00001 //
    for (int i = 0; i < 32; i++)
    {
        long isRoomOccuped = mask & allRooms.chambres;
        //printf("[MASK & Rooms] : %d\r\n", mask );
        printf("Chambre %2d : %s \r\n",i, isRoomOccuped == mask ? "Occupée" : "Libre");
        mask = mask << 1;
    }
    // Mask i = 1 00000..000010 //
    // Mask i = 2 00000..000100 //
                       // &
    // allRooms   0000011110000
    return allRooms;
}

// Q23
ensemble_t roomGoesOccupied(ensemble_t allRooms, unsigned int roomNum)
{
    long temp = 1;
    for (int i = 1; i < roomNum; i++)
    {
        temp = temp << 1;
    }
    ensemble_t chambres;
    chambres.chambres = allRooms.chambres | temp;
    return chambres;
}

// Q24
bool isOccupied(ensemble_t allRooms, unsigned int roomNum)
{
    long temp = 1;
    for (int i = 1; i < roomNum; i++)
    {
        temp = temp << 1;
    }
    return (allRooms.chambres & temp) == temp;
}

// Q25
ensemble_t roomGoesEmpty(ensemble_t allRooms, unsigned int roomNum)
{
    long temp = 1;
    for (int i = 1; i < roomNum; i++)
    {
        temp = temp << 1;
    }
    ensemble_t chambres;
    chambres.chambres = ~(temp) & allRooms.chambres;
    return chambres;
}

// Quelques tests
void q22()
{
    ensemble_t chambres;
    chambres.chambres = 15;// 1111 //
    unsigned int chambre3 = 3;
    chambres = roomGoesEmpty(chambres,chambre3);
    printRoomsState(chambres);
    chambres = roomGoesOccupied(chambres,chambre3);
    printRoomsState(chambres);
}

// Q29
void q29()
{
    //enum scrutin_e {MAJORITAIRE_UNI, MAJORITAIRE_PLURI, PROPORTIONNEL, MIXTE};
    enum scrutin_e {MAJORITAIRE=2, MAJORITAIRE_PLURI=8, PROPORTIONNEL=42, MIXTE=12};
    //enum scrutin_e {MAJORITAIRE=4, MAJORITAIRE_PLURI, PROPORTIONNEL, MIXTE};
    typedef enum scrutin_e scrutin_t;
    scrutin_t presidentiel = MAJORITAIRE;
    printf("%d\n", presidentiel);
}

// Q30
enum jour {Lundi, Mardi, Mercredi, Jeudi, Vendredi, Samedi, Dimanche};
typedef enum jour jourSemaine_t;

// Q31
void
appreciate(int note)
{
    switch (note) {
        case 12:
            printf("12 ! Passable ");
            break;
        case 18:
            printf("18 ! Super ! ");
        case 6:
            printf("6 ! Naze ");
            break;
        case 8:
            printf("8 ! Mieux que naze ");
            break;
        case 10:
            printf("10 ! Presque passable ");
            break;
        default:
            printf("%d ! Pas prevu par le de-qui-corrige", note);
        break; }
    printf("\n");
}

// Q32 et 33
void q32(int num)
{
    int quotient = num / 4;
    int reste = num % 4;
    int compt = 0;
    while (quotient >= 0)
    {
        if (quotient == 0) compt++;
        if (compt == 2) break;
        switch (reste) {
            case 0:
                printf("Ga ");
                break;
            case 1:
                printf("Bu ");
                break;
            case 2:
                printf("Zo ");
                break;
            case 3:
                printf("Meu ");
                break;
                
            default:
                break;
        }
        reste = quotient % 4;
        quotient = quotient / 4;
        
        
        
    }
    printf("\n");
}

int main() {
    q32(3);
    q32(6);
    q32(11);
    q32(42);
    return 0;
}

