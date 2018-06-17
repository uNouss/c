#include <stdio.h>
#include <stdlib.h>

const unsigned int MAX_CAR = 1024;

void code(char *s, char key){
    for(int i = 0; s[i] != '\0'; i++){
        s[i] = ( s[i] != '\n' ) ? s[i]^key : s[i];
    }
}

void decode(char *s, char key){
    for(int i = 0; s[i] != '\0'; i++){
        s[i] = ( s[i] != '\n' ) ? s[i]^key : s[i];
    }
}

unsigned char next_key(unsigned char x){
    return (x << 1) | ( n>> 7);
}


void usage(char *s){
    printf("USAGE: %s [CAR_KEY]\n", s);
}

int main(int argc, char **argv){
    if(argc != 2 || argv[1][1] != '\0'){
        usage(argv[0]);
        return EXIT_FAILURE;
    }
    char c, key = argv[1][0], sortie[MAX_CAR];
    int idx = 0;
    printf("ENTREE\n");
    while((c = getchar()) != EOF){
        sortie[idx++] = c;
    }
    sortie[idx] = '\0';
    code(sortie, key);
    printf("=======CODAGE======\n%s",  sortie);
    decode(sortie, key);
    printf("=====DECODAGE=======\n%s",  sortie);
    unsigned char  ci = 0x83;
    //unsigned flag = (ci & 0x01 ) ? 0x0F: 0;
    //ci >>= 1;
    unsigned char flag = (ci & 0xF0 ) ? 1: 0;
    ci <<= 1;
    ci |= flag;
    printf("%d rcl %d\n", 0xc1, ci);
    return EXIT_SUCCESS;
}
