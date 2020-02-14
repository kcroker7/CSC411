#include <uarray.h>

#define T uarray2_T;

typedef struct T *T;

/* uarray2_new allocates space for a descriptor and for the 
   array itself if height and width are positive */

T uarray2_new(int height, int width, int size);

/* uarray2_free deallocates the array itself and the T structure
   and clears its argument */

extern void uarray2_free(T *uarray2);

// uarray2_size returns the size of the elements being stored

extern int uarray2_size(T uarray2);

// uarray2_at fetch and store elements in an array

extern void *uarray2_at(T uarray2, int col, int row);

// uarray2_height returns the height of the array

extern int uarray2_height(T uarray2);

// uarray2_width returns the width of the array

extern int uarray2_width(T uarray2);

/* uarray2_map_row_major will loop through rows and apply 
   the function to the elements */

void uarray2_map_row_major(T uarray2, void apply(int row, int col, 
                        T uarray2, void *elem, void *cl));

/* uarray2_map_col_major will loop through columns and apply 
   the function to the elements */

void uarray2_map_col_major(T uarray2, void apply(int row, int col, 
                        T uarray2, void *elem, void *cl));


#undef T