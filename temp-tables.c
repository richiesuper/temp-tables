#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int kelvBase(float a, float b, float c) {
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
    return 0;
}

int fahrBase(float a, float b, float c) {
    float fahr, kelv, celc, ream;
    float lowerLim, upperLim, step;

    lowerLim = a;
    upperLim = b;
    step = c;

    printf("Richie's Temperature Units Table <*F> <*K> <*C> <*R>\n");

    for(fahr = lowerLim; fahr <= upperLim; fahr += step) {
        kelv = (5 / 9) * (fahr - 32) + 273.15;
        celc = (5 / 9) * (fahr - 32); /* I know that I can use the value of kelv - 273.15 but this direct approach looks cooler to me XD */
        ream = (4 / 9) * (kelv - 273.15);
        printf("\t%f *F\t%f *K\t%f *C\t%f *R\n", fahr, kelv, celc, ream);
        printf("----------------------------------------------------------------------------\n");
    }
    return 0;
}

int celcBase(float a, float b, float c) {
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
    return 0;
}

int reamBase(float a, float b, float c) {
    float ream, fahr, celc, kelv;
    float lowerLim, upperLim, step;

    lowerLim = a;
    upperLim = b;
    step = c;

    printf("Richie's Temperature Units Table <*R> <*F> <*C> <*K>\n");

    for(ream = lowerLim; ream <= upperLim; ream += step) {
        fahr = 9 / 4 * ream + 32;
        celc = 5 / 4 * ream;
        kelv = 5 / 4 * ream + 273.15;
        printf("\t%f *R\t%f *F\t%f *C\t%f *K\n", ream, fahr, celc, kelv);
        printf("----------------------------------------------------------------------------\n");
    }
    return 0;
}

int main() {
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
