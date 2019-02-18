#include "graphe.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "liste_adj.h"

void creerListesAdjacences(char* fullpath, Graphe* graphe){
 	int indice,x;
 	char buff[255];
  int val;
  int poids;
  
  FILE* fichier; 
 	fichier=fopen(fullpath,"r");

 	if(fichier==NULL){
 	 	perror("Erreur lors de l'ouverture du fichier %s\n");
   	exit(EXIT_FAILURE);
 	}
 	else{
    fscanf(fichier,"%s",buff);
    fscanf(fichier,"%d ",&val);
    graphe->nbSommet=val;

    graphe->l = creerListeAdj(val);
  
    fscanf(fichier,"%s ",buff);
    fscanf(fichier,"%d ",&val);
    graphe->oriente=val;
 
    fscanf(fichier,"%s ",buff);
    fscanf(fichier,"%d ",&val);
    graphe->value=val;
 
    fscanf(fichier,"%s ",buff);
    fscanf(fichier,"%d ",&val);
    graphe->complet=val;

    fscanf(fichier,"%s ",buff);
    if(graphe->oriente==1){
      while(strcmp(buff,"finDefAretes")!=0){
        fscanf(fichier,"%s",buff);
        if(strcmp(buff,"finDefAretes")!=0){
          indice=atoi(buff);
          fscanf(fichier,"%s",buff);
          x=atoi(buff);
          fscanf(fichier,"%s",buff);
          poids=atoi(buff);
          insererListeAdj(graphe->l, indice,x, poids);
        }
      }
    }else{
      while(strcmp(buff,"finDefAretes")!=0){
        fscanf(fichier,"%s",buff);
        if(strcmp(buff,"finDefAretes")!=0){
          indice=atoi(buff);
          fscanf(fichier,"%s",buff);
          x=atoi(buff);
          fscanf(fichier,"%s",buff);
          poids=atoi(buff);
          insererListeAdj(graphe->l, indice,x, poids);
          insererListeAdj(graphe->l,x,indice, poids);
        }
      }
    }

  }
 	fclose(fichier);
}
void creerMatriceAdjacences(char* fullpath, Graphe* graphe){
  int indice,x;
  char buff[255];
  int val;
  int poids;
  
  FILE* fichier; 
  fichier=fopen(fullpath,"r");

  if(fichier==NULL){
    perror("Erreur lors de l'ouverture du fichier %s\n");
    exit(EXIT_FAILURE);
  }
  else{
    fscanf(fichier,"%s %d",buff, &val);
    graphe->nbSommet=val;

    graphe->matrice =(int**)malloc(sizeof(int*)*val);
    int i,j;
    for(i=0;i<val;++i)
      graphe->matrice[i]=(int*)malloc(sizeof(int)*val);
    for(i=0;i<val;++i){
      for(j=0;j<val;++j)
        graphe->matrice[i][j]=0;
    }

    
    fscanf(fichier,"%s %d",buff, &val);
    graphe->oriente=val;
 
    fscanf(fichier,"%s %d",buff, &val);
    graphe->value=val;
 
    fscanf(fichier,"%s %d",buff, &val);
    graphe->complet=val;

    fscanf(fichier,"%s ",buff);
    if(graphe->oriente==1){
      while(strcmp(buff,"finDefAretes")!=0){
        fscanf(fichier,"%s",buff);
        if(strcmp(buff,"finDefAretes")!=0){
          indice=atoi(buff);
          fscanf(fichier,"%s",buff);
          x=atoi(buff);
          fscanf(fichier,"%s",buff);
          poids=atoi(buff);
          graphe->matrice[indice][x]=poids;
        }
      }
    }else{
      while(strcmp(buff,"finDefAretes")!=0){
        fscanf(fichier,"%s",buff);
        if(strcmp(buff,"finDefAretes")!=0){
          indice=atoi(buff);
          fscanf(fichier,"%s",buff);
          x=atoi(buff);
          fscanf(fichier,"%s",buff);
          poids=atoi(buff);
          graphe->matrice[indice][x]=poids;
          graphe->matrice[x][indice]=poids;
        }
      }
    }
  }
  fclose(fichier);
}
Graphe* creerGraphe(char* fullpath){
  Graphe* g=(Graphe*)malloc(sizeof(Graphe));
  creerListesAdjacences(fullpath, g);
  creerMatriceAdjacences(fullpath,g);
  return g;
}
void detruireGraphe(Graphe** graphe){
  detruireListeAdj(&(*graphe)->l);
  int i;
  for(i=0;i<(*graphe)->nbSommet;++i){
    free((*graphe)->matrice[i]);
  }
  free((*graphe)->matrice);
  free(*graphe);
  *graphe=NULL;
}
