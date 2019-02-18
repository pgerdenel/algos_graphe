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
void detruireListeAdj(Liste_Adj** la) {
	int i;
	for(i=0;i<(*la)->taille;++i)
		detruireListe(&(*la)->tabList[i]);
	free((*la)->tabList);
	free(*la);
}

void afficherListeAdj(Liste_Adj* la) {
	int i;
	printf("\n#################### Affichage Liste d'adjacence #######################################\n\n");
	for(i=0; i<la->taille;++i) {
		afficherListe(la->tabList[i]);
    printf("\n");
	}	
}

void insererListeAdj(Liste_Adj* la, int ind, int c, int p) {
  inserer(la->tabList[ind],creerCellule(c, p)); 
}

Cellule* rechercherListeAdj(Liste_Adj* la, int x, int ind) {
  return rechercher(la->tabList[ind], x);
}

void supprimerListeAdj(Liste_Adj* la, int x, int ind) {
  supprimer(la->tabList[ind], rechercherListeAdj(la, x,ind));
}
int compteTabListe(Liste_Adj* la) {
  int count=0;
  int i;
  for(i=0;i<la->taille;++i) {
    count += compteListe(la->tabList[i]);
  }
  return count;
}
