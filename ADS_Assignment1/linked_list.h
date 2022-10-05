//
// Created by Zhen Liu on 18/08/2022.
//

#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

// includes
#include "record.h"

// definitions

typedef record_t data_t;

typedef struct node node_t;
struct node {
    data_t* data; // Storing the pointer to struct, not struct itself
    node_t* next;
};

typedef struct {
    node_t* head;
    node_t* foot;
} list_t;

typedef list_t* dictionary_t;

// function prototype

list_t* make_empty_list(void);
void free_list(list_t *list);
list_t* insert_at_foot(list_t* list, data_t * value);
void search_list(dictionary_t dictionary, char* query, FILE* out_file);

#endif