#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

double benchmark(int64_t N, int64_t R) {
  
  int64_t* tab = malloc(sizeof(int64_t)*N);
  for (int i = 0; i < N; i++)
  {
    tab[i] = i;
  }
  int64_t i = N;
  int64_t j;
  while (i > 1)
  {
    i--;
    j = rand()%i;
    int64_t tmp = tab[j] ;
    tab[j] = tab[i];
    tab[i] = tmp;
  }
  printf("\n");
  double start = (double)clock()*1000;
  for(int id = 0; id<R ; id++){
    i = 0;
    while (tab[i] != 0)
    {
      i = tab[i];
    }
  }
  double diff = (double)clock()*1000-start;
  printf("%ld %g", sizeof(int64_t)*N,diff/(double)N/(double)R);
  free(tab);
  return diff/1000000.0;
}
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int64_t n = 1000;
    int64_t r = 100000;
    for(int b = 0; b < 100; b++) {
      n*=1.25;
      if(benchmark(n,r)>1.0){
        r*=0.5;
        if(r<1){
          r=1;
        }
      };
    }
    
    return 0;
}
