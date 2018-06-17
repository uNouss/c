#include <stdio.h>
#include <stdlib.h>

typedef struct maillon MAILLON;
typedef MAILLON *PTR;

struct maillon{
    int valeur;
    struct maillon *suivant;
};


PTR nouveauMaillon(int v, PTR s){
    PTR result = malloc(sizeof(MAILLON));

    result = malloc(sizeof(MAILLON));
    if(result == NULL) {
        printf("Problème d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    result->valeur = v;
    result->suivant = s;

    return result;
}
/*
 * Recheche d'un élement dans une liste
 * if ( p != NULL)
 *      // l'élément cherché est présent, p point le maillon où il se trouve
 * else
 *      // l'élément cherché est absent
*/

/*
 * CONCATENATION DE LISTE
 * if(teteListe1 == NULL) teteListe1 = teteListe2
 * else queueListe1->suivant = teteListe2;
 * if (teteListe2 != NULL) queueListe1 = queueListe2
*/


PTR ajoutEnTete(int x, PTR t){
    return nouveauMaillon(x, t);
}

PTR ajoutEnQueue(int x, PTR t){
    if(t == NULL)
        return nouveauMaillon(x, NULL);
    else {
        t->suivant = ajoutEnQueue(x, t->suivant);
        return t;
    }
}

PTR recherche(int x, PTR t){
    if(t == NULL || t->valeur == x)
        return t;
    else
        return recherche(x, t->suivant);
}

PTR suppression(int x, PTR t) {
    if (t == NULL) return NULL;
    else
        if(t->valeur == x){
            PTR r = t->suivant;
            free(t);
            return r;
        }
        else {
            t->suivant = suppression(x, t->suivant);
            return t;
        }
}

PTR concatener(PTR t1, PTR t2){
    if( t1 == NULL ) return t2;
    return ajoutEnTete(t1->valeur, concatener(t1->suivant, t2));
}


PTR fusion(PTR t1, PTR t2){
    if (t1 == NULL) return t2;
    t1->suivant = fusion(t1->suivant, t2);
    return t1;
}

PTR copier(PTR t){
    if(t == NULL) return t;
    return ajoutEnTete(t->valeur, copier(t->suivant));
}


PTR inverserAux(PTR t1, PTR t2){
    if(t1 == NULL) return t2;
    return inverserAux(t1->suivant, ajoutEnTete(t1->valeur, t2));
}

PTR inverser(PTR t){
    return inverserAux(t, NULL);
}

PTR insertion(int x, PTR t){
    if(t == NULL || x <= t->valeur)
        return nouveauMaillon(x, t);
    else {
        t->suivant = insertion(x, t->suivant);
        return t;
    }
}

void afficher(PTR t){
    printf("Voici la liste : ");
    for(PTR p = t; p != NULL; p = p->suivant)
        printf("%d ",p->valeur);
    printf("\n");
}


PTR trier(PTR t){
    if(t == NULL) return t;
    return insertion(t->valeur, trier(t->suivant));
}

PTR tete = NULL, queue;

int main(){
    int x;
    PTR p;

    for(;;){
        printf("? ");
        scanf("%d", &x);
        if(x < 0)
            break;
        p = nouveauMaillon(x, NULL);
        if( tete == NULL )
            tete = p;
        else
            queue->suivant = p;
        queue = p;
        //tete = insertion(x, tete);
    }
    afficher(tete);
    PTR tete2 = suppression(0, copier(tete));
    afficher(inverser(tete2));
    afficher(trier(concatener(tete, tete2)));
    return(EXIT_SUCCESS);
}

