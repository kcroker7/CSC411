#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#include "pnmrdr.h"
#include "assert.h"

/* In this first functiom we are making a main to
read through files so that we can then process them and 
determine their brightness*/

int main(int argc, char *argv[]){
    assert(argc <= 2);
    FILE *input;
    if(argc == 2) {
        input = fopen(argv[1], "rb");
        if(!input) {
            perror(argv[1]);
            exit(1);
        }
    }
    else if (argc == 1){
        input = stdin;
    }
    else {
        fprintf("Error");
        exit(1);
    }

    /* From here on we are getting the data of the images 
    to then see the number of pixels in each. Then we will 
    find the total and divide that by the number of pixels
    multiplies by the denominator&*/

    Pnmrdr_T r = Pnmrdr_new(input);
    Pnmrdr_mapdata data = Pnmrdr_data(r);

    int nPix = 0;
    nPix = Pnmrdr_data.width * Pnmrdr_data.heihgt; 

    float total = 0;

    for (int i = 0; i < nPix; i++) {
        unsigned newInt = Pnmrdr_get(r);
        total += newInt;
    }

    int den = D.denominator;
    double aPix = 0;

    aPix = (total / (nPix * den))

    Pnmrdr_free(r)
    printf("%.3f \n", aPix);

}