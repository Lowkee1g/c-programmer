#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NAME_LGT 50

typedef struct {
    char fornavn[MAX_NAME_LGT];
    char efternavn[MAX_NAME_LGT];
    char vejnavn[MAX_NAME_LGT];
    int vejnummer;
    int postnummer;
    char bynavn[MAX_NAME_LGT];
} person;

void indlaes_alle_personer(FILE *f, person persons[], int length);

int cmpfunc( const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int main(void)
{   
    person persons[11];


    FILE *f = fopen("t.txt", "r");
    if (f == NULL) {
        exit(EXIT_FAILURE);
    }

        

    indlaes_alle_personer(f, persons, 11); 

    qsort(persons->efternavn, 11, sizeof(person), cmpfunc);    

    for (int i = 0; i <= 11; i++) {
        printf("%s %s %s %d %d %s", persons[i].fornavn, persons[i].efternavn, persons[i].vejnavn, persons[i].vejnummer, persons[i].postnummer, persons[i].bynavn);
        printf("\n");
        //printf("-------------------------------------------------------------------------------------------------");
    }

    return 0;
}


void indlaes_alle_personer(FILE *f, person persons[], int length) {
    person p;
    int succes;
    for (int i = 0; i <= length; i++) {
        succes = fscanf(f, "%s %[A-Za-z], %[^0-9] %d, %d %[A-Za-z].", 
            &p.fornavn, 
            &p.efternavn, 
            &p.vejnavn, 
            &p.vejnummer, 
            &p.postnummer, 
            &p.bynavn);

        
        // if(succes != 6){
        //     printf("Crashing");
        //     break;
        // }
        persons[i] = p;
    }
}
