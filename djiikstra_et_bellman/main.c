#include "bellman.h"
#include "dijkstra.h"

int main(int argc, char* argv[]) {
    if(argc != 2){
        printf("Veuillez utiliser l'executable et passer un fichier en parametre \n Executable: %s\n", argv[0]);
        exit(0);
    }
    int sommet;
    Graphe* graphe =creerGraphe(argv[1]);
    int choix = -1;
    while(choix != 0) {
        printf("\n\nEntrer 0 pour :  Quitter\nEntrer 1 pour :  Afficher l'algo de Bellman_Ford\nEntrer 2 pour :  Afficher l'algo de Dijkstra\nChoix: ");
        scanf("%d", &choix);
        switch(choix) {
            case 1:
                printf("\n#################### Bellman_Ford ########################################\n\n");
                printf("Entrez la valeur du sommet source: ");
                scanf("%d", &sommet);
                bellman(graphe, sommet);
                break;
            case 2:
                printf("\n#################### Dijkstra ########################################\n\n");
                printf("Entrez la valeur du sommet source: ");
                scanf("%d", &sommet);
                dijkstra(graphe, sommet);
                break;
        }
    }
    detruireGraphe(&graphe);
    return 0;
}