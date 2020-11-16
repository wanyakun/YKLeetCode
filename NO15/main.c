//
//  main.c
//  NO15
//
//  Created by wanyakun on 2020/11/16.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO15.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    [-7,-4,-6,6,4,-6,-9,-10,-7,5,3,-1,-5,8,-1,-2,-8,-1,5,-3,-5,4,2,-5,-4,4,7]
//    int* nums = malloc(6*sizeof(int));
//    nums[0] = -1;
//    nums[1] = 0;
//    nums[2] = 1;
//    nums[3] = 2;
//    nums[4] = -1;
//    nums[5] = -4;
    
    int* nums = malloc(27*sizeof(int));
    nums[0] = -7;
    nums[1] = -4;
    nums[2] = -6;
    nums[3] = 6;
    nums[4] = 4;
    nums[5] = -6;
    nums[6] = -9;
    nums[7] = -10;
    nums[8] = -7;
    nums[9] = 5;
    nums[10] = 3;
    nums[11] = -1;
    nums[12] = -5;
    nums[13] = 8;
    nums[14] = -1;
    nums[15] = -2;
    nums[16] = -8;
    nums[17] = -1;
    nums[18] = 5;
    nums[19] = -3;
    nums[20] = -5;
    nums[21] = 4;
    nums[22] = 2;
    nums[23] = -5;
    nums[24] = -4;
    nums[25] = 4;
    nums[26] = 7;

    int returnSize;
    int* returnColumnSizes;
    int** res = threeSum(nums, 27, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d, %d] \n", res[i][0], res[i][1], res[i][2]);
    }

    return 0;
}
