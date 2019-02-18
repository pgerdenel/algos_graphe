#ifndef H_LISTE_ADJ
#define H_LISTE_ADJ
#include "liste.h"
#include <stdio.h>

typedef struct Liste_Adj {
   int taille;          // taille de la liste
   Liste** tabList;   // tableau de la liste
} Liste_Adj;

Liste_Adj* creerListeAdj(int taille);
void detruireListeAdj(Liste_Adj**);
void afficherListeAdj(Liste_Adj*);
void insererListeAdj(Liste_Adj*, int, int, int);
Cellule* rechercherListeAdj(Liste_Adj*, int ,int);
void supprimerListeAdj(Liste_Adj*, int, int);
int compteTabListe(Liste_Adj*);                 // compte le nombre d'arête

#endif
