#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

/* structure de données permettant de gérer les composantes représentant un arc (composantes connexes) */

// structure pour crée un arc
typedef struct arete {
  int s1;   // Sommet ori
  int s2;   // Sommet extremité
  int poids;// poids de l'arête
} arete;

// structure Cellule pour une file
typedef struct cellS {
  int val;                  // sommet
  struct cellS *next;       // pointe sur l'Ensemble suivant
  struct Ensemble *ens;     // pointe sur l'Ensemble auquel il appartient
} cellS;
 
//file pour l'Ensemble
typedef struct Ensemble {
  struct cellS* tete;
  struct cellS* queue;
} Ensemble;

arete** creerArete(int);                // creer le tableau d'arête
arete** creeTabArete(Graphe*,int);
void detruireArete(arete**);       // détruit le tableau de composantes connexes (d'arête)

#endif
