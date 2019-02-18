#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liste_adj.h"
#include "graphe.h"

void creerListesAdjacences(char* fullpath, Graphe* graphe) {
    int s_ori,s_ext;    // sommet origine, sommet extrémité
    char buff[255];
    int val;            // tmp val

    FILE* fichier;
    fichier=fopen(fullpath,"r");

    if(fichier==NULL) {
        perror("Erreur à listeAdj'ouverture du fichier %s\n"); // affiche errno
        exit(EXIT_FAILURE);
    }
    else {
        // On récupère le nombre de sommet
        fscanf(fichier,"%s",buff);
        fscanf(fichier,"%d ",&val);
        graphe->nbSommet=val;

        // On crée la lise d'adjacence de taille nbSommet
        graphe->listeAdj = creerListeAdjacences(val);

        // On récupère la valeur qui indique si le graphe est orienté ou pas
        fscanf(fichier,"%s ",buff);
        fscanf(fichier,"%d ",&val);
        graphe->oriente=val;

        // On récupère la valeur qui indique si le graphe est valué ou pas
        fscanf(fichier,"%s ",buff);
        fscanf(fichier,"%d ",&val);
        graphe->value=val;

        // On récupère la valeur qui dit si le graphe est complet ou pas
        fscanf(fichier,"%s ",buff);
        fscanf(fichier,"%d ",&val);
        graphe->complet=val;

        // Récupération des arêtes
        fscanf(fichier,"%s ",buff);
        // si le graphe n'est pas orienté
        if(graphe->oriente==1) {
            while(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
                fscanf(fichier,"%s",buff);
                if(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
                    // On récupère la valeur du sommet d'origine
                    s_ori=atoi(buff);
                    fscanf(fichier,"%s",buff);
                    // On récupère la valeur du sommet d'extrémité
                    s_ext=atoi(buff);
                    // On insère ces 2 valeurs dans la liste d'adjacence
                    insererListeAdjacence(graphe->listeAdj, s_ori,s_ext);
                }
            }
        }
        else { // sinon le graphe est orienté
            while(strcmp(buff,"finDefAretes")!=0) {  // Tant qu'on ne lit pas "finDefAretes"
                fscanf(fichier,"%s",buff);
                if(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
                    // On récupère la valeur du sommet d'origine
                    s_ori=atoi(buff);
                    fscanf(fichier,"%s",buff);
                    // On récupère la valeur du sommet d'extrémité
                    s_ext=atoi(buff);
                    // On insère ces 2 valeurs dans la liste d'adjacence
                    insererListeAdjacence(graphe->listeAdj, s_ori,s_ext);
                    // On insère également dans le sens inverse car un sommet d'extrémité sera un sommet d'origine aussi si orienté
                    insererListeAdjacence(graphe->listeAdj,s_ext,s_ori);
                }
            }
        }

    }
    fclose(fichier);
}
void afficherListesAdjacences(Graphe* graphe) {
    afficherListeAdjacences(graphe->listeAdj);
}
void creerMatriceAdjacences(char *fullpath, Graphe *graphe) {
    int s_ori,s_ext;    // sommet origine, sommet extrémité
    char buff[255];
    int val;            // tmp val

    FILE* fichier;
    fichier=fopen(fullpath,"r");

    if(fichier==NULL) {
        perror("Erreur à l'ouverture du fichier %s\n");  // affiche errno
        exit(EXIT_FAILURE);
    }
    else{
        // On récupère le nombre de sommet
        fscanf(fichier,"%s", buff);
        fscanf(fichier,"%d ", &val);
        graphe->nbSommet=val;

        // On alloue le tableau 2 dimensions (matrice d'adjacence carrée) de taille (nbsommet,nbsommet)
        graphe->matrice =(int**)malloc(sizeof(int*)*val);    // Pointeur
        int i,j;
        for(i=0;i<val;++i) {
            graphe->matrice[i] = (int *) malloc(sizeof(int) * val); // 1ere dimension
        }
        for(i=0;i<val;++i) {
            for(j=0;j<val;++j)
                graphe->matrice[i][j]=0; // 2eme dimension
        }

        // On récupère la valeur qui indique si le graphe est orienté ou pas
        fscanf(fichier,"%s ",buff);
        fscanf(fichier,"%d ",&val);
        graphe->oriente=val;

        // On récupère la valeur qui indique si le graphe est valué ou pas
        fscanf(fichier,"%s ",buff);
        fscanf(fichier,"%d ",&val);
        graphe->value=val;

        // On récupère la valeur qui dit si le graphe est complet ou pas
        fscanf(fichier,"%s ",buff);
        fscanf(fichier,"%d ",&val);
        graphe->complet=val;

        // Récupération des arêtes
        fscanf(fichier,"%s ",buff);
        // si le graphe n'est pas orienté
        if(graphe->oriente==1) {
            while(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
                fscanf(fichier,"%s",buff);
                if(strcmp(buff,"finDefAretes")!=0) { // Tant qu'on ne lit pas "finDefAretes"
                    // On récupère la valeur du sommet d'origine
                    s_ori=atoi(buff);
                    fscanf(fichier,"%s",buff);
                    // On récupère la valeur du sommet d'extrémité
                    s_ext=atoi(buff);
                    // On insère 1 à la case d'indice[s_ori][s_ext] dans le tableau (matrice d'adj~), pour indiquer que les sommets sont liés
                    graphe->matrice[s_ori][s_ext]=1;
                }
            }
        }
        else { // sinon le graphe n'est orienté
            while(strcmp(buff,"finDefAretes")!=0) {   // Tant qu'on ne lit pas "finDefAretes"
                fscanf(fichier,"%s",buff);
                if(strcmp(buff,"finDefAretes")!=0) {  // Tant qu'on ne lit pas "finDefAretes"
                    // On récupère la valeur du sommet d'origine
                    s_ori=atoi(buff);
                    fscanf(fichier,"%s",buff);
                    // On récupère la valeur du sommet d'extrémité
                    s_ext=atoi(buff);
                    // On insère 1 à la case d'indice[s_ori][s_ext] dans le tableau (matrice d'adj~), pour indiquer que les sommets sont liés
                    graphe->matrice[s_ori][s_ext]=1;
                    // On insère 1 à la case d'indice[s_ext][s_ori] aussi (dans le sens inverse) car un sommet d'extrémité sera un sommet d'origine aussi
                    graphe->matrice[s_ext][s_ori]=1;
                }
            }
        }
    }
    fclose(fichier);
}
void afficherMatriceAdjacences(Graphe *graphe) {
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
    Graphe* graphe=(Graphe*)malloc(sizeof(Graphe));    // allocation du graphe
    creerListesAdjacences(fullpath, graphe);         // création de sa liste d'adjacence
    creerMatriceAdjacences(fullpath,graphe);         // création de sa matrice d'adjacence
    return graphe;
}
void detruireGraphe(Graphe** graphe) {
    detruireListeAdjacences(&(*graphe)->listeAdj); // libération de la liste
    int i;
    for(i=0;i<(*graphe)->nbSommet;++i) {
        free((*graphe)->matrice[i]); // libération de la 2eme dimension de la matrice
    }
    free((*graphe)->matrice); // libération de la 1ere dimension
    free(*graphe);
    *graphe=NULL;
}
