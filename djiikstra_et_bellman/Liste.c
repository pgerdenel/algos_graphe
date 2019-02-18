#include "Liste.h"
#include <stdio.h>

Cellule* creerCellule(int val, int poids) {
	Cellule* c=(Cellule*)malloc(sizeof(Cellule));
	c->value=val;
  c->poids=poids;
	c->prev=NULL;
	c->nxt=NULL;
	return c;
}
void detruireCellule(Cellule** c) {
	free(*c);
	c=NULL;
}
Liste* creerListe() {
	Liste* l=(Liste*)malloc(sizeof(Liste));
	l->tete=NULL;
	return l;
}
void detruireListe(Liste** liste) {
	Cellule* del=(*liste)->tete;
	while(del!=NULL){
		supprimer((*liste),del);
		del=(*liste)->tete;
	}
	free(*liste);
	*liste=NULL;
	detruireCellule(&del);
}
void inserer(Liste* liste, Cellule* c) {
	if(liste->tete!=NULL){
		c->nxt=liste->tete;
		liste->tete->prev=c;
		liste->tete=c;
		c->prev=NULL;
	}
	else{
		c->prev=NULL;
		c->nxt=NULL;
		liste->tete=c;
	}
}
void supprimer(Liste* liste, Cellule* c) {
	if(c->prev!=NULL)
		c->prev->nxt=c->nxt;
	else
		liste->tete=c->nxt;
	if(c->nxt!=NULL)
		c->nxt->prev=c->prev;
	detruireCellule(&c);
	c=NULL;
}
int compteListe(Liste* liste) {
  Cellule *tmp=liste->tete;
  int nbMot=0;
   while(tmp!=NULL){
    ++nbMot;
    tmp=tmp->nxt;
  }
  return nbMot;
}
