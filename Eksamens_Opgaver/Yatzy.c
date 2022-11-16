#include <stdio.h>




int main(void)
{
    int dice[] = {5,1,2,3,4};
    int sizeofdice = sizeof(dice)/sizeof(dice[0]);
    int tmp = 0;





    for (int i = 0; i <= 5; i++) {
        printf("\n%d || ", i);
        for (int d = 0; d < sizeofdice+1; d++) {
            if (i == d) {
                tmp += d;
                printf("%d", d);
            }
        }
    }

    printf("\n%d", tmp);


    return 0;
}
