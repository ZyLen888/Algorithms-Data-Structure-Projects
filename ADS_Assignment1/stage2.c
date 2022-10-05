//
// Created by Zhen Liu (Meimi Liu) on 18/08/2022.
//

#include "stage2.h"

int stage_two (char* in_file, char* out_file){

    // 1. read data & build linked list
    FILE* input = fopen(in_file, "r");
    FILE* output = fopen(out_file, "w");

    list_t* dictionary = read_csv(input);

    char* query = (char*)malloc(sizeof(char) * MAX_STR_LENGTH + 1);

    // 2. build sorted array (ed 3.8)

    // 2.1 create empty array
    array_t* sorted_arr = arrayCreate(); //⭐️ 这么做对吗？

    // 2.2 循环list里面的所有node

    // looping through the whole linked list in order to search and print out matched records
    node_t* curr = dictionary -> head; //⭐️ 这里的循环对吗？
    assert(dictionary!=NULL);

    while (curr) {
        // 2.3 把每一个node的pointer都sorted insert到array里
        sortedArrayInsert(sorted_arr, curr);
        curr = curr -> next;
    }

    // 2.4 array shrink 去掉多余的空间
    arrayShrink(sorted_arr);


    // 3. search query & output
    // 3.1 while loop scanf query得到一个string //⭐️ 这里是对的吗？
        // read stdin query
        char* end_ptr;

        while(scanf(" %[^\n]", query) == 1){

            // 3.2 把这个string转换成double，使用得到的query double进行search
            double double_query = strtod(query,&end_ptr);
            node_t* result = arraySearch(sorted_arr, double_query);

            // 3.3 把找到的node储存的struct print到output file
            print_record(output, result -> data);

            // 3.4 print 找到的node的struct的grade1in 到stdout // ⭐️ 这个正确吗？
            printf("%s --> %lf\n", query, result -> data -> grade1in);
        }

    //4. close file, free linked list, free array

    // free list
    free_list(dictionary);
    arrayFree(sorted_arr);
    fclose(input);

    }



