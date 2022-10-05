//
// Created by Zhen Liu (Meimi Liu) on 18/08/2022.
//

#ifndef _READ_RECORD_H
#define _READ_RECORD_H

// includes
#include "linked_list.h"

//function prototype

// Reading the csv file and saving it to the linked list
list_t* read_csv(char* filename);
record_t* record_processing(char* buffer);
char** read_fields(char* buffer);

//constants
#define MAX_ROW_LENGTH 512
#define MAX_STR_LENGTH 128
#define NUM_FIELDS 19

#endif
