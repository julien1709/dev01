#include "fonctions.h"

// VARIABLES
char firstName[30] = "Nobody";
int note = 0;
int sumNote = 0;

// Max 
char firstNameMaxNote[30];
int maxNote = 0;
//
// Min 
char firstNameMinNote[30];
int minNote = 21;

int nbEleves = 0;
// END VARIABLES

void askFirstName() {
    printf("Veuillez saisir un prénom --> ");
    scanf("%s", &firstName);
}

void askNote() {
    printf("Veuillez saisir votre note --> ");
    scanf("%d", &note);
    if (checkIfNoteIsOk() == 1) {
        sumNote+= note;

        if(note > maxNote) {
            strcpy(firstNameMaxNote, firstName);
            maxNote = note;
        } else if (note < minNote) {
            strcpy(firstNameMinNote, firstName);
            minNote = note;
        }
    }    
}

void askFirstNameAndNote() {
    askFirstName();
    if (isForbiddenWord() == 0) {
        askNote();
    }
}

int checkIfNoteIsOk() {
    if (note < 0 || note > 20) {
        printf("La note n'est pas valide. ");
        askNote();
        return 0;
    } else {
        nbEleves++;
        return 1;
    }
}

int isForbiddenWord() {
    if (strcmp(firstName, "X-AE-A-XII") == 0) {
        return 1;
    }
    return 0;
}

int main() {

    do {
        askFirstNameAndNote();
    } while(isForbiddenWord() != 1);

    float moyenne = getAverage(sumNote, nbEleves);

    printf("\nLa moyenne générale de la classe est : %.2f. \n", moyenne);
    printf("La meilleure note est %d, réalisé par %s. \n", maxNote, firstNameMaxNote);
    printf("La pire note est %d, elle vient de %s. \n", minNote, firstNameMinNote);

    return 0;
}