#include <stdio.h>

#define MAX 30

void tests_length(void);
void tests_wc(void);
void tests_scan_string(void);
void tests_scan_int(void);
void tests_struct(void);

/* TODO */
typedef int livre_t;

int length(char s[])
{
    /* TODO */
    int cpt = 0;
    for(int i = 0; s[i] != '\0'; i++){
        cpt++;
    }
    return cpt;
}

int isAlphaNum(char c){
    if( (c >= '0' && c <='9') || ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' )) return 1;
    return 0;
}

int wc(char s[])
{
    /* TODO */
    int cpt = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(isAlphaNum(s[i])){
            cpt++;
        }
    }
    return cpt;
}

int scan_string(char s[MAX])
{
    /* TODO */
    int cpt = 0;
    char c;

    while(( c = getchar()) != EOF && cpt <= MAX){
        s[cpt++] = c;
    }
    if( cpt >= MAX ) return -1;
    s[cpt-1] = '\0';
    return cpt-1;
}

int scan_int()
{
    /* TODO */
    int res = 0;
    int i = 0;
    char c;
    while( ( c = getchar() ) != EOF && c != '\n' && ( c >= '0' && c <= '9')){
        res = res * 10 + ( c - '0' );
    }
    if ( c == EOF ) return -1;
    return res;
}


enum genres_t {narratifs, policier, historique, espionnage, conte};
enum maison_t {Flammarion, ActesSud,  Eyrolle};

typedef struct{
    char titre[MAX],
    char auteur[MAX],
    int annee,
    genres_t genre,
    int nbPage,
    maison_t edition
} livre_t;


void print_struct(livre_t l)
{
    /* TODO */
    printf("titre du livre   %s\n = ", l.titre);
    printf("\tauteur         %s\n = ", l.auteur);
    printf("\tpublié en      %d\n = ", l.annee);
    printf("\tgenre          %s\n = ", l.genre);
    printf("\tnombre de page %s\n = ", l.nbPage);
    printf("titre du livre   %s\n = ", l.edition);
}

livre_t scan_struct(void)
{
    /* TODO */
}

int main(void)
{
    //tests_length();
    //tests_wc();
    //tests_scan_string();
    tests_scan_int();
    tests_struct();
}

void tests_length(void)
{
    printf("========= tests de length ========== \n");
    printf("length(\"\")   : %d\n",length(""));
    printf("length(\"a\")  : %d\n",length("a"));
    printf("length(\"abc\"): %d\n\n\n",length("abc"));
}

void tests_wc(void)
{
    printf("========= tests de wc ============== \n");
    printf("wc(\"\")   : %d\n",wc(""));
    printf("wc(\"La propriete, c'est le vol. (Joseph Proudhon)\")  : %d\n",wc("La propriete, c'est le vol. (Joseph Proudhon)"));
    printf("wc(\"La liberte des autres etend la mienne a l'infini. (Mikhail Bakounine)\")  : %d\n",wc("La liberte des autres etend la mienne a l'infini. (Mikhail Bakounine)"));
    printf("wc(\"Le crime de penser n'entraine pas la mort. (George Orwell, 1984)\")  : %d\n\n\n",wc("Le crime de penser n'entraine pas la mort. (George Orwell, 1984)"));
}

void tests_scan_string(void)
{
    int res;
    char chaine[MAX];

    printf("========= tests de scan_string ========== \n");
    printf("Saisissez la chaine vide en tapant la touche \"Entrée\" : ");
    res = scan_string(chaine);
    printf("===> Chaine scannée : \"%s\" , retour de fonction: %d\n",chaine,res);

    printf("Saisissez la chaine \"abc\" : ");
    res = scan_string(chaine);
    printf("===> Chaine scannée : \"%s\" , retour de fonction: %d\n",chaine,res);

    printf("Saisissez la chaine \"a\" : ");
    res = scan_string(chaine);
    printf("===> Chaine scannée : \"%s\" , retour de fonction: %d\n",chaine,res);

    printf("Saisissez une chaine de plus de %d caractères: ", MAX);
    res = scan_string(chaine);
    printf("===> Chaine scannée : \"%s\" , retour de fonction: %d\n\n\n",chaine,res);
    /* on vide les caractères restant dans le tampon: */
    if (res == -1) while (getchar() != '\n');
}

void tests_scan_int(void)
{
    int res;
    printf("========= tests de scan_int ========== \n");
    printf("Saisissez l'entier 0: ");
    res = scan_int();
    printf("===> retour de fonction : %d\n", res);

    printf("Saisissez l'entier 123: ");
    res = scan_int();
    printf("===> retour de fonction : %d\n", res);

    printf("Saisissez 0x12: ");
    res = scan_int();
    printf("===> retour de fonction : %d\n\n\n", res);
    /* on vide les caractères restant dans le tampon: */
    if (res == -1) while (getchar() != '\n');
}

void tests_struct(void)
{
    printf("========= tests de scan_struct et print_struct ============== \n");
    print_struct(scan_struct());
}
