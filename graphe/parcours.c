#include "parcours.h"

/** fichiers nommés file.c et file.h normalement: implémentation d'une structure de file de sommets */

parcours* creer_parcours(int sommet) {
	parcours *p = (parcours*)malloc(sizeof(parcours));
	p->sommet=sommet;		// sommet d'origine en paramètre
	p->couleur=BLANC;	// blanc car non découvert
	p->distance=999;  	// distance infinie
	p->pere=0;			// pas de père
	return p;
}

cellule* creercel(parcours* parcour) {
	cellule* c=(cellule*)malloc(sizeof(cellule));
	c->nxt=NULL;
	c->parcour=parcour;
  return c;
}

void detruirecel(cellule** cellule) {
	free((*cellule)->parcour);
	free(*cellule);
	*cellule=NULL;
}

file* creerFile() {
	file* f=(file*)malloc(sizeof(file));
	f->tete=NULL;
	f->taille=0;
	f->queue=NULL;
	return f;
}

void detruireFile(file** fiole) {
	cellule* tmp=(*fiole)->tete;
	while(tmp!=NULL) {
		(*fiole)->tete=(*fiole)->tete->nxt;
		detruirecel(&tmp);
		tmp=(*fiole)->tete;
	}
	free((*fiole));
	(*fiole)=NULL;
}

int fileVide(file *file) {
	return file->tete==NULL;
}

void enfiler(file* file, parcours* parcour) {
	if(fileVide(file)){
		file->queue=creercel(parcour);
		file->tete=file->queue;
		file->taille++;
	}
	else {
		file->queue->nxt=creercel(parcour);
		file->queue=file->queue->nxt;
		file->taille++;
	}
}

cellule* defiler(file* file) {
	cellule* tmp=file->tete;
	if(!fileVide(file)){
		file->tete=file->tete->nxt;
		file->taille--;
	}
	return tmp;
}
