#include <"sudoku.h">
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "assert.h"
#include "uarray2"


//read file, fill array, check row, check col, check box

int main(int argc, char *argv[]){
    FILE *input;

    uarray2_T sol = uarray2_new(9, 9, sizeof(int));

    if(argc == 1){
        input = stdin;
    }

    else{
        input = fopen(argv[1], "rb");
    }

    readSol(sol, input);
    check(sol);
    
}

FILE *file_get(int argc, char *argv[]){
    FILE *fp;
    if (argc > 2){
        fprintf(stderr, "if there are too many command arguments")
        exit(EXIT_FAILURE);
    }


    if (argc ==2){
        fprintf(stderr,"Too many arguments.");
        exit(EXIT_FAILURE); 
    }
    return fp;

}


else {
    return(stdin);
}}


Pnmrdr_T get image(FILE*fp){

    Pnmrdr_T image = NULL;



    TRY
        image = Pnmrdr_new(fp);
        
    EXCEPT(Pnmrdr_Badformat)
        fprint(stderr, "Bad format");
        fclose(fp);
        exit(1);
    END TRY;

    
}
