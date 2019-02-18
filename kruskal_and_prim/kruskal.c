#include "kruskal.h"
#include <stdlib.h>
/*
 * Algorythme de Kruskal(glouton) permettant de déterminer un arbre couvrant de poids minimal d'un Graphe
 * en gérant l'évolution des composantes connexexes des sommets durant la consutrcrtion de l'arbre
 * - on construit l'arbre arête par arête
 * - par tableau ou pas liste
 */

/* Fonction permetttant de générer un arbre couvrant de poids minimal pour le graphe d'exemple
 * par la méthode de Kruskal implémentée en gérant les composantes connexes avec un tableau
 */
void genererAcpmKruskal(Graphe* graphe) {

    int i,cpte=0;

    // compte le nombre d'arête contenu dans la liste d'adjacence
    int nbArete = compteTabListe(graphe->listeAdj);

    //construction d'un tableau d'arêtes
    arete** tab = creeTabArete(graphe, nbArete); // creer le tableau d'arête

    // trie du tableau d'arêtes par ordre croissant
    triRapide(tab, nbArete);

    // création d'un tableau (de liste )d'ensembles disjoints permettant de gérer les composantes connexes
    Ensemble** ensemble_disj = (Ensemble**)malloc(sizeof(Ensemble*)*(graphe->nbSommet));

    // pour chaque Sommet
    for(i=0;i<graphe->nbSommet;++i) {
        ensemble_disj[i]=creer_ensemble(i); // on crée un Ensemble avec lui seul dedans
    }

    //création d'un tableau des arêtes retenues lors de l'exécution de l'algorithme
    arete** tab_retenu = creerArete(graphe->nbSommet-1); // -1 car 0 est le premier !!
    cpte=0;
    // on itère nbArete fois
    for(i=0;i<nbArete;++i) {
        // si le Sommet d'origine et l'extrémité ne font pas partie du même Ensemble
        if(trouver_ensemble(ensemble_disj[tab[i]->s_ori]->tete) != trouver_ensemble(ensemble_disj[tab[i]->s_ext]->tete)){
            // On conserve l'arête
            tab_retenu[cpte]=tab[i];
            cpte++;
            // on réunit les 2 ensembles
            unionE(ensemble_disj[tab[i]->s_ori]->tete, ensemble_disj[tab[i]->s_ext]->tete);
        }
    }

    // afficher kruskal
    afficherKruskal(tab_retenu, graphe->nbSommet-1);

    // libération mémoire
    detruireArete(tab, nbArete);
    detruireArete(tab_retenu, graphe->nbSommet-1);
    detruireEnsemble(ensemble_disj, graphe->nbSommet);
  
}
