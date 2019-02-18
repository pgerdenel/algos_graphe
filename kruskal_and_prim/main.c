#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphe.h"
#include "liste.h"
#include "Ensemble.h"
#include "kruskal.h"
#include "prim.h"

int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("Veuillez utiliser l'executable et passer un fichier en paramètre \n Executable: %s\n", argv[0]);
        exit(0);
    }

    Graphe* graphe = creerGraphe(argv[1]);

    int choice = -1;
    while(choice != 0) {
        printf("\n\nEntrer 0 pour : Quitter\nEntrer 1 pour : Afficher l'algo de Kruskal\nEntrer 2 pour : Afficher l'algo de PRIM\nChoix: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\n#################### Kruskal ########################################\n");
                genererAcpmKruskal(graphe);
                break;
            case 2:
                printf("\n#################### Prim ########################################\n");
                genererAcpmPrim(graphe,0);
                break;
        }
    }

    detruireGraphe(&graphe);

    return 0;

}
