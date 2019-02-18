#ifndef LISTE_H
#define LISTE_H
#include <stdlib.h>
#include <string.h>

/*
 * Liste utilisé pour les listes d'adjacence
 */

typedef struct Cellule {
	struct Cellule* prev;
	struct Cellule* nxt;
	int value;
  	int poids;
} Cellule;

Cellule* creerCellule(int, int);
void detruireCellule(Cellule**);

typedef struct Liste {
	Cellule* tete;
} Liste;

Liste* creerListe();
void detruireListe(Liste**);
void inserer(Liste*, Cellule*);
Cellule* rechercher(Liste*, int);
void supprimer(Liste*, Cellule*);
void afficherListe(Liste*);
int compteListe(Liste*);

#endif
