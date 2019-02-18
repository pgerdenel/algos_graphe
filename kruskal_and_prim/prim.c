#include "prim.h"
/*
 * L'algorythme de Prim(glouton) en démarrant d'un Sommet arbitraire et en étendant un arbre jusqu'à couvrir tous les sommets du Graphe.
 * Pour implmenter, l'algo de prim, il faut gérer l'Ensemble des sommets qui n'appartiennent pas à l'arbre en cours de construction à l'aide d'une structure de données permettant la sélection de
 * l'arête de poids minimal reliant chacun de ces sommets à l'arbre
 * - permet de déterminer un arbre couvrant de poids minimal d'un Graphe sans devoir trier les arêtes
 * - utilise un tableau pr gérer les sommets
 * - utilise aussi une filePrioriteMin pr gérer les sommets (au lieu du tableau)
 * - par tableau( O(S²) ou par tas O(2n + S.log(S)
 */
void genererAcpmPrim(Graphe* graphe, int sommet_arbitraite) {

    // on creer une liste de priorite min en commençant par le sommet arbitraire puis avec les sommets du graphe
	tas* tas = creer_liste_priorite(graphe, sommet_arbitraite);
	Cellule *tmpc;         // cellule temporaire de la liste d'adjacence
	int ind;                // indice de sommet
	Sommet tmp;             // structure Sommet temporaire
	construireTasMin(tas);

	while(tas->taille != 0) { // tant que la taille du tas n'est pas null
		// on extrait le Sommet minimum du tas
	    tmp = extraire_min_tas(tas);
	    // on récupère la cellule de tête de la liste du tableau de liste d'indice[sommet_min]
		tmpc = graphe->listeAdj->tabList[tmp.sommet]->tete;
        // Tant que cette cellule n'est pas vide
		while(tmpc!=NULL) {
		    // on recherche l'indice de cette cellule dans le tas
			ind=rechercheSommet(tas,tmpc->value);
            // si le poids de cette cellule est inférieure à la distance de la cellule du tas d'indice[sommet_min]
			if(tmpc->poids < tas->t[ind].distance) {
			    // le père de la cellule du tas d'indice[sommet_min] devient le sommet minimum du tas
				tas->t[ind].pere = tmp.sommet;
				// on diminue la clé de la cellule de tête d'indice[sommet_min]
				DiminuerCleTas(tas,ind,tmpc->poids);
			}
            // on passe au prochain élément de la liste
			tmpc=tmpc->nxt;
		}
	}
    // on affiche le tas final
	afficherAcpmPrim(tas);
	// libération mémoire
  	free(tmpc);
	detruireTas(&tas);

}
