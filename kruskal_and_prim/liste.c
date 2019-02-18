#include "liste.h"
#include <stdio.h>

Cellule* creerCellule(int x, int p) {
	Cellule* c=(Cellule*)malloc(sizeof(Cellule));
	c->value=x;
  	c->poids=p;
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

void detruireListe(Liste**l) {
	Cellule* del=(*l)->tete;
	while(del!=NULL) {
		supprimer((*l),del);
		del=(*l)->tete;
	}
	free(*l);
	*l=NULL;
	detruireCellule(&del);
}

void inserer(Liste* l,Cellule* c) {
	if(l->tete!=NULL) {
		c->nxt=l->tete;
		l->tete->prev=c;
		l->tete=c;
		c->prev=NULL;
	}
	else{
		c->prev=NULL;
		c->nxt=NULL;
		l->tete=c;
	}
}

Cellule* rechercher(Liste* l, int x) {
	Cellule*tmp=l->tete;
	while(tmp!=NULL && tmp->value!=x) {
		tmp=tmp->nxt;
	}
	return tmp;
}

void supprimer(Liste* l,Cellule* c) {
	if(c->prev!=NULL)
		c->prev->nxt=c->nxt;
	else
		l->tete=c->nxt;
	if(c->nxt!=NULL)
		c->nxt->prev=c->prev;
	detruireCellule(&c);
	c=NULL;
}


void afficherListe(Liste* l) {
	printf("listeAdj.tete ->");
	Cellule *tmp=l->tete;
	while(tmp!=NULL) {
		printf(" %d (%d) ->",tmp->value, tmp->poids);
		tmp=tmp->nxt;
	}
	printf("c'est NULLLLLLE");
	detruireCellule(&tmp);
}

int compteListe(Liste* l) {
  Cellule *tmp=l->tete;
  int nbMot=0;
   while(tmp!=NULL) {
    ++nbMot;
    tmp=tmp->nxt;
  }
  return nbMot;
}
