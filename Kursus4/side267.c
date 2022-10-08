#include <stdio.h>

int main(void)
{
    //Definere integer
    int n, sum;
    sum = 0;
    n = 0;

    //spørger om n
    printf("tast et tal bitch \n");
    scanf("%d", &n);

    //tæler en sum ved at bruge en for lykke
    for (int i = 0; i <= n; i++) {
        sum += i;
    }

    //Tjekker om de passer til den rigtige formle 
    if (sum == (n*(n+1))/2) {
        printf("Den er ens: %d", sum);
    } else {
        printf("den er ikke ens: %d, %d", sum, (n*(n+1))/2);
    }

    return 0;
}
