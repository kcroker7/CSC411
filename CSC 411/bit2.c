#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "assert.h"
#include "mem.h"
#include "bit2.h"

#define T bit_T

struct T {
    int height;
    int width;
    bit_T arr;
};

T bit2_new(int height, int width) {
    T uarray2;
    assert(height && width >= 0);
    NEW(uarray2);
    
    uarray2->height = height;
    uarray2->width = width;
    uarray2->arr = bit_new(height * width);

    return uarray2;
}

void bit2_free(T *uarray2) {
    assert(uarray2 && *uarray2);
    FREE(*uarray2)->words;
    FREE(*uarray2);
}

int *bit2_get(T uarray2, int row, int col) {
    assert(uarray2);
    uarray2->height = height;
    uarray2->width = width;
    assert(row >= 0 && row < (uarray2->height));
    assert(col >= 0 && col < (uarray2->width));

    int temp = ((row * uarray2->width) + col);
    int newB = bit2_get(temp);

    return newB;
}

int *bit2_put(T uarray2, int row, int col, int bit) {
    int prev;
    assert(uarray2);
    assert(bit == 0 || bit == 1);
    assert(0 <= row && row < uarray2->height);
    assert(0 <= col && col < uarray2->width);
    
    int temp = ((row * uarray2->width) + col);
    prev = bit2_get(temp);
    bit2_put(temp, bit);

    return prev;
}

int bit2_height(T urray2) {
    assert(uarray2);

    return uarray2->height;
}

int bit2_width(T urray2) {
    assert(uarray2);

    return uarray2->width;
}

void bit2_map_row_major(T uarray2, void apply(int row, int col,
                        int bit, void *cl), void *cl) {
    assert(uarray2);

    uarray2->height = height;
    uarray2->width = width;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            apply(j, i, uarray2, bit2_get(uarray2, j, i), cl);
        }
    }
}

void bit2_map_col_major(T uarray2, void apply(int row, int col,
                        int bit, void *cl), void *cl) {
    assert(uarray2);

    uarray2->height = height;
    uarray2->width = width;

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            apply(i, j, uarray2, bit2_get(uarray2, i, j), cl);
        }
    }
}