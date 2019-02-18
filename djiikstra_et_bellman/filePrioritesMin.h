#ifndef TAS_H
#define TAS_H
#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"
#include "bellman.h"

typedef struct tas{
	int taille;
	int taille2;
	sommet* t;
}tas;

tas* creer(Graphe*, int);
void echange(sommet*, int, int);
void entasserMin (tas*, int);
void construireTasMin(tas*);
int parent(int);
int droit(int);
int gauche(int);
sommet extraire_min_tas(tas*);
void DiminuerCleTas(tas*, int, int);
void detruireTas(tas**);
int rechercheSommet(tas*, int);

#endif
