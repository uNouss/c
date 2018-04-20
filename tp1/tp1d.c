#include <stdio.h>
#include <stdlib.h>

int init(int tab[8]){
    for(int i = 0; i < 8; i++){
        tab[i] = 0;
    }
}

int incr(int t[8]){
    int arret = -1;
    for(int i = 7; i >= 0 && arret != 0; i--){
        if(t[i]){
            t[i] = 0;
        }
        else if(!t[i]) {
            t[i] = 1;
            arret = 0;
        }
    }
    return arret;
}

void init_tab(int n, int tab[8]){
    int idx = 7;
    while( n/2 != 0){
        tab[idx--] = n%2;
        n /= 2;
    }
    tab[idx] = n%2;
}

void print_tab(int tab[8]){
    for(int i = 0; i < 8; i++){
        printf("%d", tab[i]);
    }
}

/*void usage(char *arg){
    printf("%s ENTIER\n", arg);
}*/

int main(int argc, char **argv){
    /*if(argc != 2 ){
        usage(argv[0]);
        return EXIT_FAILURE;
    }*/
    int tab[8];
    for(int i = 0; i < 256; i++){
        init(tab);
        init_tab(i, tab);
        printf("Initiale: %3d : ", i);
        print_tab(tab);
        printf(" , Calculé: %3d : ", i+1);
        int deb = incr(tab);
        print_tab(tab);
        printf(" , debordement ? %2d\n", deb);
    }
    return EXIT_SUCCESS;
}
