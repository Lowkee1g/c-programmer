#include <stdio.h>
#include <math.h>

//Definere Funktionerne
double RegnAlleSider(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y);
double RegnEnSide(double p1x, double p1y, double p2x, double p2y);


//main
int main(int argc, char const *argv[])
{
    //Variabler
    double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, temp, temp2;
    int n;
    
    //Again
    Again:

    //Spørger hvad brugeren vil have
    //0 alle siderne - 1 første side - 2 anden - 3 tredje
    printf("hvor mange kanter har du? \n");
    scanf("%lf", &n);
    
    //Hente punkterne
    printf("Angiv 3 kordinattor, adskilles med mellemrum \n");
    scanf("%lf %lf %lf %lf %lf %lf", &p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y);


    //Regn side længderne og gemmer i temp, for mere overblik
    temp = RegnAlleSider(p1_x,p1_y,p2_x,p2_y,p3_x,p3_y);

    //print resultatet af temp
    printf("her er omkredsen af figuren: %lf", temp);
    


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