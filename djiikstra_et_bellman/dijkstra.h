#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "filePrioritesMin.h"
#include "graphe.h"

tas* sourceUniqueInitialisation2(Graphe* ,int);
void afficherDijkstra(tas*);
void dijkstra(Graphe*, int);

#endif