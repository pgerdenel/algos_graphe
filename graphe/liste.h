#ifndef LISTE_H
#define LISTE_H

typedef struct Cellule {
    struct Cellule* prev;
    struct Cellule* nxt;
    int value;
} Cellule;

typedef struct Liste {
    Cellule* tete;
    Cellule* queud;
} Liste;

Cellule* initialiser_cellule(int);
void detruire_cellule(Cellule**);

Liste* initialiser_liste();
void detruire_liste(Liste**);
void inserer(Liste*,Cellule*);
Cellule* rechercher(Liste*, int);
void supprimer(Liste*, Cellule*);
void afficher_liste(Liste*);

#endif
