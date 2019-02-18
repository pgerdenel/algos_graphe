#include <stdlib.h>
#include "liste_adj.h"

Liste_Adj* creerListeAdjacences(int taille){
	Liste_Adj* liste_adj=(Liste_Adj*)malloc(sizeof(Liste_Adj));
	liste_adj->taille=taille;
	liste_adj->tab_list=(Liste**)malloc(sizeof(Liste*)*taille);
	int i;
	for(i=0;i<taille;++i) {
		liste_adj->tab_list[i] = initialiser_liste();
	}
	return liste_adj;
}
void detruireListeAdjacences(Liste_Adj** liste_adj){
	int i;
	for(i=0;i<(*liste_adj)->taille;++i)
		detruire_liste(&(*liste_adj)->tab_list[i]);
	free((*liste_adj)->tab_list);
	free(*liste_adj);
}
void afficherListeAdjacences(Liste_Adj* liste_adj){
	int i;
	printf("\n#################### Affichage Liste d'adjacence #######################################\n\n");
	for(i=0; i<liste_adj->taille;++i){
		afficher_liste(liste_adj->tab_list[i]);
    printf("\n");
	}	
}
void insererListeAdjacence(Liste_Adj* liste_adj, int s_ori, int s_ext){
	inserer(liste_adj->tab_list[s_ori], initialiser_cellule(s_ext));
}
Cellule* rechercherListeAdjacence(Liste_Adj* liste_adj, int s_ext, int ind){
  return rechercher(liste_adj->tab_list[ind], s_ext);
}
void supprimerListeAdjacence(Liste_Adj* liste_adj, int s_ext, int s_ori){
  supprimer(liste_adj->tab_list[s_ori], rechercherListeAdjacence(liste_adj, s_ext,s_ori));
}
