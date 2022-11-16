#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *udskift2(char s[], char c1, char c2);

int main(void) {
    char streng[] = "Foodback";
    char *streng2;
    char *streng3;

    printf("streng: %s\n", streng);

    printf("Vi Udskifter!\n");

    streng2 = udskift3(streng);


    printf("steng: %s\n", streng);
    printf("streng2: %s\n", streng2);

    free(streng3);
    return 0;
}


char *udskift3(char s[]) {

    char *s2 = (char *) malloc((strlen(s) + 1) * sizeof(char));

    int i = 0;
    while (s[i] != '\0')
    {
        
        i++;
    }
    

    

    return s2;
}


char *udskift2(char s[], char c1, char c2) {

    char *s2 = (char *) malloc((strlen(s) + 1) * sizeof(char));

    if (c2 == NULL) {
        exit(EXIT_FAILURE);
    }

    int i = 0;
    printf("%d\n", strlen(s)*sizeof(char));
    printf("%d\n", strlen(s2)*sizeof(char));
    while (s[i] != '\0') {
        if (i == strlen(s)) {
            s2[i] = '!';
            printf("Yikes\n");
        } else {
            if (s[i] == c1) {
                s2[i] = c2;
            } else {
                s2[i] = s[i];
            }
        }
        printf("%d", i);
        i++;
    }
    s2[i] = '\0';

    return s2;
}