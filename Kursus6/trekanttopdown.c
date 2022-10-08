#include <stdio.h>
#include <math.h>

//Definere Funktionerne
double RegnAlleSider(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y, double *side1, double *side2, double *side3);
double RegnEnSide(double p1x, double p1y, double p2x, double p2y);
void get_input(double *p1_x, double *p1_y, double *p2_x, double *p2_y, double *p3_x, double *p3_y);


//main
int main(void)
{
    //Variabler
    double p1_x, p1_y, p2_x, p2_y, p3_x, p3_y, temp;
    double side1, side2, side3;
    
    get_input(&p1_x, &p1_y, &p2_x, &p2_y, &p3_x, &p3_y);


    //Regn side længderne og gemmer i temp, for mere overblik
    temp = RegnAlleSider(p1_x,p1_y,p2_x,p2_y,p3_x,p3_y, &side1, &side2, &side3);
    

    printf("her er omkredsen af figuren: %lf \n", temp);
    
    //print resultatet af temp
    printf("Her er side 1: %lf\n", side1);
    printf("Her er side 2: %lf\n", side2);
    printf("Her er side 3: %lf\n", side3);


    return 0;
}

void get_input(double *p1_x, double *p1_y, double *p2_x, double *p2_y, double *p3_x, double *p3_y) {
    //Spørger hvad brugeren vil have
    //Hente punkterne
    printf("Angiv 3 kordinattor, adskilles med mellemrum og , (x,y x,y x,y) \n");
    scanf("%lf,%lf %lf,%lf %lf,%lf", p1_x, p1_y, p2_x, p2_y, p3_x, p3_y);
}


//Regner alle sidelængderne udfra RegnEnSide
double RegnAlleSider(double p1_x, double p1_y, double p2_x, double p2_y, double p3_x, double p3_y, 
                     double *side1, double *side2, double *side3) {

    *side1 = RegnEnSide(p1_x, p1_y, p2_x, p2_y);
    *side2 = RegnEnSide(p2_x, p2_y, p3_x, p3_y);
    *side3 = RegnEnSide(p3_x, p3_y, p1_x, p1_y);

    return *side1 + *side2 + *side3;
}


//Bruger 2 punkter til at regne længden
double RegnEnSide(double p1x, double p1y, double p2x, double p2y) {

    return sqrt( pow( p2x - p1x ,2) + pow( p2y - p1y ,2));
}