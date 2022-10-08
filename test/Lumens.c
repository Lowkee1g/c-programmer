#include <stdio.h>

int main(int argc, char const *argv[])
{
    int watts = 25;
    int lumens;

    if (watts == 15) {
        lumens = 125;
    } else {
        if (watts == 25) {
            lumens = 215;
        } else {
            if (watts == 40) {
                lumens = 500;
            } else {
                if (watts == 60) {
                    lumens = 880;
                } else {
                    if (watts == 75) {
                        lumens = 1000;
                    } else {
                        if (watts == 100) {
                            lumens = 1675;
                        } else {
                            lumens = -1;
                        }   
                    }   
                }   
            }   
        }
    }
    printf("\nWatts: %d, Giver lumens: %d\n\n", watts, lumens);
    return 0;
}
