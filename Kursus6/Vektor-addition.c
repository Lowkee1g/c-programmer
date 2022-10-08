#include <stdio.h> 

void vectorAdd(int v1, int v2, int u1, int u2, int *y1p, int *y2p);

int main(void) {
    int v1, v2, u1, u2, y1, y2;

    //Spørger efter første punkt
    printf("indtast den foerste vector (med mellemrum) \n");
    scanf("%d %d", &v1, &v2);

    //spøger efter andet punkt
    printf("indtast den anden vector (med mellemrum) \n");
    scanf("%d %d", &u1, &u2);
    
    //Sætter punkterne ind i en funktion
    vectorAdd(v1, v2, u1, u2, &y1, &y2);
    
    //Printer y vektoren
    printf("Resultatet er %d %d", y1, y2);
    
    return 0;
} 

//Funktion der tager 4 tal/2 punkter, og hvor den spørger om addressen til slutpunktet
void vectorAdd(int v1, int v2, int u1, int u2, int *y1p, int *y2p){

    //Vi udregner vektorens punkter og gemmer dem i slutpunktets addresse
    *y1p = v1 + u1;
    *y2p = v2 + u2;
}
