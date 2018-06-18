#include <stdio.h>
#include <stdlib.h>


typedef struct _e
{

  int val;            /* données quelconques - ici un entier */
  struct _e* prec;    /* pointeur sur l'élément précédent */
  struct _e* suiv;    /* pointeur sur l'élément suivant */
} Liste_Circulaire_Doublement_Chainee;

Liste_Circulaire_Doublement_Chainee* creeListe (void)
{
  Liste_Circulaire_Doublement_Chainee* racine = malloc ( sizeof *racine );
  if ( racine != NULL )  /* si la racine a été correctement allouée */
    {
      /* pour l'instant, la liste est vide, 
	 donc 'prec' et 'suiv' pointent vers la racine elle-même */
      racine->prec = racine;
      racine->suiv = racine;
    }
  return racine;
}

void affichage(Liste_Circulaire_Doublement_Chainee* liste){
  /* parcours à l'endroit */
  Liste_Circulaire_Doublement_Chainee* it;
  for ( it = liste->suiv; it != liste; it = it->suiv )
    printf("%d, ", it->val);
}


void affichage(Liste_Circulaire_Doublement_Chainee* liste){
  /* parcours à l'endroit */
  Liste_Circulaire_Doublement_Chainee* it;
  for ( it = liste->prec; it != liste; it = it->prec )
    printf("%d, ", it->val);
}


void viderListe (Liste_Circulaire_Doublement_Chainee* liste)
{
  Liste_Circulaire_Doublement_Chainee *it, *next;
  for ( it = liste->suiv; it != liste; it = next )
    {
      next = it->suiv;  /* on enregistre le pointeur sur l'élément suivant avant de supprimer l'élément courant */
      free(it);         /* on supprime l'élément courant */
    }
}

void supprimerListe (Liste_Circulaire_Doublement_Chainee** liste)
{
  viderListe( *liste );  /* on vide d'abord la liste */
  free( *liste ), *liste = NULL;
}

void ajouterAvant (Liste_Circulaire_Doublement_Chainee* element, int val)
{
  Liste_Circulaire_Doublement_Chainee* nouvel_element = malloc ( sizeof *nouvel_element );
  if ( nouvel_element != NULL )
    {
      nouvel_element->val = val;
      /* on définit les pointeurs du nouvel élément */
      nouvel_element->prec = element->prec;
      nouvel_element->suiv = element;
      /* on modifie les éléments de la liste */
      element->prec->suiv = nouvel_element;
      element->prec = nouvel_element;
    }
}

void ajouterApres (Liste_Circulaire_Doublement_Chainee* element, int val)
{
  Liste_Circulaire_Doublement_Chainee* nouvel_element = malloc ( sizeof *nouvel_element );
  if ( nouvel_element != NULL )
    {
      nouvel_element->val = val;
      /* on définit les pointeurs du nouvel élément */
      nouvel_element->prec = element;
      nouvel_element->suiv = element->suiv;
      /* on modifie les éléments de la liste */
      element->suiv->prec = nouvel_element;
      element->suiv = nouvel_element;
    }
}

void ajouterEnTete (Liste_Circulaire_Doublement_Chainee* racine, int val)
{
  ajouterApres (racine, val);
}

void ajouterEnQueue (Liste_Circulaire_Doublement_Chainee* racine, int val)
{
  ajouterAvant (racine, val);
}

void supprimerElement (Liste_Circulaire_Doublement_Chainee* element)
{
  element->prec->suiv = element->suiv;
  element->suiv->prec = element->prec;
  /* on libère la mémoire allouée */
  free(element);
}

void supprimerPremierElement (Liste_Circulaire_Doublement_Chainee* racine)
{
  if (racine->suiv != racine)
    supprimerElement (racine->suiv);
}

Liste_Circulaire_Doublement_Chainee* premierElement (Liste_Circulaire_Doublement_Chainee* racine)
{
  if (racine->suiv != racine)  /* on vérifie que l'élément existe bien */
    return racine->suiv;
  else                         /* sinon on retourne NULL */
    return NULL;
}

Liste_Circulaire_Doublement_Chainee* premierElement (Liste_Circulaire_Doublement_Chainee* racine)
{
  if (racine->suiv != racine)  /* on vérifie que l'élément existe bien */
    return racine->suiv;
  else                         /* sinon on retourne NULL */
    return NULL;
}

Liste_Circulaire_Doublement_Chainee* dernierElement (Liste_Circulaire_Doublement_Chainee* racine)
{
  if (racine->prec != racine)  /* on vérifie que l'élément existe bien */
    return racine->prec;
  else                         /* sinon on retourne NULL */
    return NULL;
}

size_t nombreElements (Liste_Circulaire_Doublement_Chainee* liste)
{
  size_t n = 0;
  Liste_Circulaire_Doublement_Chainee* it;
    
  for ( it = liste->suiv; it != liste; it = it->suiv )
    n++;
  return n;
}


void cacherElement (Liste_Circulaire_Doublement_Chainee* element)
{
  element->prec->suiv = element->suiv;
  element->suiv->prec = element->prec;
}


void restaurerElement(Liste_Circulaire_Doublement_Chainee* element)
{
  element->prec->suiv = element;
  element->suiv->prec = element;
}

int main(){
  

  return EXIT_SUCCESS;
}
