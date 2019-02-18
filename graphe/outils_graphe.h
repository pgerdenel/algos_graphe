#ifndef OUTILS_GRAPHE_H
#define OUTILS_GRAPHE_H

#include "graphe.h"
#include "parcours.h"

parcours** parcoursLargeur(Graphe*, int);             // construit l'arbre de parcours en largeur à partir d'un sommet spécifique
void afficherChemin(parcours**, int, int);                // à partir d'une arborescence de parcours en largeur, donne le chemin le plus court entre l'origine du parcours et un sommet du graphe
parcours** parcourProfondeurRecurif(Graphe*, int);     // construit une forêt de parcours en profondeur tout en calculant les dates de découverte et de fin de traitement de chaque sommet
void visiter_PP(Graphe*,parcours*,int*, parcours**);   // visite et traite un sommet
void afficherProfondeur(parcours**, int);                // à partir d'une arborescence de parcours en profondeur, affiche les dates de découverte et de fin de traitement de chaque sommet

#endif
