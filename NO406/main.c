//
//  main.c
//  NO406
//
//  Created by wanyakun on 2020/11/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO406.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int** people = malloc(6*sizeof(int*));
    people[0] = malloc(2*sizeof(int));
    people[0][0] = 7;
    people[0][1] = 0;
    people[1] = malloc(2*sizeof(int));
    people[1][0] = 4;
    people[1][1] = 4;
    people[2] = malloc(2*sizeof(int));
    people[2][0] = 7;
    people[2][1] = 1;
    people[3] = malloc(2*sizeof(int));
    people[3][0] = 5;
    people[3][1] = 0;
    people[4] = malloc(2*sizeof(int));
    people[4][0] = 6;
    people[4][1] = 1;
    people[5] = malloc(2*sizeof(int));
    people[5][0] = 5;
    people[5][1] = 2;
        
    int peopleColSize[6] = {2,2,2,2,2,2};
    
    int returnSize;
    int* returnColSize;
    int** res = reconstructQueue(people, 6, peopleColSize, &returnSize, &returnColSize);
    
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColSize[i]; j++) {
            int num = res[i][j];
            printf("%d, ", num);
        }
        printf("]");
    }
    printf("] \n");
    
    return 0;
}
