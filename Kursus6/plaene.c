#include <stdio.h> 

void scale(int GPL, int GPB, int *NPL, int *NPB, int faktor);

int main(void) {
    int GPL = 5;
    int GPB = 3;
    int NPL;
    int NPB;
    int faktor = 2;

    scale( GPL, GPB, &NPL, &NPB, faktor);

    printf("Ny laengde: %d\n",NPL);
    printf("Ny bredde: %d\n", NPB);

    return 0;    
} 

void scale(int GPL, int GPB, int *NPL, int *NPB, int faktor) {
    *NPL = GPL * faktor;
    *NPB = GPB * faktor;

}
