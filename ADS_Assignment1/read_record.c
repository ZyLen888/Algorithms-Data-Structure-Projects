//
// Created by Zhen Liu (Meimi Liu) on 18/08/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "linked_list.h"
#include "record.h"
#include "read_record.h"

//function implementation

/***
 * Reading in CSV file and process the file to store the record into a struct.
 * After the record is stored as a struct, the struct is added to the linked list as a new node.
 ***/
list_t* read_csv(char* filename){

    // Open the file and assert
    FILE* file = fopen(filename, "r");
    assert(file);

    // Create empty linked list
    list_t* list = make_empty_list();

    // Start reading file
    // Read and skip header

    char* buffer = malloc(sizeof(char) * MAX_ROW_LENGTH + 1);
    assert(buffer);

    fgets(buffer, MAX_ROW_LENGTH, file);

    // Read each line of input file
    while(fgets(buffer, MAX_ROW_LENGTH, file) != NULL){

        // Process and store a single line of data in line in a struct
        record_t* record = record_processing(buffer);

        // Insert struct into linked list
        list = insert_at_foot(list, record);
    }

    free(buffer); // Free temporary memory
    fclose(file); // Close file
    return list; // Return linked list
}

/***
 * Process a single record and store individual field (seperated by comma) into a struct.
 * Types are converted when stored into a struct.
 ***/
record_t* record_processing(char* buffer){

    record_t* record = malloc(sizeof(record_t));
    assert(record);

    // Process a line into each fields of data
    char** fields = read_fields(buffer);
    char* end_ptr;

    // Store each field in struct
    record -> footpath_id = atoi(fields[0]);

    record -> address = malloc(sizeof(char) * strlen(fields[1]) + 1);
    assert(record -> address);
    strcpy(record -> address, fields[1]);

    record -> clue_sa = malloc(sizeof(char) * strlen(fields[2]) + 1);
    assert(record -> clue_sa);
    strcpy(record -> clue_sa, fields[2]);

    record -> asset_type = malloc(sizeof(char) * strlen(fields[3]) + 1);
    assert(record -> asset_type);
    strcpy(record -> asset_type, fields[3]);

    record -> deltaz = strtod(fields[4], &end_ptr);

    record -> distance = strtod(fields[5], &end_ptr);

    record -> grade1in = strtod(fields[6], &end_ptr);

    record -> mcc_id = atoi(fields[7]);

    record -> mccid_int = atoi(fields[8]);

    record -> rlmax = strtod(fields[9], &end_ptr);

    record -> rlmin = strtod(fields[10], &end_ptr);

    record -> segside = malloc(sizeof(char) * strlen(fields[11]) + 1);
    assert(record -> asset_type);
    strcpy(record -> asset_type, fields[11]);

    record -> statusid = atoi(fields[12]);

    record -> streetid = atoi(fields[13]);

    record -> street_group = atoi(fields[14]);

    record -> start_lat = strtod(fields[15], &end_ptr);

    record -> start_lon = strtod(fields[16], &end_ptr);

    record -> end_lat = strtod(fields[17], &end_ptr);

    record -> end_lon = strtod(fields[18], &end_ptr);

    // Free memory used by fields
    for (int i = 0; i < 19; i++){
        free(fields[i]);
    }
    free(fields);

    return record;
}

/***
 * Reading in a single record and outputting a 2D array that stores 19 fields individually.
 * This function involves evaluating the start and end of each field and storing it in the 2D array.
 ***/
char** read_fields(char* buffer){

    // Creating a 2D array that stores pointer to 19 fields individually
    char** fields = malloc(sizeof(char*) * NUM_FIELDS);
    assert(fields);

    int in_quote = 0; // A flag variable to keep track whether a comma is in a quote
    int i = 0; // index for buffer
    int field_index = 0; //Record which field we are reading currently
    int field_length = 0; // Record the length of the current field
    char temp[MAX_STR_LENGTH+1]; // Create a temporary array to store a field

    while(buffer [i] != '\0' && buffer[i] != EOF && buffer[i] != '\n'){
        if (buffer[i] == ','){
            if (in_quote == 1){ // if the comma is in a quote, then it does not signify an end of a field
                // So we copy the comma into our temporary array
                temp[field_length] = buffer[i];
                i++;
                field_length++;
            } else{ // Signify an end of a field
                temp[field_length] = '\0';
                fields[field_index] = (char*) malloc(sizeof(char) * field_length + 1);
                assert(fields[field_index]);
                strcpy(fields[field_index], temp);
                field_length = 0; // Reset field_length to 0 for next field
                field_index++; //Moving on to read the next field
            }
        } else if (buffer[i] == '"'){
            in_quote = !in_quote;
        }else{
            temp[field_length] = buffer[i];
            i++;
            field_length++;
        }
    }

    temp[field_length] = '\0';
    fields[field_index] = (char*) malloc(sizeof(char) * field_length + 1);
    assert(fields[field_index]);
    strcpy(fields[field_index], temp);

    return fields; // Return an array of strings
}