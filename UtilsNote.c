void askName (char name[40]) {
    printf("Tapez le prenom :\n");
    scanf(" %[^\n]", name);
}

void askNote (float *note) {
    printf("Tapez la note :\n");
    scanf("%f", note);
}

void checkAndGetBestNote (float *note, float *bestNote, char bestStudent[40], char name[40]) {
    if ((*note > *bestNote)) {
        *bestNote = *note;
        strcpy(bestStudent , name);
    } 
}

void checkAndGetWorstNote (float *note, float *worstNote, char worstStudent[40], char name[40]){
    if ((*note < *worstNote)) {
        *worstNote = *note;
        strcpy(worstStudent,name);
    }
}