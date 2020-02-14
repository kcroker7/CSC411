#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <except.h>
#include "assert.h"
#include "bit2.h"
#include "pnmrdr.h"
#include "unblackedges.h"

// read from file, put file into array, start from edges and work in, change from 1 to 0

struct pic {
    int row;
    int col;
};

iint main(argc, char *argv[]){
    FILE *input;
    
    if(argc == 2){
        input = fopen(argv[1], "rb");
        readFile(input);
      }
      
    if(argc >= 2){
        fprintf(stderr, "Too many arguments given");
      }

    else{
        readFile(stdin);
    }

}


void readFile(FILE *input, bit2_T *uarray2){
    pnmrdr_mapdata picData;
    int height = 0;
    height = data.height;
    int width = 0;
    width = data.width;

    void *read = NULL
    read = pnmrdr_new(input);
    picData = pnmrdr_data(read);

    if(pData.type != Pnmrdr_bit){
        fprintf(stderr, "Incorrect file format");
    }

    *uarray2 = bit2_new(height, width);
    pnmrdr_free((pnmrdr_T *)read);
}

void startFromEdges(int row, int col, bit2_T uarray2, int bit, void *cl){
    (void) bit;
    int temp = pnmrdr_get(cl);
    bit2_put(uarray2, row, col, temp);
    int height = bit2_height(uarray2);
    int width = bit2_width(uarray2);
    if(row == 0 || col == 0 || row == height - 1 || col == width - 1){
        if (bit == 1) {
            checkPix(row, col, uarray2);
    }
}

void checkPix(int r1, int c1, bit2_T uarray2, int bit){
    bit2_height = height;
    bit2_width = width;

    bool a = true;
    bool b = false;
    while(a){
        if((bit2_get(uarray2, r1, c1) == 1)){
            bit2_put(uarray2. r1, c1, 0)
            if(c1 - 1) >= 0 && bit2_get((uarray2, c1, r1 -1) == 1){
                r1 = r1 - 1;
            }

            if(c1 + 1) < height && bit2_get((uarray2, c1, r1 + 1) == 1){
                r1 = r1 + 1;
            }

            if(c1 + 1) < width && bit2_get((uarray2, c1 + 1, r1) == 1){
                c1 = c1 + 1;
            }            

            if(c1 - 1) >= 0 && bit2_get((uarray2, c1 - 1, r1) == 1){
                c1 = c1 - 1;
            }

            if(r1 == width && c1 = height){
                break;
            }
        }
    }
}

void pbmwrite(bit2_T uarray2){
    int height = bit2_height(uarray2);
    int width = bit2_width(uarray2);
    fprintf(stdout);
    fprintf(stdout, "\n", height, width);
}

void bitCol(int row, int col, bit2_T uarray2, int bit, void *cl){
    void row, uarray2, cl;

    int width = 0;
    int width = bit2_width(uarray2);
    int placeHold = 1;

    if(col == width - 1 || (col + 1) % 35 == 0){
        fprintf(stdout);
    }
    fprintf(stdout);
}