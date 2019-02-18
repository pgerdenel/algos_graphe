#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "outils_graphe.h"

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Veuillez utiliser l'executable et passer un fichier en paramètre \n Executable: %s\n", argv[0]);
        exit(0);
    }

    Graphe* g = creerGraphe(argv[1]);
    parcours **p_Largeur1 = parcoursLargeur(g, 0);
    parcours **p_ProfondeurRecurif = parcourProfondeurRecurif(g, 0);

    int choice = -1;
    while(choice != 0) {
        printf("\n\nEntrer 0 pour : Quitter\nEntrer 1 pour : Afficher listes d'adjacences et matrice d'adjacences\nEntrer 2 pour : Afficher parcours en Largeur de 0 a n\nEntrer 3 pour : Afficher parcours profondeur\nNumero choisi : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                afficherListesAdjacences(g);
                afficherMatriceAdjacences(g);
                break;
            case 2:
                printf("\n#################### Parcours en largeur de 0 a n ########################################\n\n");
                int sommet;
                // le sommet doit exister
                do {
                    printf("Entrez la valeur du sommet : ");
                    scanf(" %d", &sommet);
                } while (sommet < 0 || sommet > 11);
                afficherChemin(p_Largeur1, 0, sommet);
                break;
            case 3:
                afficherProfondeur(p_ProfondeurRecurif, g->nbSommet);
                break;
        }
    }

    // Libération mémoire
    for(int i=0;i<g->nbSommet;++i) {
        free(p_Largeur1[i]);
        free(p_ProfondeurRecurif[i]);
    }
    free(p_Largeur1);
    free(p_ProfondeurRecurif);
    detruireGraphe(&g);

    return 0;
}
