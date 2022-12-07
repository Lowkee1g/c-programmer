#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define kampespillet 102

//ugedag, dato (uden årstal), klokkeslæt, de to hold, kampens resultat og tilskuertal.
typedef struct kamp {
    char ugedag[10];
    char dato[10];
    int klokkeslaet[10];
    char hold1[20];
    char hold2[20];
    int resultat1;
    int resultat2;
    int tilskuertal;
} Kamp;

//holdnavn, point, antal mål scoret af holdet og antal mål scoret mod holdet.
typedef struct hold {
    char holdnavn[20];
    int point;
    int maalScoret;
    int maalMod;
} Hold;


void readfile(FILE *fp, Kamp *kampe);


int main(void) {
    Kamp *kampe;
    Hold *hold;

    //Læs fil
    FILE *fp;
    fp = fopen("kampe-2022-2023.txt", "r");

    kampe = (Kamp *)malloc(kampespillet * sizeof(Kamp));
    hold = (Hold *)malloc(kampespillet * sizeof(Hold));
    
    //Read file
    readfile(fp, kampe);
    
    for (int i = 0; i < kampespillet; i++) {
        printf(fp, "%s %s %d:00 %s - %s %d - %d %d", kampe[i].ugedag, kampe[i].dato, kampe[i].klokkeslaet, kampe[i].hold1, kampe[i].hold2, kampe[i].resultat1, kampe[i].resultat2, kampe[i].tilskuertal);
    }
}

void readfile(FILE *fp, Kamp *kampe) {
    //Fre     15/07 19.00     FCM - RFC     1 - 1      7359
    for (int i = 0; i < kampespillet; i++) {
        fscanf(fp, "%s %s %d:00 %s - %s %d - %d %d", kampe[i].ugedag, kampe[i].dato, kampe[i].klokkeslaet, kampe[i].hold1, kampe[i].hold2, kampe[i].resultat1, kampe[i].resultat2, kampe[i].tilskuertal);
    }
}