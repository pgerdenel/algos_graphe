#ifndef TP_PARCOURS_H
#define TP_PARCOURS_H

#include <stdio.h>
#include <stdlib.h>

#define BLANC 0  // sommet non découvert
#define GRIS 1	 // sommet découvert
#define NOIR 2	 // sommets découvert et traité(tous ses sommets adjacents ont été découvert)

/** fichiers file.c et file.h normalement et implémentation d'une structure de file de sommets */

/* Parcours */
typedef struct parcours {
	int sommet; 	// sommet de départ
	int couleur;	// couleur (cf #define)
	int distance;	// distance
	int pere;		// sommet père
	int debut; 		// date de début (pour le parcours en profondeur)
	int fin;		// date de fin (pour le parcours en profondeur)
} parcours;
parcours* creer_parcours(int);	// permet de creer un parcours depuis le sommet passé en paramètre


/* Cellule de file contenant un parcours */
typedef struct cellule {
	struct cellule* nxt;
	parcours* parcour;
} cellule;
cellule* creercel(parcours*); 	// creer une cellule
void detruirecel(cellule**); 	// detruit une cellule

/* File */
typedef struct file {
 	int taille;
 	cellule* tete;
 	cellule* queue;
} file;

file* creerFile(); 				//  crée une file vide de capacité maximale fixe en allouant la mémoire nécessaire
void detruireFile(file**); 		//  détruit une file en libérant ses ressources mémoire
int fileVide(file*); 			//  retourne vrai si la file est vide, faux sinon
void enfiler(file*, parcours*); //  ajoute un élément en queue de file
cellule* defiler(file*);		 	//  enlève l'élément en tête de file s'il en existe un et retourne sa valeur

#endif
