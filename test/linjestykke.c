#include <stdio.h>
#include <math.h>

int main()
{
    double punkt1_x, punkt1_y, punkt2_x, punkt2_y, punkt3_x, punkt3_y;
    int start;
    for (;;)
    {
    
        //Starter
        printf("1, til at starte - 0 for at stoppe \n");
        scanf("%i", &start);
        
        if (start == 0)
        {
            break;
        }

        //Punkt 1
        printf("Tast punkt 1, mellemrum mellem talene\n");
        scanf("%lf %lf", &punkt1_x, &punkt1_y); //Punkt 1
        printf("%lf %lf \n \n", punkt1_x, punkt1_y);


        //Punkt 2
        printf("Tast punkt 2, mellemrum mellem talene\n");
        scanf("%lf %lf", &punkt2_x, &punkt2_y); //Punkt 2
        printf("%lf %lf \n \n", punkt2_x, punkt2_y);

        //Punkt 3
        printf("Tast punkt 3, mellemrum mellem talene\n");
        scanf("%lf %lf", &punkt3_x, &punkt3_y); //Punkt 3
        printf("%lf %lf \n \n", punkt3_x, punkt3_y);

        printf("Her er laengden mellem punkt 1 og 2:");
        printf("%lf \n\n", sqrt(pow(punkt2_x-punkt1_x,2)+pow(punkt2_y-punkt1_y,2)));

        printf("Her er laengden mellem punkt 2 og 3:");
        printf("%lf \n\n", sqrt(pow(punkt3_x-punkt2_x,2)+pow(punkt3_y-punkt2_y,2)));

        printf("Her er laengden mellem punkt 3 og 1:");
        printf("%lf \n\n", sqrt(pow(punkt1_x-punkt3_x,2)+pow(punkt1_y-punkt3_y,2)));

        
        
    }
    return 0;
}
