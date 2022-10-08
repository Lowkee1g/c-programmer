#include <stdio.h>

int main(void)
{
    int n;

    printf("indsæt et tal\n");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        
        for (int j = 0; j <= n-i; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    /*
    for (int i = 0; i <= n; i++)
    {
        for (int j = n-1; j >= 0; j--)
        {
            printf("%d ", j);
            
        }
        printf("\n");
    }
    */
    return 0;
}
