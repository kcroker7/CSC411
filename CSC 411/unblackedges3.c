#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "assert.h"
#include "bit2.h"
#include "uarray2.h"
#include "pnmrdr.h"

//read file in, read from file, file to bitmap, start from edge, check pix, pbmwrite

struct edgeData {
    int row;
    int col;
}


int main(argc, char *argv[]){
    FILE *input;
    
    if(argc == 2){
        input = fopen(argv[1], "rb");
        readFile(input);
      }
      
    if(argc >= 2){
        fprintf(stderr, "Too many arguments given");
        exit(1);
      }

    else{
        readFile(stdin);
    }

}

void readFile(FILE *input, bit2_T uarray2){
    bit2_T pic = bit_array(input);
    bit2_T edges = start_from_edges(pic);

    pnmrdr_mapdata pData;

    void *readPData; 
    readPData = pnmrdr_new(input);
    pData = pnmrdr_data(readPData);

    if(pData.type != Pnmrdr_bit){
        fprintf(stderr, "Incorrect file format");
        exit(1);
    }

}

void bit_array(int row, int col, bit2_T uarray2, void *cl){
    int place = pnmrdr_get(cl);
    bit2_put(uarray2, row, col, place);
}