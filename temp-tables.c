#include <stdio.h>
#include <stdlib.h>

int main() {
    float kelv, fahr, celc, ream;
    float lowerLim, upperLim, step;

    lowerLim = 0;
    upperLim = 1000;
    step = 1;

    printf("Richie's Temperature Units Table <*K> <*F> <*C> <*R>\n");

    for(kelv = lowerLim; kelv <= upperLim; kelv += step) {
        fahr = 1.8 * (kelv - 273.15) + 32;
        celc = kelv - 273.15;
        ream = 0.8 * (kelv - 273.15);
        printf("\t%f *K\t%f *F\t%f *C\t%f *R\n", kelv, fahr, celc, ream);
        printf("----------------------------------------------------------------------------\n");
    }
}
