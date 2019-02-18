#ifndef FILE_TAB_H
#define FILE_TAB_H

#include <stdio.h>
#include <stdlib.h>

typedef struct parcours {
	int sommet;		// num du sommet
	int couleur;	// couleur si non découvert, découvert et traité(tous ses sommets ont été visité)
	int distance;	// distance
	int pere;		// père du sommet
} parcours;
typedef struct file {
	parcours **tab;	// tableau de liste
	int taille;		// taille de la liste
	int tete;
	int queue;
} file;

parcours* creerParcours_FileTab(int);
file* creerFile_FileTab(int);
void detruireFile_FileTab(file**);
int fileVide_FileTab(file*);
void enfiler_FileTab(file*, parcours*);
parcours* defiler_FileTab(file*);
int afficherFile_FileTab(file* file);

#endif
