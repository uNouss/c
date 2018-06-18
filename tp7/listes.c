#include <stdio.h>
#include <stdlib.h>


/* définir les structures cell et le type list */
typedef struct cell_t{
    int val;
    struct cell_t * next;
}cell;

typedef cell* list;

int head(list l){
  /* renvoie la tête de la liste l */
    return l->val; // *(l.val);
}

list tail(list l){
  /* renvoie la queue de la liste l */
    return l->next;
}

list cons(int v, list l){
    /* renvoie une liste de tête v et de queue l */

    list list_new = (list) malloc (sizeof(cell));
    list_new->val = v;
    list_new->next = l;
    return list_new;
}

int length(list l){
    /* renvoie le longueur de la liste l */
    /*int size = 0;
    while(l != NULL){
        size++;
        l = tail(l);
    }
    return size;*/
  if(l == NULL) return 0;
  return 1+length(tail(l));
}

void print_list(list l){
    /* affiche la liste l */
    printf("[");
    while(l != NULL){
      printf("%d ", head(l));
      l = tail(l);
    }
    printf("]\n");
}

list append(list l1, list l2){
    //renvoie la liste qui est la concaténation des listes l1 et l2
    //on se positionne à la fin de la première list
  if(l1 == NULL) return l2;
  return cons(head(l1),append(tail(l1), l2));
}

list reverse(list l){
      /* renvoie la liste l renversée */
    //if(l->next == NULL) return l;
    //list r = reverse(tail(l));
    //l->next = NULL;
    //return append(r, l);
    return (!l)?NULL:append(reverse(tail(l)), cons(head(l), NULL));
}


list copy(list l){
    // renvoie une copie de la liste passée en paramètre
    /*list r = NULL; list p = NULL;
    int i = 0;
    while( l != NULL ){
        list n = cons(l->val, NULL);
        if( p == NULL) p = n;
        l = tail(l);
        if( r != NULL )
            r = append(r, n);
    }
    return r;*/
  if(l == NULL) return l;
  return cons(head(l), copy(tail(l)));
}

list insert(int v, list l){
    /* insert v dans l à la première position suivie d'une valeur plus grande que v */
    /*list n = cons(v, NULL);
    list first = NULL;
    list prec = NULL;
    while( l != NULL ){
        if( v < head(l) ){
            n->next = l;
            prec->next = n;
            return first;
        }
        prec = l;
        l = tail(l);
        if(first == NULL) first = prec;
	}*/
  if(l == NULL || v <= head(l)) return cons(v, l);
  else{
    l->next = insert(v, tail(l));
    return l;
  }
}

list tri_insertion(list l){
      /* tri par insertion */
  /*if( l == NULL) return NULL;
    list r = cons(head(l), NULL);

    while(tail(l) != NULL){
      l = tail(l);
      r = insert(head(l), r);
    }
    return r;*/
  if(l == NULL) return l;
  else insert(head(l), tri_insertion(tail(l)));
}

int main(int argc, char **argv){
  /* teste les fonction print_list, length et reverse d'une
     liste d'entiers passés en paramètre de l'exécutable */
    list maListe = NULL;
    list maListe2 = NULL;

    maListe = cons(11, maListe);
    maListe = cons(15, maListe);
    maListe = cons(30, maListe);
    maListe = cons(4, maListe);

    printf("head = %d\n", head(maListe));
    printf("taille = %d\n", length(maListe));
    print_list(maListe);

    maListe2 = cons(12, maListe2);
    maListe2 = cons(16, maListe2);
    maListe2 = cons(31, maListe2);
    maListe2 = cons(5, maListe2);
    print_list(maListe2);

    list l = append(maListe, maListe2);
    printf("liste l1 + l2 = ");print_list(l);
    l = reverse(l);
    printf("liste reverse l = ");print_list(l);
    list copy_list = copy(l);
    printf("liste copy = ");print_list(copy_list);

    l = insert(8,l);
    printf("liste apres insert [size=%d] = ", length(l));print_list(l);

    l = insert(20,l);
    printf("liste apres insert [size=%d] = ", length(l));print_list(l);

    l = insert(30,l);
    printf("liste apres insert [size=%d] = ", length(l));print_list(l);
 
    printf("liste trié ", length(l));print_list(tri_insertion(l));

    return 0;
}
