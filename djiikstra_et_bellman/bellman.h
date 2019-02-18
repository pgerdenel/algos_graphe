#ifndef BELLMAN_FORD_H
#define BELLMAN_FORD_H
#include "graphe.h"

/*
 * Algorithme permettant de calculer les plus courts chemins et leurs poids depuis un sommet source donné dans un graphe ->orienté<- valué
 * il autorise des arcs de poids négatifs
 * il permet de détecter l'existence d'un circuit absorbant (poids total strictement négatif, accessible depuis le sommet source) à partir de l'origine
 */

typedef struct sommet {
	int valeur;
	int distance;
	struct sommet* pere;
} sommet;

void bellman(Graphe *,int);
sommet* creerSommet(int);
void relacher(sommet*, sommet*,int) ;
void detruireSommet(sommet** tabSommet, int taille);
void afficherPlusCourtChemin(sommet**, int);
sommet** sourceUniqueInitialisation(Graphe*, int);
void afficherBellman(sommet**, int);

#endif