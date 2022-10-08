#include <stdio.h>

//Definere inputene
#define ROCK 'R'
#define PAPER 'P'
#define SCISSORS 'S'


int main(void)
{
    

    

    if (Spil() == 1) {
        printf("Uafgjort");
    }
    
    
    return 0;
}


int Spil(void) {
    

    char spiller1 = "";
    char spiller2 = "";


    //PLAYER INPUT HERE
    printf("Spiller 1 [R;P;S]:");
    scanf("%c", &spiller1);

    printf("\n\n\n\n\n\n\n\n\n\n\n\n");

    printf("Spiller 2 [R;P;S]:");
    scanf(" %c", &spiller2);



    //Udregner hvem der ar vundet
    if (spiller1 == ROCK) {
        if (spiller2 == SCISSORS)
        {
            printf("\n"
                "     PLAYER 1             PLAYER 2 \n"
                "    _______            _______     \n"
                "---'   ____)      ____(___    '--- \n"
                "      (_____)    (______           \n"
                "      (_____)   (_______           \n"
                "      (____)          (____)       \n"
                "---.__(___)            (___)__.--- \n"
                "                                   \n"
                "      PLAYER 1 WINS FATALITY       \n"
                "\n"
            );
        }
        else if (spiller2 == PAPER) {
            printf("\n"
                "     PLAYER 1             PLAYER 2 \n"
                "    _______            _______     \n"
                "---'   ____)      ____(___    '--- \n"
                "      (_____)    (______           \n"
                "      (_____)   (_______           \n"
                "      (____)     (________         \n"
                "---.__(___)         (_________.--- \n"
                "                                   \n"
                "          PLAYER 2 WINS            \n"
                "\n"
            );
        }
        else {
            printf("\n"
                "     PLAYER 1             PLAYER 2 \n"
                "    _______            _______     \n"
                "---'   ____)          (___    '--- \n"
                "      (_____)       (_____)        \n"
                "      (_____)       (_____)        \n"
                "      (____)         (____)        \n"
                "---.__(___)           (___)___.--- \n"
                "                                   \n"
                "              UAFGJORT             \n"
                "\n"
            );
        }
    }
    else if (spiller1 == PAPER) {
        if (spiller2 == ROCK)
        {
            printf("Spiller to taber");
        }
        else if (spiller2 == SCISSORS) {
            printf("Spiller et taber");
        }
        else {
            return 1;
        }
    }
    else if (spiller1 == SCISSORS) {
        if (spiller2 == PAPER)
        {
            printf("Spiller to taber");
        }
        else if (spiller2 == ROCK) {
            printf("Spiller et taber");
        }
        else{
            return 1;
        }
    }
    return 0;
}





