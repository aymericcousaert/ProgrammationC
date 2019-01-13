#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

// Q1
// Test : le type char est-il signé ou non ?
int q1()
{
    char a;
    a = 127;
    a+=2;
    return (a<0);
}

// Q2
// Tailles (max/min) d'un entier signé et d'un entier non signé
void q2()
{
    /*
    Autre idée : puissance par décallage

    int i = 1;
    int max = i << 31;

    printf("%d", max);
    */

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

//Q4
// Affiche le nombre de bits sur lesquels sont codés le types long et long long (64)
void q4()
{
    printf("%d\r\n",sizeof(long int)*8);
    printf("%d\r\n", sizeof(long long int)*8);
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

void q7(){
    int i = 1;
    printf("%d\r\n", i);
    i = i++ + 1;
    printf("%d\r\n", i);
}

// Q8

int q8()
{
    if (sizeof(int) < -1)
        printf("Bizarre, bizarre ... ??\n");
    else
        printf ("Tout semble normal\n");
}

// Q9 & Q10

void q9()
{
   int pi = 3.14;
   float pi1 = 3.14;
   float pi2 = 3.1415926535897932384626433832;
   double pi3 = 3.1415926535897932384626433832;

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
void q12(){
    char lettre = 'A';
    lettre++;

    // Affichera B
    printf("%c\r\n", lettre);
}

// Q13
// Renvoie 4294902761 (on a fait le tour)
// Le résultat de la soustraction n'est pas de type unint16_t
// Le résultat est une variable de type uint32_t
void q13(){
    uint16_t a = 413;
    uint16_t b = 64948;
    fprintf(stdout, "%u\n", (a - b));
}

// Q15
// La mantisse est codée sur un nombre limité de bits (donc si on dépasse : on perd de l'information)
void q15(){

    long a = 80000002;
    printf("A EN FLOAT : %f \r\n", (float)a);
    float b = 2;
    long c = a / b;
    printf("res : %li\n", c);

}

// Q16, 17, 18 : ok

void q19(){
    int i = 5;
    char j = i;

    // N'affiche rien
    printf("%d -> %c \r\n",i, j);

    j = 'A';
    i = j;
    printf("%c -> %d \r\n",j, i);
}

void q20(){
    int i = 10;
    unsigned int j = i;

    printf("%d -> %u\r\n", i, j);

    int e = 0x2a3b;
    char f = e;
    // Est un point virgule
    printf("%d -> en char : %c \r\n", e, f);
}

void q21(){
    char A=3;
    int B=4;
    // Ne fonctionnera pas : pour pouvoir avoir un float on doit diviser 2 flots
    float C = A/B;
    printf("%c / %d = %f\r\n", A, B, C);
}


// Q22 : Gestion de chambres et de jacouzi



uint32_t printRoomsState(uint32_t allRooms){
    int mask = 1; // 000000000....00001 //
    for(int i = 0; i < 32; i++){
        int isRoomOccuped = mask & allRooms;
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




uint32_t roomGoesOccupied(uint32_t allRooms, unsigned int roomNum)
{
    return allRooms | roomNum;

}

bool isOccupied(uint32_t allRooms, unsigned int roomNum)
{
    return (allRooms & roomNum)==roomNum;
}

uint32_t roomGoesEmpty(uint32_t allRooms, unsigned int roomNum)
{
    return ~(roomNum) & allRooms;
}

void q22(){
    uint32_t chambre3 = 0b0100; // 0100 //
    uint32_t chambres = 15; // 0001 //

    chambres = chambres | chambre3;

    printf("%d\r\n",printRoomsState(chambres));
    roomGoesEmpty(chambres,1);
    printf("%d",printRoomsState(chambres));

}

int main()
{
    q22();
    return 0;
}
