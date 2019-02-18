#include "dijkstra.h"
#include "bellman.h"

tas* sourceUniqueInitialisation2(Graphe* graphe, int s) {
	tas* tas = creer(graphe, s);;
	tas->t[s].distance = 0;
	return tas;
}
void dijkstra(Graphe* graphe, int s) {
	tas* tas=sourceUniqueInitialisation2(graphe, s);
	construireTasMin(tas);
	int ind,ind2;

	sommet tmp;
	Cellule *tempo;

 	while(tas->taille!=0) {
 		tmp=extraire_min_tas(tas);
 		ind2=rechercheSommet(tas, tmp.valeur);
 		tempo=graphe->l->tabList[tmp.valeur]->tete;
 		while(tempo!=NULL) {
      	ind=rechercheSommet(tas,tempo->value);
			if(ind<tas->taille) { // si le sommet est encore dans le tas
        		relacher(&tas->t[ind2],&tas->t[ind],tempo->poids);
        		// on met la plus petite valeur du tas en haut
				DiminuerCleTas(tas, ind,tas->t[ind].distance);
      }
      tempo=tempo->nxt;
    }
  }
 	afficherDijkstra(tas);
  	free(tempo);
	detruireTas(&tas);
}
void afficherDijkstra(tas* tas) {
	sommet* tmp;
	int i;

	printf("\nTableau des poids\n");
	printf(" --------------------- \n");
	printf("Sommet \t Distance \t\n");
	printf("---------------------\t\n");

	for(i=0;i<tas->taille2;++i) {
		printf("%2d \t %2d\n",tas->t[i].valeur,tas->t[i].distance);
	}

	printf(" -------------------- \n");
	printf("\nAfficher les plus courts chemins : \n");
	for(i=0;i<tas->taille2;++i) {
		tmp=&tas->t[i];
		printf("[DESTINATION] sommet: %d (poids: %d) ",tmp->valeur,tmp->distance);
		tmp=tmp->pere;

		while(tmp!=NULL) {
		printf("<- sommet: %d (poids: %d) ",tmp->valeur,tmp->distance);
		tmp=tmp->pere;
		}
		printf("<- [SOURCE]");
		printf("\n");
	}
	free(tmp);
}
