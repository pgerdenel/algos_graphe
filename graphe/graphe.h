#ifndef GRAPHE_H
#define GRAPHE_H

#include "liste.h"
#include "liste_adj.h"

typedef struct Graphe {
    int nbSommet;           // nombre de sommet
    int oriente;            // si graphe orienté ou pas
    int value;              // si graphe valué ou pas
    int complet;            // graphe complet ou pas
    Liste_Adj* listeAdj;    // la liste d'adjacence
    int** matrice;          // la matrice d'adjacence
} Graphe;

void creerListesAdjacences(char*, Graphe*);    // lit les données du fichier  graphe1.txt  et construit le tableau de listes d'adjacences de ce graphe
void afficherListesAdjacences(Graphe*);       // affiche les listes d'adjacences d'un graphe
void creerMatriceAdjacences(char*, Graphe*);   // lit les données du fichier  graphe1.txt  et construit la matrice d'adjacences de ce graphe
void afficherMatriceAdjacences(Graphe*);      // affiche la matrice d'adjacences d'un graphe
Graphe* creerGraphe(char*);                   // crée un graphe en allouant la mémoire nécessaire et en utilisant les fonctions définies précédemment pour associer les représentations mémoire à la structure de graphe
void detruireGraphe(Graphe**);                // détruit un graphe en libérant ses ressources mémoire

#endif
