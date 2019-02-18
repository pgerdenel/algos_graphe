#include "Ensemble.h"

arete** creerArete(int nbSommet){
  arete** tab = (arete**)(malloc(sizeof(arete*)*(nbSommet)));
  int i;
  for(i=0;i<nbSommet;++i){
    tab[i] = (arete*)(malloc(sizeof(arete)));
  }
  return tab;
}
arete** creeTabArete(Graphe*g, int nbArete) {
  arete** tab=creerArete(nbArete);
  int i,j,k=0;
  for(i=0;i<g->nbSommet;++i){
    for(j=0;j<g->nbSommet;++j){
      if(g->matrice[i][j]!=0){ 
        tab[k]->s1=i;
        tab[k]->s2=j;
        tab[k]->poids=g->matrice[i][j];
        ++k;
      }
    }
  }
  return tab;
}
void detruireArete(arete **t){
  free(t);
}
