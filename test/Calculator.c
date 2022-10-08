#include <stdio.h>

int main(void)
{
    char * temp;    

    printf("WELCOME TO Mr. LOWKEES CALCULATOR \n");
    printf("What do you want to do?\n");
    scanf("&c", &temp);
    if (temp == 'help')
    {
        printf("Commands: miles_to_km");
    }
    

    return(0);
}

int miles_to_km() {
    return(0);
}