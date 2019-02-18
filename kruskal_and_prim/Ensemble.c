#include "Ensemble.h"
#include "graphe.h"

arete** creerArete(int nbSommet) {
  // cree un tableau d'arêtes de taille nbSommet
  arete** tab = (arete**)(malloc(sizeof(arete*)*(nbSommet)));
  int i;
  for(i=0;i<nbSommet;++i) { 
      tab[i] = (arete*)(malloc(sizeof(arete)));
  }
  return tab;
}
arete** creeTabArete(Graphe* graphe, int nbArete) {
    arete** tab=creerArete(nbArete);
    int i,j,cpte=0;
    for(i=0;i<graphe->nbSommet;++i) {
        for(j=0;j<graphe->nbSommet;++j) {
            if(graphe->matrice[i][j]!=0) {
                tab[cpte]->s_ori=i;
                tab[cpte]->s_ext=j;
                tab[cpte]->poids=graphe->matrice[i][j];
                ++cpte;
            }
        }
    }
    return tab;
}
void detruireArete(arete ** t, int taille) {
    free(t);
}
Ensemble* creer_ensemble(int s0) {
    Ensemble* list_ensemble = (Ensemble*)(malloc(sizeof(Ensemble)));
    cell_E* sommet = (cell_E*)(malloc(sizeof(cell_E)));

    // On cree le Sommet
    sommet->val = s0;
    sommet->next = NULL;
    sommet->ensemble = list_ensemble;

    list_ensemble->tete = sommet;
    list_ensemble->queue = sommet;

    return list_ensemble;
}
void detruireEnsemble(Ensemble** list_ensemble, int taille) {
	free(list_ensemble);
}
// retourne un pointeur sur le représentant de l'Ensemble (cellule de tête de la liste d'Ensemble)
cell_E * trouver_ensemble(cell_E *sommet) {
    return sommet->ensemble->tete;
}
// reunit 2 ensembles et détruit les anciens ensembles
void unionE(cell_E *ce_1, cell_E *ce_2) {
    cell_E *s3;
    // On fait pointer la queue de l'Ensemble X vers la tête de l'Ensemble Y
    ce_1->ensemble->queue->next = ce_2->ensemble->tete;
    // On fait pointer la queue de l'Ensemble X vers la queue de l'Ensemble Y
    ce_1->ensemble->queue=ce_2->ensemble->queue;
    //
    for(s3 = ce_2->ensemble->tete; s3!=NULL; s3=s3->next) {
        s3->ensemble = ce_1->ensemble;
    }
}
// permet d'effectuer un tri croissant par poids du tableau d'arête
void triRapide (arete** t_arete, int taille) {
    // divisé pour régner, adapté au liste (n.log(n))
    int sep, i;
    arete *pivot, *tmp;

    if (taille < 2) {
        /*printf("pas besoin de trier le tableau contient 1 ou pas de valeur");*/
        return; // on arête la fonction
    }
    pivot = t_arete[taille - 1];
    sep  = i = 0;
        while (i<taille) {
        if (t_arete[i]->poids <= pivot->poids) {
            if (sep != i) {
                tmp=t_arete[i];
                t_arete[i]=t_arete[sep];
                t_arete[sep]=tmp;
            }
            sep ++;
        }
        i ++;
    }
    triRapide(t_arete, sep - 1);
    triRapide(t_arete + sep - 1, taille - sep + 1);
}
// fonction calculant le poids de l'arbre sur le tas
int distanceKruskal(arete** tab_arete,int taille) {
  int i, poids_total=0;
  // on parcours chaque arête du tableau et on additionne leur poid
  for(i=0; i<taille;++i) {
    poids_total+=tab_arete[i]->poids;
  }
  return poids_total;
}
void afficherKruskal(arete** tab_arete,int taille) {
  int i;
  printf("\n----------------------\n");
  printf("depart\tarrive\tpoids \n");
  printf("----------------------\n");
  for(i=0; i<taille; ++i) {
    printf(""
           "%d\t %d\t %d \t \n", tab_arete[i]->s_ori, tab_arete[i]->s_ext, tab_arete[i]->poids);
  }
  printf("----------------------\n");
  printf("\nPoids de l'arbre = %d\n", distanceKruskal(tab_arete,taille));
}
