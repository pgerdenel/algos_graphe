#ifndef TAS_H
#define TAS_H
#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"
/*
 * Permet d'implémenter une file de priorités min (par tas) pour l'algo de prim
 * - optimise le temps de l'algorythme
 */
typedef struct Sommet {
    int sommet; 	// clé du Sommet
    int distance;	// distance du Sommet
    int pere;		// Sommet père du Sommet
} Sommet;

typedef struct tas {
	int taille;  // taille actuel
	int taille2; // reste fixe
	Sommet* t;   // tableau de structure Sommet
} tas;

tas* creer_liste_priorite(Graphe*, int);	// initialise la file de priorité min
void echange(Sommet *, int, int);			// échange 2 sommets de l'arbre
void entasserMin(tas*, int);				// entasse la valeur vers le bas pour conserver la propritété de tas-min (pour que le sous arbre enraciné en int deviennen un tas min)
void construireTasMin(tas*);				// Parcourt les noeuds de l'arbre et appelle entasserMin pour chacun
int parent(int);							// renvoie le parent du Sommet
int droit(int);								// renvoie le fils droit du Sommet
int gauche(int);							// renvoie le fils gauche du Sommet
Sommet extraire_min_tas(tas*);				// renvoie la structure Sommet minimum du tas
void DiminuerCleTas(tas*, int, int);		// diminue la valeur de la clé(2p) du Sommet pour lui donner une nouvelle valeur <= à la valeur du Sommet(1p)
void afficherAcpmPrim(tas*);				// affiche le tas après application de l'algo de prim
void detruireTas(tas**);					// détruit le tas/libère la mémoire
int distancePrim(tas*);						// calcule le poids de l'arbre sur le tas
int rechercheSommet(tas*, int);				// recherche l'indice du Sommet dans le tas

#endif
