#include <stdio.h>
#include <stdlib.h>

void usage(char *s){
    printf("USAGE: %s [BASE] [ENTIER]\n\tBASE = 2|8|10|16\n", s);
}


int baseInvalide(int base){
    if((base == 2) || (base == 8) || (base == 10) || (base == 16))
        return 1;
    return 0;
}

int dec2any(int base, int entier){
    return ( entier < base || base == 10 ) ? entier: ((entier % base) + 10 * dec2any(base, entier/base));
}


int length(int entier){
    int cpt = 1;
    while(entier/10 != 0){
        cpt++;
        entier = entier/10;
    }
    return cpt;
}

int puissance(int entier, int exposant){
    int p = 1;
    for(int i = 0; i < exposant; i++){
        p *= entier;
    }
    return p;
}

int any2dec(int base, int entier){
    int nb_car = length(entier);
    int i = 0;
    int nombre = 0;
    while( i < nb_car && entier/10 != 0){
        nombre += (entier%10)*puissance(base,i++);
        entier = entier/10;
    }
    nombre += (entier%10)**puissance(base,i++);
    return nombre;
}

int main(int argc, char **argv){
    if((argc != 3) || (baseInvalide(atoi(argv[1])) == 0)){
        usage(argv[0]);
        return EXIT_FAILURE;
    }
    int base = atoi(argv[1]);
    int entier = atoi(argv[2]);
    printf("nb car de %d = %d \n", entier, length(entier));
    printf("%d puissance %d = %d\n", 4, 4, puissance(4,4));
    printf("%d en base %d --> %d\n", entier, base, dec2any(base,entier));
    printf("%d en base %d --> %d\n", entier, base, any2dec(base,entier));
    return EXIT_SUCCESS;
}
