#include <stdio.h>
#include <math.h>

void scan_data(char *operator, double *operand);
void do_next_op(char operator, double operand, double *samlet);
void run_calculator(double akku, char opor);

int main(void)
{
    //https://www.moodle.aau.dk/mod/page/view.php?id=1415084
    //Variabler
    double akkumulatoren = 0, operand;
    char operator;

    do {
        scan_data(&operator, &operand);

        do_next_op(operator, operand, &akkumulatoren);

        run_calculator(akkumulatoren, operator);
    
    } while (operator != 'q');

    printf("You have quit the program\n");
    printf("Final number is: %lf", akkumulatoren);
    
    return 0;
}


void run_calculator(double akku, char opor) {
        if (opor == 'q'){
            return;
        }

        printf("\n%lf", akku);
}


void scan_data(char *operator, double *operand) {
    printf("\nInsert a operator and an optional operand\n");
    scanf(" %c", &*operator);
    switch (*operator) {
        case '#':
            break;
        case '%':
            break;
        case '!':
            break;
        case 'q':
            break;
    
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

    case '/':
        *samlet = *samlet / operand;
        break;

    case '*':
        *samlet = *samlet * operand;
        break;

    case '^':
        *samlet = pow(*samlet,2);
        break;
    
        //Unære operatorer
    
    case '#':
        *samlet = sqrt(*samlet);
        break;

    case '%':
        *samlet = *samlet * -1;
        break;

    case '!':
        *samlet = 1 / *samlet;
        break;

    case 'q':
        
        break;

    default:
        break;
    }
}