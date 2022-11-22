#include <stdio.h>
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
void Debug(char s[100]) {
    printf("\033[0;35m");
    printf("     %c <%s>",175,s);
    ResetOutputColor();
}

int findFive(int *dice, int sizeofdice, char c, int *score);
void findSingler(int *dice, int sizeofdice, int *score);
int findPar(int *dice, int sizeofdice, int n, int *score);
int findHus(int *dice, int sizeofdice, int *score);
int findChance( int *dice, int sizeofdice, int *score);
int findEns(int *dice, int sizeofdice, int n, int *score);
void printScoreboard(int *score);

int main(void)
{
    int dice[] = {6,6,3,6,6,4,3,2,4,5,6,1,5};
    int scoreboard[17];
    int sizeofdice = sizeof(dice)/sizeof(dice[0]);
    
    //1-ere - 2 - 3 - 4 - 5 - 6
    findSingler(&dice, sizeofdice, &scoreboard);
    

    //et par
    scoreboard[7] = findPar(&dice, sizeofdice, 1, &scoreboard);

    //to par
    scoreboard[8] = findPar(&dice, sizeofdice, 2, &scoreboard);


    //tre ens
    scoreboard[9] = findEns(&dice, sizeofdice, 3, &scoreboard);

    //fire ens
    scoreboard[10] = findEns(&dice, sizeofdice, 4, &scoreboard);

    //lille
    scoreboard[11] = findFive(&dice, sizeofdice, 'L', &scoreboard);

    //stor
    scoreboard[12] = findFive(&dice, sizeofdice, 'H', &scoreboard);

    //Fuldhus
    scoreboard[13] = findHus(&dice, sizeofdice, &scoreboard);

    //Chance
    scoreboard[14] = findChance(&dice, sizeofdice, &scoreboard);

    //YATZY
    scoreboard[15] = findYATZY(&dice, sizeofdice, &scoreboard);

    //Print scoreboard
    printScoreboard(&scoreboard);

    /*
    for (int i = 0; i < 16; i++) {
        printf("\n%d | %d", i , scoreboard[i]);
    }
    */
    return 0;
}


void findSingler(int *dice, int sizeofdice, int *score) {
    for (int ojne = 1; ojne <= 6; ojne++) {
        int tmp = 0;
        for (int i = 0; i < sizeofdice; i++) {
            if (dice[i] == ojne) {
                tmp += ojne;
            }
            
        }
    score[ojne-1] = tmp;
    printf("\n%d-ere: %d",ojne, tmp);
    }
}


int findPar(int *dice, int sizeofdice, int n, int *score) {
    int tmp;
    int found[] = {0,0,0,0,0,0};
    for (int o = 1; o <= 6; o++) {
        for (int i = 0; i < sizeofdice; i++) {
            if (o == dice[i]) {
                found[o-1]++;
            }
        }
    }
    
    for (int i = 6; i > 0; i--) {
        if (found[i-1] > 1) {
            n--;
            tmp = i+i;
            if (n == 0) {
                printf("\n %d Par: %d",i , i+i);
                return i+i;
            }
        }
    }
    
}

int findEns(int *dice, int sizeofdice, int n, int *score) {
    int tmp = n;
    for (int o = 6; o > 0; o--) {
        for (int i = 0; i <= sizeofdice; i++) {
            if (dice[i] == o) {
                tmp--;
                if (tmp == 0) {
                    printf("\n%d ens: %d", n, o*n);
                    return o*n;
                }
            }
        }
        tmp = n;
    }
    printf("\n%d ens: %d", n, 0);
}

int findHus(int *dice, int sizeofdice, int *score) {
    int ens = 3;
    int foundEns = 0;
    int found[] = {0,0,0,0,0,0};
    
    for (int o = 6; o > 0; o--) {
        for (int i = 0; i <= sizeofdice; i++) {
            if (dice[i] == o) {
                ens--;
                if (ens == 0) {
                    foundEns = dice[i];
                    break;
                }
            }
        }
        ens = 3;
    }
    for (int o = 6; o > 0; o--) {
        for (int i = 0; i <= sizeofdice; i++) {
            if (o != foundEns) {
                if (o == dice[i]) {
                    found[o-1]++;
                }
            }

        }
    }
    for (int i = 6; i > 0; i--) {
        if (found[i-1] > 1) {
            printf("\nFuldHus: %d", (i*2)+(foundEns*3));
            return (i*2)+(foundEns*3);
        }
    }
    
}


int findFive(int *dice, int sizeofdice, char c, int *score) {

    int tmp = 0;
    printf("\n%d", sizeofdice);
    int lowOrHigh;

    if (c == 'L') {
        lowOrHigh = 0;
    } else {
        lowOrHigh = 1;
    }


    for (int i = 1 + lowOrHigh; i <= 5 + lowOrHigh; i++) {
        printf("\n%d || ", i);
        int found = 0;
        
        for (int d = 0; d < sizeofdice; d++) {
            if (i == dice[d] && found == 0) {
                tmp += dice[d];
                found = 1;
                printf("(%d)", dice[d]);
            } else {
                printf("%d", dice[d]);
            }
            
        }
    }
    if (tmp == 15 || tmp == 20) {
        printf("\nLave tal: %d", tmp);
        return tmp;
    } else {
        printf("\nLave tal: %d", 0);
        return 0;
    }

}

int findChance( int *dice, int sizeofdice, int *score) {
    int n = 0;
    int chance = 0;
    for (int o = 6; o > 0; o--) {
        for (int i = 0; i <= sizeofdice; i++) {
            if (n == 6) {
                printf("\nChance: %d", chance);
                return chance;
            }
            if (o == dice[i]) {
                chance += dice[i];
                n++;
            }
        }
    }
}

int findYATZY(int *dice, int sizeofdice, int *score) {
    for (int o = 6; o > 0; o--) {
        int YATZY = 0;
        for (int i = 0; i <= sizeofdice; i++) {
            if (o == dice[i]) {
                YATZY++;
            }
            if (YATZY == 5) {
                printf("\n YATZY: %d", 50);
                return 50;
            }
        }
    }
    printf("\nYATZY: %d", 0);
    return 0;
}

void printScoreboard(int *score) {
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
    printf("\n=YATZY=\n");
    for (int i = 0; i < 14; i++) {
        BlueOutputColor();
        printf("\n%s", outputs[i]);
        ResetOutputColor();
        printf(" %d", score[i]);
    }
    ResetOutputColor();
}