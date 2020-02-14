#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bit2.h"
#include "uarray2.h"



//Read the file provided by the user

void readFile(FILE *input);

//Put the file into an array of bits

bit2_T bit_array(FILE *input);

//Start from the edges and work way to middle or unless it finds white pixels

bit2_T start_from_edges(bit2_T pFile);

//Checking to see if the pixels are black (1), or white (0), and changing if need be

int checkB(bit2_T bEdge, bit2_T pFile);

//chhanging edge color

void changeEdge(bit2_T pic, bit2_T edges);

//verifying that edges need to be changed

int isBEdge(bit2_T bEdge, bit2_T pFile);

//writing new file

void pbmwrite(FILE *finish, bit2_T bitmap);