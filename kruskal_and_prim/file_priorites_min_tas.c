#include "file_priorites_min_tas.h"

// Crée un tas et initialise les valeurs du tableau
tas* creer_liste_priorite(Graphe* graphe, int sommet_arbitraire) {
  tas* ts = (tas*)malloc(sizeof(tas));
  ts->taille=graphe->nbSommet;
  ts->taille2=graphe->nbSommet;
  ts->t = (Sommet*) malloc(sizeof(Sommet)*(graphe->nbSommet));
  for(int i=0; i<graphe->nbSommet; ++i) {
    ts->t[i].sommet=i;
    ts->t[i].pere=-1;
    ts->t[i].distance=999;
  }
  ts->t[sommet_arbitraire].distance=0;
  return ts;
}
// Parcourt les noeuds de l'arbre et appelle entasserMin pour chacun
void construireTasMin(tas* tas) {
	int i;
	for(i=(tas->taille/2)-1;i>=0;--i)
		entasserMin(tas,i);
}
// échange 2 clé de Sommet d'un tableau de Sommet
void echange(Sommet* t, int i, int j) {
	Sommet swap = t[i];
	t[i] = t[j];
	t[j] = swap;
}
// entasse la valeur vers le bas pour conserver la propritété de tas-min (pour que le sous arbre enraciné en int deviennen un tas min)
void entasserMin(tas* tas, int i) {
    int max=i;
    int g=gauche(i),d=droit(i);
    if(g<tas->taille && tas->t[g].distance < tas->t[i].distance) {
        max = g;
    }
    if(d<tas->taille && tas->t[d].distance < tas->t[max].distance) {
        max = d;
    }
    if(max != i) {
        echange(tas->t, i, max);
        entasserMin(tas,max);
    }
}
// renvoie le parent du Sommet
int parent(int i) {
  if(i%2==0)
    return i/2-1;
  else
    return i/2;
}
// renvoie le fils droit du Sommet
int droit(int i) {
    return 2*i+2;
}
// renvoie le fils gauche du Sommet
int gauche(int i) {
    return (2*i+1);
}
// renvoie la structure Sommet minimum du tas
Sommet extraire_min_tas(tas* tas) {
  if(tas->taille < 0) {
    printf("problème de taille\n");
    exit(0);
  }
  Sommet min = tas->t[0];
  tas->t[0] = tas->t[tas->taille-1];
  tas->t[tas->taille-1] = min;
  tas->taille = tas->taille-1;
  entasserMin(tas,0);
  return min;
}
// diminue la valeur de la clé du Sommet pour lui donner une nouvelle valeur <= à la valeur du Sommet i
void DiminuerCleTas(tas* tas, int i, int j) {
  tas->t[i].distance = j;
  while(i > 0 && tas->t[parent(i)].distance > tas->t[i].distance) {
      echange(tas->t, i, parent(i));
    i = parent(i);
  }
}
// affiche le tas après application de l'algo de prim
void afficherAcpmPrim(tas *tas) {
  int i;
  printf("\n---------------------\n");
  printf("depart\tarrive\tpoids\n");
  printf("---------------------\n");
    for(i = tas->taille2 -2; i > -1 ; i--) {
    printf("%d\t %d\t %d \t\n",tas->t[i].pere,tas->t[i].sommet,tas->t[i].distance);
  }
  printf("---------------------\n");
  printf("\nPoids arbre = %d\n", distancePrim(tas));
}
// détruit le tas/libère la mémoire
void detruireTas(tas** tas) {
  free((*tas)->t);
  free(*tas);
}
// calcule le poids de l'arbre sur le tas
int distancePrim(tas* tas) {
  int i = 0;
  int som=0;
  for(i =0; i<tas->taille2;++i) {
    som+=tas->t[i].distance;
  }
  return som;
}
// recherche l'indice du Sommet dans le tas
int rechercheSommet(tas* tas, int val) {
  int i=0;
  while (i< tas->taille && tas->t[i].sommet != val)
    ++i;
  return i;
}
