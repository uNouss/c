#include <stdio.h>

int main(){
    char c;
    int i, po , pf;
    i = po = 0;

    while((c = getchar()) != EOF){
        switch((char)c){
            case '(' : po = (po >= 0 ) ? po+1:po; break;
            case ')' : po--; break;
        }
    }
    if((po == 0))
        printf("bien parenthesé\n");
    else
        printf("mal parenthesé\n");
    return 1;
}
