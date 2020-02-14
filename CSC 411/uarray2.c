#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assert.h"
#include "uarray2.h"
#include "arrayrep.h"

#define T uarray2_T

typedef struct T *T;

struct T {
    int width;
    int height;
    int size;
    char *array;
};

/* uarray2_new allocates space for a descriptor and for the 
   array itself if height and width are positive */

T uarray2_new(int height, int width, int size) {
    T uarray2;
    NEW(uarray2);
    assert(size && height && width > 0);
    uarray2->height = height;
    uarray2->width = width;
    uarray2->size = size;

    return uarray2;
}

/* uarray2_free deallocates the array itself and the T structure
   and clears its argument */

void uarray2_free(T *uarray2){
    assert(uarray2 && *uarray2);
    FREE((*uarray2)->array);
    FREE(*uarray2);
}

// uarray2_size returns the size of the elements being stored

int uarray2_size(T uarray2){
    assert(uarray2);

    return uarray2->size;
}

// uarray2_at fetch and store elements in an array

void *uarray2_at(T uarray2, int row, int col){
    assert(uarray2);
    uarray2->height = height;
    uarray2->width = width;
    assert(row >= 0 && row < (uarray2->height));
    assert(col >= 0 && col < (uarray2->width));

    return uarray2->array + row*width + col;
}

// uarray2_height returns the height of the array

int uarray2_height(T uarray2){
    assert(uarray2);

    return uarray2->height;
}

// uarray2_width returns the width of the array

int uarray2_width(T uarray2){
    assert(uarray2);
    
    return uarray2->width;
}

// uarray2_map_row_major will loop through rows and apply to the elements

void uarray2_map_row_major(T uarray2, void apply(int row, int col, 
                        T uarray2, void *elem, void *cl), void *cl){
    assert(uarray2);

    uarray2->height = height;
    uarray2->width = width;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            apply(j, i, uarray2, uarray2_at(array, j, i));
        }
    }
}

// uarray2_map_col_major will loop through rows and apply to the elements

void uarray2_map_col_major(T uarray2, void apply(int row, int col,
                        T uarray2, void *elem, void *cl), void *cl){
    assert(uarray2);

    uarray2->height = height;
    uarray2->width = width;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            apply(i, j, uarray2, uarray2_at(array, i, j));
        }
    }
}