#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pnmrdr.h>


int main(int argc, char *argv[]) {
    
    FILE *input;

    if(argc == 1){
        input = stdin;
    }

    else if(argc == 2) {
        input = fopen(argv[1],"r");
    }
    else {
        fprintf(stderr, "too many arguments");
    }

    Pnmrdr_T r = Pnmrdr_new(input);
    Pnmrdr_mapdata D = Pnmrdr_data(r);
    
    int w = D.width;
    int h = D.height;
    int nPix = w * h; 

    double total = 0;

    for (int i = 0, i < nPix, i++) {
        total += Pnmrdr_get(r);
    }

    int den = D.denominator;
    double aPix = 0;

    aPix = (total / (nPix * den))

    Pnmrdr_free(r)
    printf("%.3f \n", aPix);


}