#include <stdio.h>

int main(void)
{
    //--------------------------------------//
    //-----Definationer af variabler--------//
    //--------------------------------------//



    int sec, min, hour, day, week;
    int minPrSec, hourPrSec, dayPrSec, weekPrSec;


    minPrSec = 60;
    hourPrSec = minPrSec * 60;
    dayPrSec = hourPrSec * 24;
    weekPrSec = dayPrSec * 7;



    //--------------------------------------//
    //---Beder brugren om et antal sekunder-//
    //--------------------------------------//



    printf("\n\n\n\n\n\n");
    printf("Indtast sekunder som omregnes til aar, maanderer, dage, timer, minutter, sekunder: \n");
    printf("Indtast here: ");
    scanf("%i", &sec);
    printf("\n\n\n\n\n\n");
    
    
    
    //--------------------------------------//
    //------------Udregner------------------//
    //--------------------------------------//


    //Week
    week = (sec/weekPrSec);
    sec = sec % weekPrSec;

    //Dage
    day = (sec/dayPrSec);
    sec = sec % dayPrSec;

    //Timer
    hour = (sec/hourPrSec);
    sec = sec % hourPrSec;

    //Minutter
    min = (sec/minPrSec);
    sec = sec % minPrSec;



    //--------------------------------------//
    //------Printer resultatet--------------//
    //--------------------------------------//


    
    printf("Uger: %i; Dage: %i; Timer: %i; Minuter: %i; sekunder: %i;", week, day, hour, min, sec);
    


    //Lukker programmet//
    return 0;
}