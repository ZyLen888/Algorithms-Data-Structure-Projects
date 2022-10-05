/* Created by Zhen Liu (Meimi Liu) on 18/08/2022.
 * Stage 1: Read in a CSV and enable user to search records with query input
 * Stage 2:
 * */

#include <stdio.h>
#include "stage1.h"
#include "stage2.h"

int main(int argc, char** argv) {

    // check command line argument to identify which program we are running
    if (argv[1] == 1){
        stage_one(argv[2], argv[3]);
    }
    if (argv[1] == 2){
        stage_two(argv[2], argv[3]);
    }


    return 0;
}
