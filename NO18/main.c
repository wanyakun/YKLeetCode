//
//  main.c
//  NO18
//
//  Created by wanyakun on 2020/11/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO18.h"

int main(int argc, const char * argv[]) {
    // insert code here...

        int* nums = malloc(6*sizeof(int));
        nums[0] = 1;
        nums[1] = 0;
        nums[2] = -1;
        nums[3] = 0;
        nums[4] = -2;
        nums[5] = -2;
    
        int returnSize;
        int* returnColumnSizes;
        int** res = fourSum(nums, 6, 0, &returnSize, &returnColumnSizes);
        
        for (int i = 0; i < returnSize; i++) {
            printf("[%d, %d, %d, %d] \n", res[i][0], res[i][1], res[i][2], res[i][3]);
        }
    return 0;
}
