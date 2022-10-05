//
// Created by Zhen Liu (Meimi Liu) on 21/08/2022.
//

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "record.h"
#include "linked_list.h"

#define INIT_SIZE 2     // initial size of arrays

typedef struct array array_t;

array_t *arrayCreate();

void arrayFree(array_t *arr);

void arrayEnsureSize(array_t *arr);

void sortedArrayInsert(array_t *arr, node_t* s);

void arrayShrink(array_t *arr);

node_t* arraySearch(array_t *arr, double key) ;


#endif

