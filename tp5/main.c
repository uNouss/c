#include <stdio.h>
#include "vecteur.h"

int main(){
  // TODO
  vecteur m[LONGUEUR];
  m[0].x = 111;
  m[0].y = 150;
  //printf("(%d;%d)\n", m[0].x, m[0].y);
  for(int i = 1; i < LONGUEUR; i++){
    m[i].x = LONGUEUR*i+i;
    m[i].y = i-i*i;
  }

  int ordre[LONGUEUR];
  
  afficher(m);
  trier(m);
  afficher(m);
  trier2(m, ordre);
  afficher2(m, ordre);
  return 0;
}
