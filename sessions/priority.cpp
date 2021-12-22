#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[255];
    int priority;
    Patient *left, *right;
} *first, *last;

Patient *createPatient(const char *name, int priority){
    Patient *newPatient = (Patient*)malloc(sizeof(Patient));
    strcpy(newPatient->name, name);
    newPatient->priority = priority;
    newPatient->left = newPatient->right = NULL;
    return newPatient;
}

void viewQueue(){
    Patient *currentPatient = first;

    while(currentPatient) {
        printf("%s (%d) -> ", currentPatient->name, currentPatient->priority);
        currentPatient = currentPatient->right;
    }

    puts("NULL");
}

void pushPriority(const char *name, int priority){
    Patient *newPatient = createPatient(name, priority);

    if(!first){ // if LL is empty
        first = last = newPatient;
    }
    else if(newPatient->priority > first->priority){ // If priority is greater than first patient
        newPatient->right = first;
        first->left = newPatient;
    }
    else if(newPatient->priority < last->priority){// if priority is lower than last patient
        last->right = newPatient;
        newPatient->left = last;
        last = newPatient;
    }
    else{
        Patient *currentPatient = first;

        while(currentPatient->priority > priority){ // if new patient's priority is lower than current patient's priority
            currentPatient = currentPatient->right; // keep going to the right (lower priority)
        }
        newPatient->right = currentPatient;
        newPatient->left = currentPatient->left;
        currentPatient->left->right = newPatient;
        currentPatient->left = newPatient;
    }
    viewQueue();
}


int main(){
    pushPriority("Andrew", 95);
    pushPriority("Dody", 70);
    pushPriority("Cecep", 85);
    pushPriority("Benny", 98);
    pushPriority("Arvyn", 97);
    pushPriority("Felix", 80);
    return 0;
}