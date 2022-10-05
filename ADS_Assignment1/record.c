/*
 * Created by Zhen Liu (Meimi Liu) on 18/08/2022.
 * record.c
 * Printing and freeing the record after the record is being used.
*/

#include <stdlib.h>
#include <stdio.h>
#include "record.h"

/***
 * Printing the record to an output file with the required format.
 ***/
void print_record(FILE* file, record_t* record){
    fprintf(file, "--> footpath_id: %d || address: %s || clue_sa: %s || asset_type: %s || deltaz: %lf || distance: %lf || grade1in: %lf || mcc_id: %d || mccid_int: %d || rlmax: %lf || rlmin: %lf || segside: %s || statusid: %d || streetid: %d || street_group: %d || start_lat: %lf || start_lon: %lf || end_lat: %lf || end_lon: %lf || \n",
            record -> footpath_id, record -> address, record -> clue_sa, record -> asset_type, record -> deltaz, record -> distance, record -> grade1in, record ->mcc_id, record -> mccid_int, record -> rlmax, record -> rlmin, record -> segside, record -> statusid, record -> streetid, record -> street_group, record -> start_lat, record -> start_lon, record -> end_lat, record -> end_lon);
}

/***
 * Freeing the record struct after it is used.
 ***/
void free_record(record_t* record){
    free(record -> address);
    free(record -> clue_sa);
    free(record -> asset_type);
    free(record -> segside);
    free(record);
}
