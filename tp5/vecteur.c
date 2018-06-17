#include <stdio.h>
#include <math.h>
#include "vecteur.h"

int norme(vecteur v){
  return (int)sqrt(v.x*v.x + v.y*v.y);
}

void afficher(vecteur m[]){
  for(int i = 0; i < LONGUEUR; i++){
    printf("(%d;%d) ",m[i].x, m[i].y, norme(m[i]));
  }
  printf("\n");
}

int maximum(vecteur m[]){
  return maximum_aux(m, 0);
}

// tri à bulles
void trier(vecteur m[]){
  /*for(int i = 0; i < LONGUEUR-1; i++){
    for(int j = 0; j < LONGUEUR - 1 - i; j++){
      if(norme(m[j]) > norme(m[j+1])){
	vecteur tmp;
	tmp.x, tmp.y =  m[j].x, m[j].y;
	m[j].x, m[j].y = m[j+1].x, m[j+1].y;
	m[j+1].x, m[j+1].y = tmp.x, tmp.y;
      }
    }
  }*/
  // TODO
  for(int i = 0; i < LONGUEUR; i++){
    int imax = maximum_aux(m, LONGUEUR - i);
    vecteur itmp = m[imax];
    m[imax] = m[LONGUEUR - i - 1];
    m[LONGUEUR - i -1 ] = itmp; 
  }
}

int maximum_aux(vecteur m[], int fin){
  int imax = -1;
  int nmax = -1;
  for(int i = 0; i < fin; i++){
    if(norme(m[i]) > nmax) {
      imax = i;
      nmax = norme(m[i]);
    }
  }
  return imax;
}

void trier2(vecteur m[], int ordre[]){
  // TODO
  for(int i = 0; i < LONGUEUR; i++){
    int imax = maximum_aux(m, LONGUEUR - i);
    ordre[LONGUEUR-i-1] = imax;
  }
  
}

void afficher2(vecteur m[], int ordre[]){
  // TODO
  for(int i = 0; i < LONGUEUR; i++){
    printf("(%d;%d) ", m[ordre[i]].x, m[ordre[i]].y);
  }
  printf("\n");
}
