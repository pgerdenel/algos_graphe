#include <stdlib.h>
#include "outils_graphe.h"

parcours** parcoursLargeur(Graphe *graphe, int sommet) {
    int i;
    cellule* u;     // cellule de parcours de file
    Cellule* tmp;   // cellule de liste
    parcours** parcours_tab = (parcours**)malloc(sizeof(parcours*)*graphe->nbSommet); // tableau de struct_parcours de taille du nombre sommet

    // initialisation de chaque sommet
    for(i=0;i<graphe->nbSommet;++i) {
        parcours_tab[i]= creer_parcours(i);
    }
    // affectation du sommet source (on commence par lui donc il est découvert)
    parcours_tab[sommet]->distance=0;
    parcours_tab[sommet]->pere=-1;
    parcours_tab[sommet]->couleur=GRIS; // sommet en cours de traitement
    
    // On crée la file
    file *f=creerFile();
    enfiler(f,parcours_tab[sommet]); // enfile le parcours du sommet racine
    while(!fileVide(f)) { // tant que la file n'est pas vide
        u = defiler(f); // on récupère la cellule en tête de file
        // on récupère la cellule de tête de la liste d'indice[sommet du parcours de la cellule de tête(de file) récupéré précédement] présent dans le tableau de la liste d'adjacence du graphe
        tmp = graphe->listeAdj->tab_list[u->parcour->sommet]->tete;
        while(tmp!=NULL) {  //  tant qu'il n'est pas nul
            if( parcours_tab[tmp->value]->couleur==BLANC) { // si sommet non découvert

                parcours_tab[tmp->value]->couleur=GRIS; // sommet devient découvert
                parcours_tab[tmp->value]->distance=parcours_tab[u->parcour->sommet]->distance +1; // distance incrémenté de +1
                parcours_tab[tmp->value]->pere=u->parcour->sommet;  // son père devient le sommet de la cellule défilé précédement
                enfiler(f,parcours_tab[tmp->value]); // on enfile le parcours de ce sommet
            }
            tmp=tmp->nxt;   // on passe au sommet de la cellule suivante
        }
        parcours_tab[u->parcour->couleur]->couleur=NOIR; // on met les sommets dont ses sommets adjacents ont tous été découvert en NOIR
        free(u);
    }
    free(tmp);
    detruireFile(&f);

    return parcours_tab;
}

void afficherChemin(parcours** parcour, int s1, int s2) {
    if(s1==s2) { // si c'est le m sommet
        printf("%d ",s1);
    }
    else {
        // si s2 n'a pas de père
        if((parcour[s2]->pere) == -1) {
            printf("pas de  chemin de s1 à s2");
            return;
        }
        else { // sinon s2 a un père
            afficherChemin(parcour,s1,parcour[s2]->pere); // affiche le père en apel récursif
            printf("-> %d ",s2);
        }
    }
}

parcours** parcourProfondeurRecurif(Graphe *graphe, int sommet) {
    int *date = (int *)(malloc(sizeof(int)));
    *date=1; // création de la date de début valant 1
    int i,j;
    parcours** parcours_tab=(parcours**)malloc(sizeof(parcours*)*graphe->nbSommet); // tableau de struct_parcours de taille du nombre sommet

    // initialisation de chaque sommet
    for(i=0;i<graphe->nbSommet;++i) {
        parcours_tab[i]= creer_parcours(i);
    }
    // affectation du sommet source (on commence par lui donc il est découvert)
    parcours_tab[sommet]->distance=0;
    parcours_tab[sommet]->pere=sommet;
    parcours_tab[sommet]->couleur=GRIS;
    parcours_tab[sommet]->debut=*date; // compteur date de début=X et date de fin=X+1

    // On parcours chaque sommet
    for(i=sommet,j=0; j<graphe->nbSommet; ++j, ++i) {
        if(i==graphe->nbSommet)
            i=0;
        if(parcours_tab[i]->couleur == BLANC)                   // si le sommet n'est pas découvert
            visiter_PP(graphe,parcours_tab[i],date,parcours_tab);    // on le visite
    }
    parcours_tab[sommet]->fin=*date+1; // le sommet et ses sommets adjacents sont traités donc la date de fin est incrémentée

    return parcours_tab;
}

void visiter_PP(Graphe *graphe, parcours *parcours_sommet, int *date_debut, parcours **parcours_tab) {
    *date_debut = *date_debut + 1;
    parcours_sommet->debut = *date_debut;
    parcours_sommet->couleur = GRIS; // le sommet est découvert
    Cellule *tmp; // cellule de liste d'adjacence
    // on récupère la cellule de tête de liste de la liste d'adjacence du sommet visité
    tmp=graphe->listeAdj->tab_list[parcours_sommet->sommet]->tete;
    while(tmp != NULL) { // tant que la celulle(sommet) suivant n'est pas nul
        if(parcours_tab[tmp->value]->couleur == BLANC) { // si le sommet n'est pas découvert
            parcours_tab[tmp->value]->pere = parcours_sommet->sommet; // on met à jour le père
            visiter_PP(graphe,parcours_tab[tmp->value],date_debut,parcours_tab); // on visite récursivement ce sommet de la liste
        }
        tmp = tmp->nxt; // on passe au sommet suivant de la liste
    }
    parcours_sommet->couleur = NOIR;    // le sommet est maintenant traité
    *date_debut = *date_debut +1;                   // on incrémente sa date_debut
    parcours_sommet->fin = *date_debut;       // on l'assigne en temps que date_debut de fin
}

void afficherProfondeur(parcours** parcour, int taille) {
    int i;
    printf("\n#################### Parcours en profondeur ############################################\n\n");
    printf("----------------------------\n");
    printf("Sommet\tPere\tDebut\tFin\n");
    printf("----------------------------\n");
    for(i=0;i<taille; ++i) {
        printf("%2d\t %2d\t %2d\t %2d\n", parcour[i]->sommet, parcour[i]->pere, parcour[i]->debut, parcour[i]->fin);
    }
    printf("----------------------------\n");
}
