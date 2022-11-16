//https://www.moodle.aau.dk/mod/page/view.php?id=1415084
#include <stdio.h>
#include <math.h>

void scan_data(char *operator, double *operand);
void do_next_op(char operator, double operand, double *samlet);
void run_calculator(double akku, char opor);

int main(void)
{
    //Variabler
    double akkumulatoren = 0, operand;
    char operator;

    //Kører en while som kører konstant med mindre operatoren er q.
    do {
        scan_data(&operator, &operand);

        do_next_op(operator, operand, &akkumulatoren);

        run_calculator(akkumulatoren, operator);
    } while (operator != 'q');

    printf("\nYou have quit the program\n");
    printf("Final number is: %lf\n", akkumulatoren);
    
    return 0;
}



void scan_data(char *operator, double *operand) {
    //Scanner først efter operatoren
    printf("\nInsert a operator and an optional operand\n");
    //gemmer char direkte via operatoren
    scanf(" %c", &*operator);

    //Switch case som ser om den er binær eller ej
    switch (*operator) { 
        case '#':
        case '%':
        case '!':
        case 'q':
            break;
    
        //Hvis den er binær, spørger vi efter et tal 
        default:
            scanf(" %lf", &*operand);
            break;
    }
    return 0;
}



void do_next_op(char operator, double operand, double *samlet) {
    switch (operator)
    {
        //Binære operatorer
    case '+': //Plus
        *samlet = *samlet + operand;
        break;

    case '-': //minus
        *samlet = *samlet - operand;
        break;

    case '/': //Dividere
        *samlet = *samlet / operand;
        break;

    case '*': //Gange
        *samlet = *samlet * operand;
        break;

    case '^': //y i x'ne
        *samlet = pow(*samlet,2);
        break;
    
        //Unære operatorer
    
    case '#': //Kvadrat rod
        *samlet = sqrt(*samlet);
        break;

    case '%': //Flip fortegnet
        *samlet = *samlet * -1;
        break;

    case '!': // Divider 1 med x
        *samlet = 1 / *samlet;
        break;

    default:
        break;
    }
}


void run_calculator(double akku, char opor) {

    //tjekker om vi har valgt at exit programmet
    if (opor == 'q'){
        return;
    }

    //Printer resultatet
    printf("\nResult so far: %lf", akku);
}