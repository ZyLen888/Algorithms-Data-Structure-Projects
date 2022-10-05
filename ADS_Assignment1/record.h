//
// Created by Zhen Liu on 18/08/2022.
//

#ifndef _RECORD_H_
#define _RECORD_H_

//includes
#include <stdio.h>

//definitions

typedef struct record record_t;

struct record{
    int footpath_id;
    char* address;
    char* clue_sa;
    char* asset_type;
    double deltaz;
    double distance;
    double grade1in;
    int mcc_id;
    int mccid_int;
    double rlmax;
    double rlmin;
    char* segside;
    int statusid;
    int streetid;
    int street_group;
    double start_lat;
    double start_lon;
    double end_lat;
    double end_lon;
};

//function prototype
void print_record(FILE* file, record_t* record);
void free_record(record_t* record);


#endif
