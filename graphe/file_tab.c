#include <stdlib.h>
#include "file_tab.h"

#define BLANC 0

parcours* creerParcours_FileTab(int sommet) {
    parcours* p=(parcours*)malloc(sizeof(parcours));
	p->sommet =sommet;
	p->couleur=BLANC;   // blanc car non découvert
	p->distance=0;      // distance

	return p;
}
file* creerFile_FileTab(int taille) {
    file* f = (file*)malloc(sizeof(file));
    f->taille = taille;
    f->tab = (parcours**)malloc(sizeof(parcours*)*f->taille);

    for(int i=0;i<f->taille;i++) {
        f->tab[i] = NULL;
        f->tete = 0;
        f->queue = 0;
    }
return f;
}
void detruireFile_FileTab(file** file) {
	free((*file)->tab);
	free(*file);
	*file=NULL;
}
int fileVide_FileTab(file* file) { // 1 vide
	if(file->tete == file->queue && file->tab[file->queue] == NULL) {
        return 1;
    }
	else {
        return 0;
    }
}
void enfiler_FileTab(file* file, parcours* p) {
    if(fileVide_FileTab(file)==1 || file->queue != file->tete) {
        file->tab[file->queue] = p;
        if(file->queue < file->taille-1) {
            file->queue++;
        }
        else {
            file->queue = 0;
        }
    }
    else {
        printf("erreur la file est pleine\n");
    }
}
parcours* defiler_FileTab(file *file) {
  parcours *p=NULL;
  if(fileVide_FileTab(file)==0) {
    p = file->tab[file->tete];
    file->tab[file->tete]=NULL;
    if(file->tete == file->taille-1) {
        file->tete = 0;
    }
    else {
        file->tete++;
    }
  }
  return p;
}
int afficherFile_FileTab(file* file) {
  if(fileVide_FileTab(file)==0) {
    for(int i=0;i<file->taille;i++) {
        if(file->tab[i] != NULL)
        printf("Sommet: %d\n", file->tab[i]->sommet);
    }
  }
return 0;
}
