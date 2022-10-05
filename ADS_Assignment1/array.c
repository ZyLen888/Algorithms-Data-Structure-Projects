/*
 * Created by Zhen Liu (Meimi Liu) on 21/08/2022.
 * Code adopted from W3.8: qStud: Adding Sorted Array & Binary Search
 * Skeleton/program is compiled by the comp20003 teaching team, the university of Melbourne.
 * Modified by Zhen Liu (Meimi Liu).
*/


#include "array.h"

struct array {
    node_t** A;      // use as array of student_t *, ie. student_t *A[]
    int size;           // current array size
    int n;              // current number of elements
};

/***
 * free memory used by array "arr"
***/

array_t *arrayCreate() {
    array_t *arr = malloc(sizeof(*arr));
    assert(arr);
    int size = INIT_SIZE;      // "size" used for convenience
    arr->size = size;
    arr->A = malloc(size * sizeof(*(arr->A)));
    assert(arr->A);
    arr->n = 0;
    return arr;
}

void arrayFree(array_t *arr) {
    free(arr->A);
    free(arr);
}

/***
 * Shrinks the array, to reduce array size to the same as the number of element used
 * ***/
void arrayShrink(array_t *arr) {
    if (arr->size != arr->n) {
        // the new size should be at least INIT_SIZE
        arr->size = (arr->n > INIT_SIZE) ? arr->n : INIT_SIZE;
        arr->A = realloc(arr->A, arr->size * sizeof(*(arr->A)));
        assert(arr->A);
    }
}


/***
 * makes sure that array's size exceeds its number of elements
 * ie. there is space for adding new element
 ***/

void arrayEnsureSize(array_t *arr) {
    if (arr->n == arr->size) {
        arr->size <<= 1;       // same as arr->size *= 2;
        arr->A = realloc(arr->A, arr->size * sizeof(*(arr->A)));
        assert(arr->A);
    }
}

/***
 * Searches for the closest node using key (grade1in) in array "arr".
 * The definition of "closest" is defined by the absolute difference
 * between the key and the elements in the array.
 * The difference between key and the current element in the array
 * is kept and compared to the minimum difference.
 * ***/

node_t* arraySearch(array_t *arr, double key) {
    node_t *s = NULL;
    double min_diff = INFINITY;
    int i;
    for (i = 0; i < arr->n; i++) {
        double diff = fabs( key - (arr -> A[i] -> data -> grade1in));
        if (diff < min_diff){
            min_diff = diff;
            s = arr -> A[i];
        } else{
            break;
        }
    }
    return s;
}

/***
 * Inserts data "s" into sorted array "arr", ensuring "arr" remains sorted
 * ***/

void sortedArrayInsert(array_t *arr, node_t* s) {
    int i;
    arrayEnsureSize(arr);

    // starting from the end, shift all elements > s one position to the right
    for (i = arr->n - 1; i >=0 && (s -> data -> grade1in) < (arr -> A[i] -> data -> grade1in); i--) {
        arr->A[i + 1] = arr->A[i];
    }
    // now "s" should be in A[i+1]
    arr->A[i + 1] = s;
    arr->n++;
}
