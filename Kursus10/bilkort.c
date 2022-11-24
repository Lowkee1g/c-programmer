#include <stdio.h>
#include <string.h>

typedef struct bilkort bilkort;


struct bilkort
{
    char navn[20];
    int kmt;
    int hk;
    int acc;
    int ccm;
};

#include <stdio.h>
void blue () {
  printf("\033[0;36m");
}

void reset () {
  printf("\033[0m");
}

bilkort hurtigste(bilkort a, bilkort b);
void print_bilkort(bilkort kort);
void skriv_kort_til_fil(FILE *f, bilkort b);

int main(void)
{
    bilkort bil1 = {"Lotus", 200, 110, 8, 1973};
    bilkort bil2 = {"Mercedes", 215, 116, 9, 4520};
    bilkort ba[] = {bil1, bil2};
    
    print_bilkort(bil1);
    print_bilkort(bil2);

    bilkort hurtigsteBil = hurtigste(bil1,bil2);

    FILE *f = fopen("../fil.txt","w");

    skriv_kort_til_fil(f, bil1);


    printf("Hurtigste bil : %s", hurtigsteBil.navn);

    return 0;
}

void skriv_kort_til_fil(FILE *f, bilkort b) {
    fprintf(f, "%s", b.navn);
}


bilkort hurtigste(bilkort a, bilkort b) {
    if (a.kmt >= b.kmt) {
        return a;
    } else {
        return b;
    }
}


void print_bilkort(bilkort kort) {
    blue();
    printf("\n%s\n", kort.navn);
    reset();
    printf("  %c KMT : %d\n", 175, kort.kmt);
    printf("  %c HK  : %d\n", 175, kort.hk);
    printf("  %c ACC : %d\n", 175, kort.acc);
    printf("  %c CCM : %d\n", 175, kort.ccm);
}
