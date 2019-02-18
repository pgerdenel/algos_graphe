#include "bellman.h"
#include "Ensemble.h"

sommet* creerSommet(int s) {
	sommet* p= (sommet*)malloc(sizeof(sommet));
	p->valeur =s;
	p->distance=999;
	p->pere=NULL;
	return p;
}
void relacher(sommet* s1, sommet* s2, int p) {
  if(s2->distance > s1->distance + p) {
      s2->distance = s1->distance + p;
      s2->pere = s1;
  }
}
sommet** sourceUniqueInitialisation(Graphe* graphe, int s) {
  sommet** t;
  int i;
  t = (sommet**)malloc(sizeof(sommet*)*graphe->nbSommet);
  for(i=0;i<graphe->nbSommet;++i) {
      t[i]=creerSommet(i);
  }
  t[s]->distance = 0;
  return t;
}
void detruireSommet(sommet** tabSommet, int taille) {
  int i;
  for(i=0; i<taille ;++i)
      free(tabSommet[i]);
  free(tabSommet);
}
void afficherPlusCourtChemin(sommet** tabSommet, int s) {
  sommet* tmp =tabSommet[s];
  printf("[DESTINATION] sommet: %d (poids: %d) ",tmp->valeur,tmp->distance);
  tmp=tmp->pere;
  while(tmp!=NULL) {
    printf("<- sommet: %d (poids: %d) ",tmp->valeur,tmp->distance);
    tmp=tmp->pere;
  }
  printf("<- [SOURCE]");
  printf("\n");
}
void afficherBellman(sommet** tabSommet, int taille) {
  int i;
  printf("\nTableau des poids: \n");
  printf("---------------------\n");
  printf("Sommet\tDistance \n");
  printf("---------------------\n");
  for(i=0;i < taille;++i) {
    printf("%2d\t%2d\n", tabSommet[i]->valeur, tabSommet[i]->distance);
  }
  printf("---------------------\n");
  printf("\nLes plus courts chemins: \n");
  for(i=0;i<taille;++i)
    afficherPlusCourtChemin(tabSommet,i);
}
void bellman(Graphe* graphe, int s) {
  
  // source_unique_initialisation
  sommet** tabSommet=sourceUniqueInitialisation(graphe,s);
  int i,j;
  int nbArete=compteTabListe(graphe->l);     // on compte le nombre d'arête
  arete** tab=creeTabArete(graphe,nbArete);  // on crée le tableau de structure d'arête
 
  // On relache nbSommet fois tous les arcs
  for(i=0;i<graphe->nbSommet-1;++i) {
    for(j=0;j<nbArete;++j) {
      relacher(tabSommet[tab[j]->s1],tabSommet[tab[j]->s2],tab[j]->poids);
    }
  }
  // on parcourt tous les arcs pour vérifier la présence d'un circuit de poids strictement négatif
  for(j=0;j<nbArete;++j) {
    if(tabSommet[tab[j]->s2]->distance > tabSommet[tab[j]->s1]->distance+ tab[j]->poids) {
      printf(":S erreur circuit absorbant\n");
      exit(0);
    } 
  }

  afficherBellman(tabSommet,graphe->nbSommet);
  detruireSommet(tabSommet,graphe->nbSommet);
  detruireArete(tab);
}
