#include <stdio.h>
#include <stdlib.h>

typedef struct maillon MAILLON;
typedef MAILLON *PTR;

struct maillon{
    int valeur;
    struct maillon *suivant;
};

PTR tete = NULL;

int main(){
    int x;
    PTR p;

    for(;;){
        printf("? ");
        scanf("%d", &x);
        if(x < 0)
            break;

        p = malloc(sizeof(MAILLON));
        if(p == NULL) {
            printf("Problème d'allocation de mémoire\n");
            exit(EXIT_FAILURE);
        }
        p->valeur = x;
        p->suivant = tete;
        tete = p;
    }

    printf("Voici la liste construite\n");
    for(p = tete; p != NULL; p = p->suivant)
        printf("%d ",p->valeur);
    printf("\n");
    return(EXIT_SUCCESS);
}

