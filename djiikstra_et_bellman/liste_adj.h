#ifndef LISTE_ADJ_H
#define LISTE_ADJ_H
#include "Liste.h"
#include <stdio.h>

typedef struct Liste_Adj {
   int taille;      // taille de la Liste
   Liste** tabList; // tableau de la Liste
} Liste_Adj;

Liste_Adj* creerListeAdj(int taille);
void detruireListeAdj(Liste_Adj**);
void insererListeAdj(Liste_Adj*, int, int, int);
int compteTabListe(Liste_Adj*);                     // compte le nombre d'arête

#endif
