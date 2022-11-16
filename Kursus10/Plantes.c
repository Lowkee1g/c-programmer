#include <stdio.h>
#include <string.h>
#include <math.h>
#define _USE_MATH_DEFINES

typedef struct Plantes plantes;
void blue () {
  printf("\033[0;36m");
}

void reset () {
  printf("\033[0m");
}

struct Plantes {
    char name[30];
    double radius;
    double volume;
    double mass;
};

void vol(plantes *p);
plantes scanInsert();


int main(void)
{   

    plantes input = scanInsert();
    vol(&input);
    

    printPlantes(input);
    return 0;
}



void printPlantes(plantes p) {
    blue();
    printf("\n%s", p.name);
    reset();
    printf("\n  Radius : %lf", p.radius);
    printf("\n  Mass   : %lf", p.mass);
    printf("\n  Volume : %lf", p.volume);
    
}



plantes scanInsert() {
    plantes planet;
    blue();
    printf("\nInsert planet name: ");
    reset();
    scanf("%s", &planet.name);
    printf("\nInsert planet radius: ");
    scanf("%lf", &planet.radius);
    printf("\nInsert planet mass: ");
    scanf("%lf", &planet.mass);

    return planet;
}

void vol(plantes *p) {
    p->volume = 4/3* M_PI * pow(p->radius,3);
}

