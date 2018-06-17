#include <stdio.h>
#include <stdlib.h>

enum Nature{Symbole, Nombre};

struct Element{
    enum Nature nature;
    int         valeur;
    char        valSymb;
};

typedef struct Element Element;
typedef Expression Element[MaxP];

int Calculer (Char a, int x, int y);
void Inserer (Element x, Pile *p);
int Evaluer (Expression u, int n);


int Calculer (char a, int x, int y){
    switch (a) {
        case '+':
            return x + y;
        case '*':
            return x * y;
    }
}

void Inserer(Element x, Pile *p){
    Element y, z;
    if (EstPvide(p) || x.nature == Symbole)
        Pajouter(x, p);
    else{
        y = Pvaleur(p);
        if (y.nature == Symbole)
            Pajouter(y, p);
        else{
            Psupprimer(p);
            z = Pvaleur(p);
            Psupprimer(p);
            x.valeur = Calculer(z.valSymb, x.valeur, y.valeur);
            Inserer(x,p);
        }
    }
}

int Evaluer(Expression u, int n){
    int i;
    Pile p;

    FairePvide(&p);
    for(i = 1; i <= n; ++i)
        if(u[i].nature == Symbole || u[i].valSymb == '+' || u[i].valSymb == '*')
            Inserer(u[i], &p);
    return (Pvaleur(&p)).valeur;
}



