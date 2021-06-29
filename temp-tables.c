#include <stdio.h>
#include <stdlib.h>

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
    char baseUnit;
    float lL, uL, st;

    printf("Hello there, user! Richie's Temperature Units Table is here to help you out!\n");

    printf("Now, enter your base unit choice (k = Kelvin | f = Fahrenheit | c = Celcius | r = Reaumur): \n");
    scanf("%c", &baseUnit);

    printf("Enter your desired lower limit for the base temperature unit (ints or floats): \n");
    scanf("%f", &lL);

    printf("Enter your desired upper limit for the base temperature unit (ints or floats): \n");
    scanf("%f", &uL);

    printf("Enter your desired step for the base temperature unit (ints or floats): \n");
    scanf("%f", &st);

    if(baseUnit == 'k' || baseUnit == 'K') {
        kelvBase(lL, uL, st);
    } else if(baseUnit == 'f' || baseUnit == 'F') {
        fahrBase(lL, uL, st);
    } else if(baseUnit == 'c' || baseUnit == 'C') {
        celcBase(lL, uL, st);
    } else if(baseUnit == 'r' || baseUnit == 'R') {
        reamBase(lL, uL, st);
    } else {
        printf("Base unit value not recognized, please pay more attention to the prompt.\nTerminating program...\n");
        return -1;
    }
}
