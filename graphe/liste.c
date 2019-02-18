#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Liste utilisé pour les listes d'adjacence
 */

Cellule* initialiser_cellule(int val) {
    Cellule* c=(Cellule*)malloc(sizeof(Cellule));
    c->value=val;
    c->prev=NULL;
    c->nxt=NULL;
    return c;
}
void detruire_cellule(Cellule** c) {
    free(*c);
}
Liste* initialiser_liste() {
    Liste* l=(Liste*)malloc(sizeof(Liste));
    l->tete=NULL;
    return l;
}
void detruire_liste(Liste** liste) {
    Cellule* del=(*liste)->tete;
    while(del!=NULL) {
        supprimer((*liste),del);
        del=(*liste)->tete;
    }
    free(*liste);
    *liste=NULL;
    detruire_cellule(&del);
}
void inserer(Liste* liste, Cellule* cellule) {
    if(liste->tete!=NULL) {
        cellule->nxt=liste->tete;
        liste->tete->prev=cellule;
        liste->tete=cellule;
        cellule->prev=NULL;
    }
    else{
        cellule->prev=NULL;
        cellule->nxt=NULL;
        liste->tete=cellule;
    }
}
Cellule* rechercher(Liste* liste, int val) {
    Cellule*tmp=liste->tete;
    while(tmp!=NULL && tmp->value!=val) {
        tmp=tmp->nxt;
    }
    return tmp;
}
void supprimer(Liste* liste, Cellule* cellule) {
    if(cellule->prev!=NULL)
        cellule->prev->nxt=cellule->nxt;
    else
        liste->tete=cellule->nxt;
    if(cellule->nxt!=NULL)
        cellule->nxt->prev=cellule->prev;
    detruire_cellule(&cellule);
    cellule=NULL;
}
void afficher_liste(Liste* liste) {
    printf("tete ->");
    Cellule *tmp=liste->tete;
    while(tmp!=NULL) {
        printf(" %d ->",tmp->value);
        tmp=tmp->nxt;
    }
    printf("NULL");
    detruire_cellule(&tmp);
}
