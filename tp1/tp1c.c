#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    double x = 0.1;
    double s;
    double t;
    int signe = -1;
    t = x;
    s = x;
    for(int i = 3; i < 12; i = i+2){
        t = t * x * x / (i * (i-1));
        s = s + signe * t;
        signe = -signe;
        printf("i = %2d ; s = %.9lf\n", i, s);
    }
    return EXIT_SUCCESS;
}
