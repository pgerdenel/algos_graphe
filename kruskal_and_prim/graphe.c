#include "graphe.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "liste_adj.h"

void creerListesAdjacences(char* fullpath, Graphe* graphe) {
  int indice,x;   // Sommet origine, Sommet extrémité
  char buff[255];
  int val;        // tmp val
  int poids;      // poids de listeAdj'arête

  FILE* fichier; 
  fichier=fopen(fullpath,"r");

  if(fichier==NULL) {
      perror("Erreur lors de listeAdj'ouverture du fichier %s\n"); // affiche errno
      exit(EXIT_FAILURE);
  }
  else {
      // On récupère le nombre de Sommet
      fscanf(fichier,"%s",buff);
      fscanf(fichier,"%d ",&val);
      graphe->nbSommet=val;

      // On crée la lise d'adjacence de taille nbSommet
      graphe->listeAdj = creerListeAdj(val);

      // On récupère la valeur qui indique si le Graphe est orienté ou pas
      fscanf(fichier,"%s ",buff);
      fscanf(fichier,"%d ",&val);
      graphe->oriente=val;

      // On récupère la valeur qui indique si le Graphe est valué ou pas
      fscanf(fichier,"%s ",buff);
      fscanf(fichier,"%d ",&val);
      graphe->value=val;

      // On récupère la valeur qui dit si le Graphe est complet ou pas
      fscanf(fichier,"%s ",buff);
      fscanf(fichier,"%d ",&val);
      graphe->complet=val;

      // Récupération des arêtes
      fscanf(fichier,"%s ",buff);
      // si le Graphe n'est pas orienté
      if(graphe->oriente==1) {
          while(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
              fscanf(fichier,"%s",buff);
              if(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
                  // On récupère la valeur du Sommet d'origine
                  indice=atoi(buff);
                  fscanf(fichier,"%s",buff);
                  // On récupère la valeur du Sommet d'extrémité
                  x=atoi(buff);
                  fscanf(fichier,"%s",buff);
                  // On récupère le poids de listeAdj'arête
                  poids=atoi(buff);
                  // On insère ces 2 valeurs dans la Liste d'adjacence
                  insererListeAdj(graphe->listeAdj, indice,x, poids);
              }
          }
      }
      else { // sinon le Graphe est orienté
          while(strcmp(buff,"finDefAretes")!=0) {  // Tant qu'on ne lit pas "finDefAretes"
              fscanf(fichier,"%s",buff);
              if(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
                  // On récupère la valeur du Sommet d'origine
                  indice=atoi(buff);
                  fscanf(fichier,"%s",buff);
                  // On récupère la valeur du Sommet d'extrémité
                  x=atoi(buff);
                  fscanf(fichier,"%s",buff);
                  // On récupère le poids de listeAdj'arête
                  poids=atoi(buff);
                  // On insère ces 3 valeurs dans la Liste d'adjacence
                  insererListeAdj(graphe->listeAdj, indice,x, poids);
                  // On insère également dans le sens inverse car un Sommet d'extrémité sera un Sommet d'origine aussi si orienté
                  insererListeAdj(graphe->listeAdj,x,indice, poids);
              }
          }
      }

  }
 	fclose(fichier);
}
void afficherListesAdjacences(Graphe* graphe) {
  afficherListeAdj(graphe->listeAdj);
}
void creerMatriceAdjacences(char* fullpath, Graphe* graphe) {
  int indice,x;       // Sommet origine, Sommet extrémité
  char buff[255];
  int val;            // tmp val
  int poids;          // poids de listeAdj'arête
  
  FILE* fichier; 
  fichier=fopen(fullpath,"r");

  if(fichier==NULL) {
    perror("Erreur lors de listeAdj'ouverture du fichier %s\n");  // affiche errno
    exit(EXIT_FAILURE);
  }
  else {
    fscanf(fichier,"%s", buff);
    fscanf(fichier,"%d ", &val);
    graphe->nbSommet=val;

    // On alloue le tableau 2 dimensions (matrice d'adjacence carrée) de taille (nbsommet,nbsommet)
    graphe->matrice =(int**)malloc(sizeof(int*)*val);    // Pointeur
    int i,j;
    for(i=0;i<val;++i)
      graphe->matrice[i]=(int*)malloc(sizeof(int)*val); // 1ere dimension
    for(i=0;i<val;++i) {
      for(j=0;j<val;++j)
        graphe->matrice[i][j]=0; // 2eme dimension
    }

    // On récupère la valeur qui indique si le Graphe est orienté ou pas
    fscanf(fichier,"%s %d",buff, &val);
    graphe->oriente=val;

    // On récupère la valeur qui indique si le Graphe est valué ou pa
    fscanf(fichier,"%s %d",buff, &val);
    graphe->value=val;

    // On récupère la valeur qui dit si le Graphe est complet ou pas
    fscanf(fichier,"%s %d",buff, &val);
    graphe->complet=val;

    // Récupération des arêtes
    fscanf(fichier,"%s ",buff);
      // si le Graphe n'est pas orienté
    if(graphe->oriente==1) {
      while(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
        fscanf(fichier,"%s",buff);
        if(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
            // On récupère la valeur du Sommet d'origine
            indice=atoi(buff);
            fscanf(fichier,"%s",buff);
            // On récupère la valeur du Sommet d'extrémité
            x=atoi(buff);
            fscanf(fichier,"%s",buff);
            // On récupère le poids de listeAdj'arête
            poids=atoi(buff);
            // On insère le poids à la case d'indice[s_ori][s_ext] dans le tableau (matrice d'adj~), pour indiquer le poids de listeAdj'arête
            graphe->matrice[indice][x]=poids;
        }
      }
    }
    else { // sinon le Graphe n'est orienté
      while(strcmp(buff,"finDefAretes")!=0) {   // Tant qu'on ne lit pas "finDefAretes"
        fscanf(fichier,"%s",buff);
        if(strcmp(buff,"finDefAretes")!=0) {
            // On récupère la valeur du Sommet d'origine
            indice=atoi(buff);
            fscanf(fichier,"%s",buff);
            // On récupère la valeur du Sommet d'extrémité
            x=atoi(buff);
            fscanf(fichier,"%s",buff);
            // On récupère le poids de listeAdj'arête
            poids=atoi(buff);
            // On insère le poids à la case d'indice[s_ori][s_ext] dans le tableau (matrice d'adj~), pour indiquer que le poids de listeAdj'arête
            graphe->matrice[indice][x]=poids;
            // On insère le poids à la case d'indice[s_ext][s_ori] aussi (dans le sens inverse) car un Sommet d'extrémité sera un Sommet d'origine aussi si orienté
            graphe->matrice[x][indice]=poids;
        }
      }
    }
  }
  fclose(fichier);
}
void afficherMatriceAdjacences(Graphe* graphe) {
    int i,j;
    printf("\n #################### Affichage Matrice d'adjacence #######################################");
    printf("\n ------------------------------------------------------------------------------------------\n");
        for(i=0;i<graphe->nbSommet;++i) {
            for(j=0;j<graphe->nbSommet;++j) {
                printf(" %d \t", graphe->matrice[i][j]);
            }
            printf("\n");
    }
    printf(" ------------------------------------------------------------------------------------------\n");
}
Graphe* creerGraphe(char* fullpath) {
  Graphe* g=(Graphe*)malloc(sizeof(Graphe));          // allocation du graphe
  creerListesAdjacences(fullpath, g);               // création de sa Liste d'adjacence
  creerMatriceAdjacences(fullpath,g);               // création de sa matrice d'adjacence
  return g;
}
void detruireGraphe(Graphe** graphe) {
  detruireListeAdj(&(*graphe)->listeAdj);
  int i;
  for(i=0;i<(*graphe)->nbSommet;++i) {
    free((*graphe)->matrice[i]);
  }
  free((*graphe)->matrice);
  free(*graphe);
  *graphe=NULL;
}