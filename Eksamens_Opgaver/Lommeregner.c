#include <stdio.h>
#include <math.h>

void scan_data(char *operator, double *operand);
void do_next_op(char operator, double operand, double *samlet);

int main(void)
{
    //https://www.moodle.aau.dk/mod/page/view.php?id=1415084
    //Variabler
    double akkumulatoren = 0, operand;
    char operator;

    do {
        scan_data(&operator, &operand);

        do_next_op(operator, operand, &akkumulatoren);
        
        if (operator == 'q'){
            break;
        }

        printf("\n%lf", akkumulatoren);
    
    } while (operator != 'q');

    printf("You have quit the program\n");
    printf("Final number is: %lf", akkumulatoren);
    
    return 0;
}





void scan_data(char *operator, double *operand) {
    printf("\nInsert a operator and an optional operand\n");
    scanf(" %c %lf", &*operator, &*operand);
    return 0;
}



void do_next_op(char operator, double operand, double *samlet) {
    switch (operator)
    {
        //Binære operatorer
    case '+':
        *samlet = *samlet + operand;
        break;

    case '-':
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