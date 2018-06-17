#include <stdio.h>
#include <stdlib.h>

int calu;

void erreur(char *mesg){
    printf("\nERREUR : %s\n", mesg);
    //system("pause");
    exit(EXIT_FAILURE);
}

void lire(void){
    do
        calu = getchar();
    while(calu == ' ' || calu == '\t' || calu == '\n');
}

void chiffre() {
    if( '0' <= calu && calu <= '9')
        lire();
    else
        erreur("Chiffre attendu");
}

void naturel(void){
    chiffre();
    while('0' <= calu && calu <= '9')
        chiffre();
}

void nombre(void){
    naturel();
    if( calu == '.'){
        lire();
        while('0' <= calu && calu <= '9')
            chiffre();
    }
}

void xpuissance(void){
    if(calu != 'X' && calu != 'x')
        erreur("'X' ou 'x' attendus");
    lire();
    if(calu == '^'){
        lire();
        naturel();
    }
}

void monome(void){
    if(calu == 'X' || calu == 'x')
        xpuissance();
    else {
        nombre();
        if(calu == '*'){
            lire();
            xpuissance();
        }
    }
}

void polynome(void){
    if(calu =='-')
        lire();
    monome();
    while(calu == '+' || calu == '-'){
        lire();
        monome();
    }
}


int main(void) {
    printf("? ");
    lire();
    polynome();
    if (calu != ';')
        erreur("';' attendu");
    printf("Syntaxe OK\n");

    //system("pause");
}
