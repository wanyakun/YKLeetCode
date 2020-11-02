//
//  main.c
//  NO46
//
//  Created by wanyakun on 2020/11/2.
//

#include <stdio.h>
#include "NO46.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int* nums = malloc(3*sizeof(int));
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    int returnSize;
    int* returnColumSizes;
    int** res = permute(nums, 3, &returnSize, &returnColumSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < *returnColumSizes; j++) {
            printf("%d, ", res[i][j]);
        }
        printf("], \n");
    }
    free(returnColumSizes);
    free(res);
    return 0;
}
