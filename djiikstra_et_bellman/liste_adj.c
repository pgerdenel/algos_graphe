#include "liste_adj.h"

Liste_Adj* creerListeAdj(int taille) {
	Liste_Adj* th=(Liste_Adj*)malloc(sizeof(Liste_Adj));
	th->taille=taille;
	th->tabList=(Liste**)malloc(sizeof(Liste*)*taille);
	int i;
	for(i=0;i<taille;++i)
		th->tabList[i]=creerListe();
	return th;
}
void detruireListeAdj(Liste_Adj** tl) {
	int i;
	for(i=0;i<(*tl)->taille;++i)
		detruireListe(&(*tl)->tabList[i]);
	free((*tl)->tabList);
	free(*tl);
}
void insererListeAdj(Liste_Adj* la, int ind, int c, int p) {
  inserer(la->tabList[ind],creerCellule(c, p)); 
}
int compteTabListe(Liste_Adj* la) {
  int count=0;
  for(int i=0;i<la->taille;++i) {
    count += compteListe(la->tabList[i]);
  }
  return count;
}
