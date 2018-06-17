#define MaxP 100

struct Pile{
    int     hauteur;
    Element contenu[MaxP];
};

typedef struct Pile Pile;

void FairePvide(Pile *p){
    p->hauteur = 0;
}

int EstPvide(Pile *p){
    return p->hauteur == 0;
}

void Pajouter(Element x, Pile *p){
    p->contenu[p->hauteur] = x;
    ++p->hauteur;
}

Element Pvaleur(Pile *p){
    int i;

    i = p->hauteur - 1;
    return p->contenu[i];
}

void Psupprimer(Pile *p){
    --p->hauteur;
}

Pile *PCarres(int n){
    Pile *p = (Pile *)malloc(sizeof(Pile));
    int i;

    FairePvide(p);
    for(i = n; i >= 1; --i)
        Pajouter(i*i, p);
    return (p);
}


