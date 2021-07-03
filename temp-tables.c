#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kelvBase(float a, float b, float c) {
    float kelv, fahr, celc, ream;
    float lowerLim, upperLim, step;

    lowerLim = a;
    upperLim = b;
    step = c;

    printf("Richie's Temperature Units Table <*K> <*F> <*C> <*R>\n");

    for(kelv = lowerLim; kelv <= upperLim; kelv += step) {
        fahr = 1.8 * (kelv - 273.15) + 32;
        celc = kelv - 273.15;
        ream = 0.8 * (kelv - 273.15);
        printf("\t%f *K\t%f *F\t%f *C\t%f *R\n", kelv, fahr, celc, ream);
        printf("----------------------------------------------------------------------------\n");
    }
    exit(0);
}

void fahrBase(float a, float b, float c) {
    float fahr, kelv, celc, ream;
    float lowerLim, upperLim, step;

    lowerLim = a;
    upperLim = b;
    step = c;

    printf("Richie's Temperature Units Table <*F> <*K> <*C> <*R>\n");

    for(fahr = lowerLim; fahr <= upperLim; fahr += step) {
        kelv = 5.0 / 9.0 * (fahr - 32) + 273.15;
        celc = 5.0 / 9.0 * (fahr - 32);
        ream = 4.0 / 9.0 * (fahr - 32);
        printf("\t%f *F\t%f *K\t%f *C\t%f *R\n", fahr, kelv, celc, ream);
        printf("----------------------------------------------------------------------------\n");
    }
    exit(0);
}

void celcBase(float a, float b, float c) {
    float celc, fahr, kelv, ream;
    float lowerLim, upperLim, step;

    lowerLim = a;
    upperLim = b;
    step = c;

    printf("Richie's Temperature Units Table <*C> <*F> <*K> <*R>\n");

    for(celc = lowerLim; celc <= upperLim; celc += step) {
        fahr = 1.8 * celc + 32;
        kelv = celc + 273.15;
        ream = 0.8 * celc;
        printf("\t%f *C\t%f *F\t%f *K\t%f *R\n", celc, fahr, kelv, ream);
        printf("----------------------------------------------------------------------------\n");
    }
    exit(0);
}

void reamBase(float a, float b, float c) {
    float ream, fahr, celc, kelv;
    float lowerLim, upperLim, step;

    lowerLim = a;
    upperLim = b;
    step = c;

    printf("Richie's Temperature Units Table <*R> <*F> <*C> <*K>\n");

    for(ream = lowerLim; ream <= upperLim; ream += step) {
        fahr = 2.25 * ream + 32;
        celc = 1.25 * ream;
        kelv = 1.25 * ream + 273.15;
        printf("\t%f *R\t%f *F\t%f *C\t%f *K\n", ream, fahr, celc, kelv);
        printf("----------------------------------------------------------------------------\n");
    }
    exit(0);
}

int main(void) {
    char baseUnit[16];
    char tempStore[4][16];
    float lL, uL, st;

    printf("Hello there, user! Richie's Temperature Units Table is here to help you out!\n");

    printf("Now, enter your base unit choice (k = Kelvin | f = Fahrenheit | c = Celcius | r = Reaumur): \n");
    fgets(baseUnit, 16, stdin);
    baseUnit[strcspn(baseUnit, "\n")] = 0;

    printf("Enter your desired lower limit for the base temperature unit (ints or floats): \n");
    fgets(tempStore[1], 16, stdin);
    tempStore[1][strcspn(tempStore[1], "\n")] = 0;
    lL = atof(tempStore[1]);

    printf("Enter your desired upper limit for the base temperature unit (ints or floats): \n");
    fgets(tempStore[2], 16, stdin);
    tempStore[2][strcspn(tempStore[2], "\n")] = 0;
    uL = atof(tempStore[2]);

    printf("Enter your desired step for the base temperature unit (ints or floats): \n");
    fgets(tempStore[3], 16, stdin);
    tempStore[3][strcspn(tempStore[3], "\n")] = 0;
    st = atof(tempStore[3]);

    if(*baseUnit == 'k' || *baseUnit == 'K') {
        kelvBase(lL, uL, st);
    } else if(*baseUnit == 'f' || *baseUnit == 'F') {
        fahrBase(lL, uL, st);
    } else if(*baseUnit == 'c' || *baseUnit == 'C') {
        celcBase(lL, uL, st);
    } else if(*baseUnit == 'r' || *baseUnit == 'R') {
        reamBase(lL, uL, st);
    } else {
        printf("Base unit value not recognized, please pay more attention to the prompt.\nTerminating program...\n");
        return -1;
    }
}
