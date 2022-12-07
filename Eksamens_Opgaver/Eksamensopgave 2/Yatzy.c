#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

void BlueOutputColor() {
    printf("\033[0;36m");
}
void YellowOutputColor() {
    printf("\033[0;33m");
}
void ResetOutputColor() {
    printf("\033[0m");
}

int cmpInt(const void *pa, const void *pb) {
    const int *p1 = pa;
    const int *p2 = pb;
    return *p2 - *p1; 
}

//Definere funktioner
int findFive(int **dice, int sizeofdice, char c, int *score);
void findSingler(int **dice, int sizeofdice, int *score);
int findPar(int **dice, int sizeofdice, int n, int *score);
int findHus(int **dice, int sizeofdice, int *score);
int findChance( int **dice, int sizeofdice, int *score);
int findEns(int **dice, int sizeofdice, int n, int *score);
void printScoreboard(int *score, int rounds);

int main(void)
{
    int **numbers, rounds = 15;
    int n = 0;
    int scoreboard[16];

    //Finder et random seed med time
    srand(time(NULL));

    //Spørger brugeren efter hvor mange terninger der spilles med
    printf("\n\nEnter how many dies you would like to play with (min 5): ");
    scanf("%d", &n);
    while (n < 5) {
        printf("\nPlease type in a number highere or equal to 5: ");
        scanf("%d", &n);
    }
    printf("\n");

    
    //Opretter dynamisk array med malloc
    numbers = malloc((rounds+1) * sizeof *numbers);
    for(int i = 0; i < rounds+1; i++) {
        numbers[i] = malloc(n * sizeof *numbers[i]);
    }

    //generere random terninge kast og gemmer dem i et 2d array
    roll_multiple_dies(numbers, rounds, n);    


    //Nulstiller alle tal på scoreboardet
    for (int i = 0; i < rounds+1; i++) {
        scoreboard[i] = 0;
    }



    //1-ere - 2 - 3 - 4 - 5 - 6
    findSingler(numbers, n, &scoreboard);
    
    //Tjek efter bonus
    scoreboard[6] = findBonus(scoreboard);

    //et par
    scoreboard[7] = findPar(numbers, n, 1, &scoreboard);

    //to par
    scoreboard[8] = findPar(numbers, n, 2, &scoreboard);

    //tre ens
    scoreboard[9] = findEns(numbers, n, 3, &scoreboard);

    //fire ens
    scoreboard[10] = findEns(numbers, n, 4, &scoreboard);

    //lille
    scoreboard[11] = findFive(numbers, n, 'L', &scoreboard);

    //stor
    scoreboard[12] = findFive(numbers, n, 'H', &scoreboard);

    //Fuldhus
    scoreboard[13] = findHus(numbers, n, &scoreboard);

    //Chance
    scoreboard[14] = findChance(numbers, n, &scoreboard);

    //YATZY
    scoreboard[15] = findYATZY(numbers, n, &scoreboard);

    //TOTAL
    scoreboard[16] = computeTotal(&scoreboard, rounds);

    //Print scoreboard
    printScoreboard(&scoreboard, rounds);

    
    return 0;
}

void roll_multiple_dies(int **numbers, int rounds, int terninger) {

    //Indsætter random tal i numbers
    for (int i = 0; i < rounds+1; i++) {
        for (int j = 0; j < terninger; j++) {
        numbers[i][j] = rand() % 6 + 1;
        }

        qsort(numbers[i], terninger, sizeof(int), cmpInt);
    }

    
    YellowOutputColor();
    printf("\n=======Terninger=======\n");
    ResetOutputColor();


    // Printing ROUNDS * dice matrix
    for(int i = 0; i < rounds+1; i++) { 
        printf("\n%d: ", i);
        for(int j = 0; j < terninger; j++) {
            printf("%d ", numbers[i][j]);  
        }
    }   
    printf("\n");
    

}

void findSingler(int **dice, int sizeofdice, int *score) {
    
    //Går alle ojne i gennem, og tjekker om nogen af tallene matcher
    for (int ojne = 1; ojne <= 6; ojne++) {
        int max = 0;
        int tmp = 0;
        for (int i = 0; i < sizeofdice; i++) {
            if (max != 5) {
                if (dice[ojne-1][i] == ojne) {
                    tmp += ojne;
                    max++;
                }
            }
            
        }
        score[ojne-1] = tmp;
    }
}

int findBonus(int *score) {

    //Går gennem alle single talene og ser om pointene er over eller i lig med 63, og giver en bonus på 50
    int tmp = 0;
    for (int i = 0; i < 6; i++) {
        tmp += score[i];
    }
    
    if (tmp >= 63) {
        return 50;
    }
    return 0;
}

int findPar(int **dice, int sizeofdice, int n, int *score) {
    int tmp = 0;

    //Kigger på om "i" matcher med det tal som stå direkte ved siden af.
    //Hvis det matcher, og hvis der skal ledes efter flere tal, så fortsætter den
    //med at kigge uden at indkludere det første par
    for (int i = 0; i < sizeofdice; i++) {
        if (dice[7+n-1][i] == dice[7+n-1][i+1]) {
            if (n == 0) {
                return tmp;
            }
            tmp += dice[7+n-1][i]*2;
            n--;
            i++;
        }
    }
    return 0;
}

int findEns(int **dice, int sizeofdice, int n, int *score) {
    
    //Kigger på om en terning matcher de som der kommer direkte efter, x antal gange
    for (int i = 0; i < sizeofdice; i++) {
        int tmp = n-1;
        for (int t = 0; t < n; t++) {
            
            if (tmp <= 0) {
                return dice[9+n-3][i]*n;
            }
            if (dice[9+n-3][i+t] == dice[9+n-3][i+t+1]) {
                tmp--;
            }
        }
    }
    return 0;
}

int findHus(int **dice, int sizeofdice, int *score) {
    int ens = 3;
    int foundEns = 0;
    int found[] = {0,0,0,0,0,0};
    
    //Først kigges der efter om der er 3 ens i programmet
    for (int o = 6; o > 0; o--) {
        for (int i = 0; i <= sizeofdice; i++) {
            if (dice[13][i] == o) {
                ens--;
                if (ens == 0) {
                    foundEns = dice[13][i];
                    break;
                }
            }
        }
        ens = 3;
    }

    //Herefter kigges der på om der er et par som ikke har de samme terninger som dem der er ens
    for (int o = 6; o > 0; o--) {
        for (int i = 0; i <= sizeofdice; i++) {
            if (o != foundEns) {
                if (o == dice[13][i]) {
                    found[o-1]++;
                }
                
            }

        }
    }
    for (int i = 6; i > 0; i--) {
        if (found[i-1] > 1) {
            return (i*2)+(foundEns*3);
        }
    }
    
}

int findFive(int **dice, int sizeofdice, char c, int *score) {

    int tmp = 0;
    int lowOrHigh;

    if (c == 'L') {
        lowOrHigh = 0;
    } else {
        lowOrHigh = 1;
    }

    //Først kigges der efter den mindste værdi, 1/2. Herefter går den i gennem alle terningerne og ser
    //om de resterende tal også er der
    for (int i = 1 + lowOrHigh; i <= 5 + lowOrHigh; i++) {
        int found = 0;

        for (int d = 0; d < sizeofdice; d++) {
            if (i == dice[11+lowOrHigh][d] && found == 0) {
                tmp += dice[11+lowOrHigh][d];
                found = 1;
            }
        }
    }

    //udfra om det er lille eller store tal, udskrives der point udfra dette
    if (tmp == 15 || tmp == 20) {
        return tmp;
    } else {
        return 0;
    }

}

int findChance( int **dice, int sizeofdice, int *score) {
    int n = 0;
    int chance = 0;

    //Der kigges på de højeste værdiger som er blevet slået, og hvad den værdi er. efter 5 rul, bliver det gemt
    for (int o = 6; o > 0; o--) {
        for (int i = 0; i <= sizeofdice; i++) {
            if (n == 5) {
                return chance;
            }
            if (o == dice[14][i]) {
                chance += dice[14][i];
                n++;
            }
        }
    }
}

int findYATZY(int **dice, int sizeofdice, int *score) {

    //Alle terninger bliver kigget i gennem efter om der skulle være 5 terninger som er ens
    for (int o = 6; o > 0; o--) {
        int YATZY = 0;
        for (int i = 0; i <= sizeofdice; i++) {
            if (o == dice[15][i]) {
                YATZY++;
            }
            if (YATZY >= 5) {
                return 50;
            }
        }
    }
    return 0;
}

int computeTotal(int *score, int rounds) {
    int total = 0;
    
    //Går alle værdier igennem fra scoreboardet og samler dem til et total
    for (int i = 0; i < rounds+1; i++) {
        total += score[i];
        //printf(" %d", total);
    }
    return total;
}

void printScoreboard(int *score, int rounds) {

    //Printer outputsene og tilføjere lidt farver
    char *outputs[] =  {"1-ere   :", 
                        "2-ere   :", 
                        "3-ere   :", 
                        "4-ere   :", 
                        "5-ere   :",
                        "6-ere   :",
                        "BONUS   :",
                        "Et Par  :",
                        "To Par  :",
                        "Tre ens :",
                        "Fire ens:",
                        "Lille   :",
                        "Stor    :",
                        "Fuld hus:",
                        "Chance  :",
                        "YATZY   :",
                        "TOTAL   :"};
    YellowOutputColor();
    printf("\n====YATZY====\n");
    for (int i = 0; i < rounds + 2; i++) {
        if (outputs[i] == "Et Par  :" || outputs[i] == "TOTAL   :") {
            printf("\n");
        }
        BlueOutputColor();
        printf("\n%s", outputs[i]);
        ResetOutputColor();
        printf("%d", score[i]);
    }
    ResetOutputColor();
}
