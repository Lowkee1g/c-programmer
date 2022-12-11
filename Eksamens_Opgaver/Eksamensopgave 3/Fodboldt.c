#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//::::::KONSTANTER:::::://

#define kampespillet 102
#define holdialt 12
#define Won 3
#define Draw 1
#define Lost 0

//::::::STRUCTS:::::://

//ugedag, dato (uden årstal), klokkeslæt, de to hold, kampens resultat og tilskuertal.
typedef struct kamp {
    char ugedag[10];
    char dato[10];
    char klokkeslaet[20];
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


//::::::FUNKTIONER:::::://

void readfile(FILE *fp, Kamp *kampe);
void printfile(Kamp *kampe);
void findhold(Kamp *kampe, Hold *hold);
void findpoints(Kamp *kampe, Hold *hold, char *holdnavne[]);
int cmpfunc(const void *a, const void *b);
void sort(hold);

//::::::MAIN:::::://

int main(void) {
    Kamp *kampe;
    Hold *hold;
    char *holdnavne[] = {"AGF","AaB","ACH","BIF","FCM","FCN","FCK","LBK","OB","RFC","SIF","VFF"};

    //Læs fil
    FILE *fp;
    fp = fopen("kampe-2022-2023.txt", "r");

    //Allocate memory
    kampe = (Kamp *)malloc(kampespillet * sizeof(Kamp));
    hold = (Hold *)malloc(holdialt * sizeof(Hold));
    
    //Read file
    readfile(fp, kampe);


    //find point
    findpoints(kampe, hold, holdnavne);

    //sort
    sort(hold);

    //print hold
    printhold(hold);
    
}


//::::::FUNKTIONER:::::://

//Funktion til at indlæse filen
void readfile(FILE *fp, Kamp *kampe) {
    //Fre     15/07 19.00     FCM - RFC     1 - 1      7359
    for (int i = 0; i < kampespillet; i++) {
        fscanf(fp, "%s %s %s %s - %s %d - %d %d", kampe[i].ugedag, kampe[i].dato, kampe[i].klokkeslaet, kampe[i].hold1, kampe[i].hold2, &kampe[i].resultat1, &kampe[i].resultat2, &kampe[i].tilskuertal);
    }
}

//Funktion til at sorte hold
void sort(Hold *hold) {
    qsort(hold, holdialt, sizeof(Hold), cmpfunc);
}

//Funktion til at printe hold score
void printhold(Hold *hold) {
    printf("|*********************************************|\n");
    printf("|     %s    VINDER LIGAEN MED %d POINT!      |\n", hold[0].holdnavn, hold[0].point);
    printf("|*********************************************|\n");
    printf("|         POINT TABLE OVER KAMPE 22-23        |\n");
    printf("|---------------------------------------------|\n");
    printf("| NAVN | POINT | MAAL AF HOLD | MAAL MOD HOLD |\n");
    printf("|      |       |              |               |\n");
    for (int i = 0; i < holdialt; i++) {
        //Hvis holdnavnet er OB eller LBK, så skal der være et ekstra mellemrum da deres score er for lav eller navn for kort
        if (strcmp(hold[i].holdnavn, "OB") == 0) {
            printf("| %s   |   %d  |      %d      |      %d       |\n", hold[i].holdnavn, hold[i].point, hold[i].maalScoret, hold[i].maalMod);
        } else if (strcmp(hold[i].holdnavn, "LBK") == 0) { 
            printf("| %s  |   %d   |      %d      |      %d       |\n", hold[i].holdnavn, hold[i].point, hold[i].maalScoret, hold[i].maalMod);
        } else {
            printf("| %s  |   %d  |      %d      |      %d       |\n", hold[i].holdnavn, hold[i].point, hold[i].maalScoret, hold[i].maalMod);
        }
    }
    printf("|---------------------------------------------|\n");

}

//Funktion til at sammenligne hold
void findpoints(Kamp *kampe, Hold *hold, char *holdnavne[]) {
    //Tilføj holdnavne til hold struct
    for (int i = 0; i < holdialt; i++) {
        strcpy(hold[i].holdnavn, holdnavne[i]);
        hold[i].point = 0;
        hold[i].maalScoret = 0;
        hold[i].maalMod = 0;
    }

    //Find point
    for (int i = 0; i < kampespillet; i++) { //Gennemløb alle kampe
        for (int j = 0; j < holdialt; j++) { //Gennemløb alle hold
            //Hvis holdnavnet matcher holdnavnet i kampe struct
            //Så skal hold struct opdateres med point, maal scoret af holdet og maal mod holdet
            if (strcmp(kampe[i].hold1, hold[j].holdnavn) == 0) { 
                hold[j].maalScoret += kampe[i].resultat1;
                hold[j].maalMod += kampe[i].resultat2;

                if (kampe[i].resultat1 > kampe[i].resultat2) {
                    hold[j].point += Won;
                } else if (kampe[i].resultat1 == kampe[i].resultat2) {
                    hold[j].point += Draw;
                } else {
                    hold[j].point += Lost;
                }
                //Det samme gælder for hold 2 i kampe struct
            } else if (strcmp(kampe[i].hold2, hold[j].holdnavn) == 0) {
                hold[j].maalScoret += kampe[i].resultat2;
                hold[j].maalMod += kampe[i].resultat1;

                if (kampe[i].resultat2 > kampe[i].resultat1) {
                    hold[j].point += Won;
                } else if (kampe[i].resultat2 == kampe[i].resultat1) {
                    hold[j].point += Draw;
                } else {
                    hold[j].point += Lost;
                }
            }
        }
    }
}


//qsort funktion til at sortere hold
int cmpfunc(const void *hold1_input, const void *hold2_input) {
    int result = 0;

    Hold *hold1 = (Hold *) hold1_input;
    Hold *hold2 = (Hold *) hold2_input;

    //Tjek om holdene har samme point og hvis de har, så skal der tjekkes på maal scoret og maal mod
    //difference mellem maal scoret og maal mod, bestemmer hvem der skal være først
    if (hold1->point == hold2->point) {
        result = ((hold2->maalScoret - hold2->maalMod) - (hold1->maalScoret - hold1->maalMod));
    } else {
        result = (hold2->point - hold1->point);
    }

    return result;
}