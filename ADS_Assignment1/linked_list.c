/*
 * Created by Zhen Liu (Meimi Liu) on 18/08/2022.
 * Program modified from the example written by Alistair Moffat, as an example for the book
 * "Programming, Problem Solving, and Abstraction with C",
 * Pearson Custom Books, Sydney, Australia, 2002; revised edition 2012, ISBN 9781486010974.
 * Chapter 10.2 Linked Structure (Page 172)
*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "linked_list.h"

//function implementation

/***
 * Creating an empty linked list
 ***/
list_t* make_empty_list(void) {
    // malloc a space for the list to store head and foot
    list_t* list;
    list = (list_t*)malloc(sizeof(list_t));
    assert(list!=NULL);
    // Set the head and foot to NULL
    list->head = list->foot = NULL;
    return list;
}

/***
 * Freeing a linked list
 ***/
void free_list(list_t *list) {
    // Set current node as the head node
    node_t* curr = list->head;
    node_t* prev; //Create two pointers to keep track of the freeing process
    assert(list!=NULL);

    while (curr) { // Continue to free each node until curr points to NULL
        prev = curr; //Making prev points toward curr
        curr = curr -> next; // Making curr points to the address of next node
        free_record(prev -> data); // freeing the record that prev points to
        free(prev);
    }
    free(list); //freeing the struct of list
}

/***
 * Inserting a new node at foot in a linked list
 ***/
list_t* insert_at_foot(list_t *list, data_t* value) {
    assert(list);
    // Create a new node
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    assert(new_node);
    // Initialise the value and next address in the new node
    new_node->data = value;
    new_node->next = NULL;
    // Evaluate whether the original list is empty or not
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        list->foot->next = new_node;
    }
    // Update the foot
    list->foot = new_node;
    return list;
}

/***
 * Searching the records in a dictionary that matches to a query
 ***/
void search_list(dictionary_t dictionary, char* query, FILE* out_file){

    int match_count = 0;

    FILE* output = out_file;
    fprintf(output, "%s\n", query);

    // looping through the whole linked list in order to search and print out matched records
    node_t* curr = dictionary -> head;
    node_t* prev;
    assert(dictionary!=NULL);

    while (curr) {
        if (strcmp(curr -> data -> address, query)) {
            print_record(output, curr->data);
            match_count++;
        }
        prev = curr;
        curr = curr -> next;
    }


    if(match_count == 0){
        printf("%s --> NOTFOUND", query);
    }else{
        printf("%s --> %d", query, match_count);
    }


    // close output file
    fclose(output);
}

