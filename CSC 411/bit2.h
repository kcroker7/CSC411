#include "array.h"
#include "uarray2.h"
#define T bit2_T
typedef struct T *T;

//new, free, size, put, get, height, width, row major, col major

/* bit2_new creates a new array of height and width 
   stored by bits */

T bit2_new(int height, int width);

// bit2_free will free the array and also clear it

extern void bit2_free(T *uarray2);

/* bit2_get will return a bit and then test whether it is
   in the array. In will return 1 if the bit is in the array 
   and a 0 if not in the array */

extern int *bit2_get(T uarray2, int row, int col);

/* bit2_put will set bit n to bit and returns the previous 
   value of that bit */

extern int *bit2_put(T uarray2, int row, int col, int bit);

// bit2_height will return the height of uarray2

extern int bit2_height(T urray2);

// bit2_width will return the width of uarray2

extern int bit2_width(T uarray2);

/* This function will loop through rows and apply 
   the function to the elements */

void bit2_map_row_major(T uarray2, void apply(int row, int col,
                        int bit, void *cl), void *cl);

/* This function will loop through columns and apply 
   the function to the elements */

void bit2_map_col_major(T uarray2, void apply(int row, int col,
                        int bit, void *cl), void *cl);