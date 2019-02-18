#ifndef KRUSKAL_H
#define KRUSKAL_H
#include <stdlib.h>
#include "graphe.h"
#include "Ensemble.h"

void genererAcpmKruskal(Graphe*); // génère un arbre couvrant de poids minimal d'un Graphe en gérant listeAdj'évolution des composantes connexes des sommets durant la construction de listeAdj'arbre

#endif