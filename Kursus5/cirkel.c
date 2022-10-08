#include <stdio.h>

#define PI 3.14159


double OmRegn(double ra);
double ArRegn(double ra);

int main(void)
{
    double radius;
    int valg;
    again:

    //spørger om areal eller omkreds
    printf("areal (1) eller omkreds? (0) \n");
    scanf("%d", &valg);

    //spørger om et tal
    printf("Tast et tal her: \n");
    scanf("%lf", &radius);



    //Valg mellem areal eller omkreds
    switch (valg)
    {
        case 0:
            printf("Her er omkredsen: %lf",OmRegn(radius));
            break;
        
        case 1:
            printf("Her er arealet: %lf", ArRegn(radius));
            break;
        
        default:
            printf("Du har ikke valg areal(1) eller omkreds(0) \n");
            goto again;
            break;
    }


    return 0;
}


//Functions
//Omkreds
double OmRegn(double ra) {
    return PI * ra * 2;
}

//Areal
double ArRegn(double ra) {
    return PI * ra * ra;
}




















