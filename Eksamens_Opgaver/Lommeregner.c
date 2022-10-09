#include <stdio.h>

void scan_data(char *operator, double *operand);

int main(void)
{
    //https://www.moodle.aau.dk/mod/page/view.php?id=1415084
    //Variabler
    double akkumulatoren, operand;
    char operator;

    scan_data(&operator, &operand);

    printf("\n%c %lf", operator, operand);
    
    return 0;
}

void scan_data(char *operator, double *operand) {
    printf("Insert a operator and an optional operand\n");
    scanf("%c %lf", &*operator, &*operand);
    return 0;
}