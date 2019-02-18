#ifndef LISTE_ADJ_H
#define LISTE_ADJ_H

#include <stdio.h>
#include "liste.h"

typedef struct Liste_Adj {
    int taille;         // taille de la liste
    Liste** tab_list;   // tableau de la liste
} Liste_Adj;

Liste_Adj* creerListeAdjacences(int);
void detruireListeAdjacences(Liste_Adj**);
void afficherListeAdjacences(Liste_Adj*);
void insererListeAdjacence(Liste_Adj*, int, int);
Cellule* rechercherListeAdjacence(Liste_Adj*, int ,int);
void supprimerListeAdjacence(Liste_Adj*, int, int);

#endif
