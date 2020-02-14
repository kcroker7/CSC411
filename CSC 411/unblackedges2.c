#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "assert.h"
#include "bit2.h"
#include "uarray2.h"
#include "pnmrdr.h"

//read file in, read from file, file to bitmap, start from edge, check pix, pbmwrite


int main(argc, char *argv[]){
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

void readFile(FILE *input){
    bit2_T pic = bit_array(input);
    bit2_T edges = start_from_edges(pic);

    changeEdge(pic, edges);
    pbmwrite(stdout, pic);
    bit2_free(&pic);
    bit2_free(&edges);

    if(pData.type != pnmrdr_bit){
        fprintf(stderr, "Incorrect file format");
    }

}

bit2_T bit_array(FILE *input){
    int row = 0;
    int col = 0; 
    Pnmrdr_T bitData = pnmrdr_new(input);
    Pnmrdr_mapdata pData = pnmrdr_data(bitData);

    bit2_T bitmap = bit2_new(pData.height, pData.width);
    
    for(row = 0; row < pData.height; row++){
        for(col = 0; col < pData.width; col++){
            bit2_put(bitmap, row, col, pnmrdr_get(bitData));
        }
    }
    return bitmap;
}

bit2_T start_from_edges(bit2_T pFile){
    int row = 0;
    int col = 0;

    bit2_T bEdge = bit2_new(bit2_height(pFile), bit2_width(pFile));
    
    for(row = 0; row < bit2_height(pFile); row++){
        bit2_put(bEdge, 0, row, bit2_get(pFile, 0, row));
        bit2_put(bEdge, bit2_width(bEdge) - 1, row, 
        bit2_get(pFile, bit2_width(pFile) - 1, row));
    }

    for(col = 0; col < bit2_width(pFile); col++){
        bit2_put(bEdge, col, 0, bit2_get(pFile, col, 0));
        bit2_put(bEdge, col, bit2_width(bEdge) - 1, 
        bit2_get(pFile, col, bit2_width(pFile) - 1));
    }

    while(false){
        true = checkB(bEdge, pFile);
    }

    return bEdge;
}

int checkB(bit2_T bEdge, bit2_T pFile){
    int change = 1;
    int row = 0;
    int col = 0;

    for(row = 0; row < bit2_height(bEdge) - 1; row++){
        for(col = 0; col < bit2_width(bEdge) - 1; col++){
            if(isBEdge(bEdge, pFile, row, col) || isBEdge(bEdge, pFile, bit2_height(pFile) - 1 - row,
            bit2_width(pFile) - 1 - col)){
                change = 0;
            }
        }
    }
    return change;
}

void changeEdge(bit2_T pic, bit2_T edges){
    int row = 0;
    int col = 0;

    for(row = 0; row < bit2_height(edges); row++){
        for(col = 0; col < bit2_width(edges); col++){
            if(bit2_get(edges, row, col)){
                bit2_put(pic, row, col, 0);
            }
        }
    }
}

int isBEdge(bit2_T bEdge, bit2_T pFile){
    int row = 0;
    int col = 0;

    if(bit2_get(pFile, row, col) && !(bit2_get(bEdge, row, col))){
        if(bit2_get(bEdge, col - 1, row) || bit2_get(bEdge, col + 1, row ||
        bit2_get(bEdge, col, row - 1) || bit2_get(bEdge, col, row + 1))){
            bit2_put(bEdge, row, col, 1);
            return 1;
        }
    }
    return 0;
}

void pbmwrite(FILE *finish, bit2_T bitmap){
    pfrintf(finish);
    bit2_map_row_major(bitmap, finish);
}