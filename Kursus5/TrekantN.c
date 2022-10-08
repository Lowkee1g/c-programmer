#include <stdio.h>
#include <math.h>

//Definere Funktionerne
double RegnAlleSider(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y);
double RegnEnSide(double p1x, double p1y, double p2x, double p2y);


//main
int main(int argc, char const *argv[])
{
    //Variabler
    double p1_x, p1_y, p2_x = 0, p2_y = 0, p3_x, p3_y, temp, temp2;
    double xStart, yStart;
    int n;
    

    //Spørger hvad brugeren vil have
    printf("hvor mange kanter har du? \n");
    scanf("%d", &n);
    
    //Hente punkterne
    printf("Angiv start punkt, adskilles med mellemrum \n");
    scanf("%lf %lf", &p1_x, &p1_y);
    xStart = p1_x;
    yStart = p1_y;



    //Kører igennem n-1 gange og beder om det næste tal
    for (int i = 0; i < n-1; i++) {
        if (i != 0) { 
            p1_x = p2_x;
            p1_y = p2_y;
        }

        printf("Angiv naeste punkt, adskilles med mellemrum \n");
        scanf("%lf %lf", &p2_x, &p2_y);

        temp += RegnEnSide(p1_x,p1_y,p2_x,p2_y);

    }

    //Regner den sidste side
    p1_x = p2_x;
    p1_y = p2_y;
    p2_x = xStart;
    p2_y = yStart;
    

    temp += RegnEnSide(p1_x,p1_y,p2_x,p2_y);


    //print resultatet af temp
    printf("her er omkredsen af figuren: %lf \n", temp);    


    return 0;
}


//Regner alle sidelængderne udfra RegnEnSide
double RegnAlleSider(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y) {

    return RegnEnSide(p1_x, p1_y, p2_x, p2_y) + RegnEnSide(p2_x, p2_y, p3_x, p3_y) + RegnEnSide(p3_x, p3_y, p1_x, p1_y);
}


//Bruger 2 punkter til at regne længden
double RegnEnSide(double p1x, double p1y, double p2x, double p2y) {

    return sqrt( pow( p2x - p1x ,2) + pow( p2y - p1y ,2));
}