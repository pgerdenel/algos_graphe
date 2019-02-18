#include "filePrioritesMin.h"

tas* creer(Graphe* graphe, int s) {
  tas* t = (tas*)malloc(sizeof(t));
  t->taille=graphe->nbSommet;
  t->taille2=graphe->nbSommet;
  t->t = (sommet*) malloc(sizeof(sommet)*(graphe->nbSommet));
  for(int i=0; i<graphe->nbSommet; ++i) {
    t->t[i].valeur=i;
    t->t[i].pere=NULL;
    t->t[i].distance=999;
  }
  t->t[s].distance=0;
  return t;
}
void construireTasMin(tas* tas) {
	int i;
	for(i=(tas->taille/2)-1;i>=0;--i)
		entasserMin(tas,i);
}
void echange(sommet* tab_sommet, int s1, int s2) {
	sommet swap = tab_sommet[s1];
	tab_sommet[s1] = tab_sommet[s2];
	tab_sommet[s2] = swap;
}
void entasserMin (tas* tas, int i) {
    int max=i;
    int g=gauche(i),d=droit(i);
    if(g<tas->taille && tas->t[g].distance < tas->t[i].distance)
        max=g;
    if(d<tas->taille && tas->t[d].distance < tas->t[max].distance)
        max=d;
    if(max != i) {
        echange(tas->t, i, max);
        entasserMin(tas,max);
    }
}
int parent(int i) {
    if(i%2==0)
        return i/2-1;
    else
        return i/2;
}
int droit(int i) {
    return 2*i+2;
}
int gauche(int i) {
    return (2*i+1);
}
sommet extraire_min_tas(tas* tas) {
    if(tas->taille < 0) {
        printf("taille erreur\n");
        exit(0);
    }
    sommet min = tas->t[0];
    tas->t[0] = tas->t[tas->taille-1];
    tas->t[tas->taille-1] = min;
    tas->taille = tas->taille-1;
    entasserMin(tas,0);

    return min;
}
void DiminuerCleTas(tas* tas, int i, int cle) {
    tas->t[i].distance = cle;
    while(i > 0 && tas->t[parent(i)].distance > tas->t[i].distance) {
        echange(tas->t, i, parent(i));
        i = parent(i);
    }
}
void detruireTas(tas** tas) {
  free((*tas)->t);
  free(*tas);
}
//fonction recherchant l'indice d
int rechercheSommet(tas* tas, int val) {
    int i=0;
    while (i < tas->taille && tas->t[i].valeur != val)
        ++i;
    return i;
}
