#ifndef ENSEMBLE_H
#define ENSEMBLE_H
#include <stdlib.h>
#include <stdio.h>
#include "graphe.h"

/* structure de données permettant de gérer les composantes représentant un arc (composantes connexes) */

// structure pour crée une arête
typedef struct arete {
  int s_ori;   // Sommet ori
  int s_ext;   // Sommet extremité
  int poids;// poids de l'arête
} arete;

// structure Cellule pour la liste
// 'next' pointe sur l'Ensemble suivant et 'Ensemble' sur l'Ensemble auquel le sommet appartient
typedef struct cell_E {
  int val;                   // Sommet
  struct cell_E *next;        // pointe sur l'Ensemble suivant
  struct Ensemble *ensemble; // pointe sur l'Ensemble auquel il appartient
} cell_E;
 
// structure file pour les ensembles
typedef struct Ensemble {
  struct cell_E* tete;
  struct cell_E* queue;
} Ensemble;

arete** creerArete(int);                // creer le tableau d'arête
arete** creeTabArete(Graphe*graphe, int nbArete);
void detruireArete(arete**, int);       // détruit le tableau de composantes connexes (d'arête)
void detruireEnsemble(Ensemble**, int);  // détruit
Ensemble* creer_ensemble(int);          // creer un nouvel Ensemble dont le seul élément(et représentant) est le Sommet passé en paramètre, et ce Sommet ne doit pas être membre d'un autre Ensemble
cell_E* trouver_ensemble(cell_E*);        // retourne un pointeur sur le représentant del'Ensemble contenant la Cellule
void unionE(cell_E*, cell_E*);            // reunit 2 ensembles et détruit les anciens ensembles
void triRapide (arete**, int);          // permet d'effectuer un tri croissant par poids du tableau d'arête
int distanceKruskal(arete**, int);       // renvoie la somme des poids del'arbre
void afficherKruskal(arete **, int);     // affiche le tableau d'arête sommet départ, sommet arrive, poids

#endif
