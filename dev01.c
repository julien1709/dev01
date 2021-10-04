#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"

#define FORBIDDEN_NAME "X AE A-XII"

int main(int argc, char *argv[]) {

char name[40] = ""; 
int sumStudent=0;
char bestStudent[40] = "";
char worstStudent[40] = ""; 

float bestNote=0;
float worstNote=20;

float sumNote=0;

float note=0;


    while (strcmp(name,FORBIDDEN_NAME)) {

        askName(name);
        if (feof(stdin))
            break;
            // Si la chaine de caractère est identique alors on arrête la boucle et on renvoie les infos 
        if (strcmp(name,FORBIDDEN_NAME) == 0)
            break;

        askNote(&note);
        if (feof(stdin)) {
            break;
        }
        
        if ((note<=20)&&(note>=0)) {
            checkAndGetBestNote(&note, &bestNote, bestStudent, name);
            checkAndGetWorstNote(&note, &worstNote, worstStudent, name);
            sumStudent++;
            sumNote += note;
        } else {
            printf("La note n\'est pas comprise entre 0 et 20. \n");
        }
    }
        printf("\n La meilleure note est : %.2f obtenue par : %s\n",bestNote,bestStudent);
        printf("La pire note est : %.2f obtenue par : %s\n",worstNote,worstStudent);
        printf("La moyenne de la classe est : %.2f\n",sumNote/sumStudent);
}  