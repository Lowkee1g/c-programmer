#include <stdio.h>
#define true 1
#define false 0

void findLowestFive(int dice, int sizeofdice);

int main(void)
{
    int dice[] = {5,1,3,4,2};
    int sizeofdice = sizeof(dice)/sizeof(dice[0]);
    
    findLowestFive(dice, sizeofdice);

    return 0;
}


void findLowestFive(int dice, int sizeofdice) {
    int tmp = 0;
    printf("%d", sizeofdice);

    for (int i = 1; i <= 5; i++) {
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

    printf("\n%d", tmp);
}