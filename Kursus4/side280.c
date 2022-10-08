

#include <stdio.h>

int main(void)
{
    int people = 9870;
    int increase = 10;
    int countYears = 0;

    while (people <= 30000)
    {
        people += people/100*increase;
        countYears++;
    }
    printf("Years to naa: %d, population: %d", countYears, people);

    return 0;
}
