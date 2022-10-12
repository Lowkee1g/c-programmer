#include <stdio.h>

enum planeter {Merkur, Venus, Jorden, Mars, Jupiter, Saturn, Uranus, Neptun};

int main(void)
{
    int diameter;
    
    

    printf("%d\n", circumference(Merkur));
    printf("%d\n", circumference(Venus));
    printf("%d\n", circumference(Jorden));
    return 0;
}



int circumference(enum planeter Planet) {
    switch (Planet) {
    case Merkur:
        return 15329;
        break;
    
    case Venus:
        return 38025;
        break;
    
    case Jorden:
        return 40075;
        break;
    
    case Mars:
        return 21344;
        break;
    
    case Jupiter:
        return 439264;
        break;
    
    case Saturn:
        return 378675;
        break;
    
    case Uranus:
        return 160590;
        break;

    case Neptun:
        return 155600;
        break;
    
    default:
        break;
    }
}



