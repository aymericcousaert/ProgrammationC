#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>


typedef int ensemble;
int nbSommets; // Nombre de sommets du graphe : doit etre inferieur ou egal a 32
int** cout;    // cout[i][j] = cout de l'arc (i,j)

int nbAppelD = 0;
int** memD;

bool estElementDe(int e, ensemble s){
    // Precondition : 1 <= e < nbSommets
    // Postrelation : retourne true ssi e appartient à l'ensemble s
    if ((s & (1 << (e-1))) != 0) return true;
    return false;
}

bool estVide(ensemble s){
    // Postrelation : retourne true si s est vide
    return (s == 0);
}

ensemble ajouteElement(ensemble s, int e){
    // Precondition : 1 <= e < nbSommets
    // Postrelation : retourne l'ensemble s U {e}
    return (s | (1 << (e-1)));
}

ensemble enleveElement(ensemble s, int e){
    // Precondition : 1 <= e < nbSommets
    // Postrelation : retourne l'ensemble s \ {e}
    return (s ^ (1 << (e-1)));
}

ensemble creeEnsemble(){
    // Postrelation : retourne l'ensemble contenant tous les entiers compris entre 1 et nbSommets-1
    return (1 << (nbSommets - 1)) - 1;
}

void afficheEnsemble(ensemble s){
    // Postcondition : affiche sur stdout l'ensemble des elements de s
    int i = 1;
    while (s != 0){
        if (s%2 != 0) printf(" %d",i);
        s /= 2;
        i++;
    }
}

int card(ensemble s){
    // Postcondition : retourne le nombre d'elements contenus dans s
    int cpt = 0;
    while (s){
        s &= (s-1) ;
        cpt++;
    }
    return cpt;
}

int plusPetitElement(ensemble s){
    // Precondition : estVide(s) = false
    // Postrelation : retourne le plus petit element de s
    return log2(s & -s)+1;
}

void creeCout(){
    // postrelation initialise la matrice cout avec des couts compris entre coutMin et coutMax
    int coutMin = 10;
    int coutMax = 40;
    int i, j, iseed, it;
    iseed = 1;
    cout = (int**) malloc(nbSommets*sizeof(int*));
    for (i=0; i<nbSommets; i++){
        cout[i] = (int*) malloc(nbSommets*sizeof(int));
        for (j=0; j<nbSommets; j++){
            if (i == j) cout[i][j] = coutMax+1;
            else {
                it = 16807 * (iseed % 127773) - 2836 * (iseed / 127773);
                if (it > 0)	iseed = it;
                else iseed = 2147483647 + it;
                cout[i][j] = coutMin + iseed % (coutMax-coutMin+1);
            }
        }
    }
}


int calculeD(int i, ensemble s){
    nbAppelD++;
    // Precondition : estElementDe(i,s) = false et estElement(0,s) = false
    // Postrelation : retourne le cout du plus court chemin partant du sommet i, passant par chaque sommet de s exactement une fois, et terminant sur 0

    if (memD[i][s] == 0)
    {
      if (estVide(s)) return cout[i][0];
        int min = INT_MAX;
        for (int j=1; j<nbSommets; j++){
            if (estElementDe(j,s)){
                int d = calculeD(j, enleveElement(s,j));
                if (cout[i][j] + d < min) min = cout[i][j] + d;
             }
        }
        memD[i][s] = min;
        return min;
    }
    else
    {
        return memD[i][s];
    }

}

int calculeDIteratif(int i, ensemble s, int nbSommets){
    nbAppelD++;
    // Precondition : estElementDe(i,s) = false et estElement(0,s) = false
    // Postrelation : retourne le cout du plus court chemin partant du sommet i, passant par chaque sommet de s exactement une fois, et terminant sur 0
      if (estVide(s)) return cout[i][0];
        int min = INT_MAX;
        for (int ens = 1; ens < card(s); ens++){
            for (int i = 1; i < nbSommets; i++)
            if (!estElementDe(i,ens))
            {
                if (card(ens) == 0)
                {
                    memD[i][ens] = cout[i][0];
                }
                else
                {
                    memD[i][ens] = INT_MAX;

                    for (int j = 0; j < nbSommets; j++)
                    {
                        if (estElementDe(j,ens))
                        {

                            if (cout[i][j] + memD[j][enleveElement(ens,j)] < memD[i][ens])
                            {
                                memD[i][ens] = cout[i][j] + memD[j][enleveElement(ens,j)] ;
                            }
                        }
                    }
                }
             }
        }
        return memD[nbSommets][card(s)];
}

int main(){

    printf("Nombre de sommets : ");
    fflush(stdout);
    scanf("%d",&nbSommets);

    if ((nbSommets > 32) || (nbSommets < 1)){
        printf("Le nombre de sommets doit être compris entre 1 et 32\n");
        return 0;
    }
    memD = (int**)malloc(nbSommets*sizeof(int*));

    for (int i = 0; i < nbSommets; i++)
    {
        memD[i] = malloc((int)pow(2,nbSommets+1)*sizeof(int)); // Ou utiliser INT_MAX
    }
    creeCout();
    ensemble s = creeEnsemble(); // s contient tous les entiers compris entre 1 et nbSommets-1
    clock_t tpsDebut = clock();


    // int d = calculeD(0,s);

    int d = calculeDIteratif(0,s,nbSommets);
    float duree = ((double) (clock() - tpsDebut)) / CLOCKS_PER_SEC;
    printf("Longueur du plus court circuit hamiltonien = %d ; temps de calcul = %.3fs ; nb d'appels à D : %d\n",d,duree,nbAppelD);
    return 0;
}



/* Question 1 : plus gde valeur pour laquelle le programme s'execute en moins de 1 minute : 13 (56sec)
 * Question 2 : pour N = 10, 986410 appels à calculeD ; (10^2) * (2^10) = 102400; 10! = 3628800
 *              pour N = 13, 6227020800 appels à DcalculeD ; (13^2) * (2^13) = 1384448; &"! =  6227020800
 *              pour N = 24,
 *
 * Avec memoisation :
 *              pour N = 10, 9226 appels à calculeD
 *              pour N = 13, 135181 appels à calculeD
 *              pour N = 16, 1720336 appels à calculeD
 *
 * Plus gd N tel que le résultat est en moins de 1 min : 24 (49 sec) ; il y a dans ce cas 1061158936 appels à calculeD
 * (24^2) * (2^24) = 9663676416 ;  24! = 6.204484e+23 ;
 *
 * Derniere partie :
 *
 * Si E inclus dans E' et i et i' en sont la représentation respective, alors i < i'
 *
 * On fait une boucle sur les i croissants
 *
 */
