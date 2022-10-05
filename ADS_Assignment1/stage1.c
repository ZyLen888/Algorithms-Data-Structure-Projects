//
// Created by Zhen Liu (Meimi Liu) on 18/08/2022.
//

#include "stage1.h"
#include "linked_list.h"

/***
 * Satisfy the requirement of Stage One:
 * Read the data from the data file specified in the second command line argument.
    - The data from the CSV should be stored in a linked list of pointers to structs for the data.
    - Each record (row) should be stored in a separate node.
- Accept addresses from stdin, search the list for all matching records and print them to the output file.
- In addition to outputting the record(s) to the output file, the number of records found should be output to stdout
 ***/
void stage_one(char* in_file, char* out_file){

    // read data into the dictionary
    list_t* dictionary = read_csv(in_file);
    char* query;

    // read stdin query
        while(scanf(" %[^\n]",query) == 1){
            // process each query
            search_list(dictionary, query, out_file);
        }

    // free list
    free_list(dictionary);
}
