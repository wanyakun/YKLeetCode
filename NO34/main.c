//
//  main.c
//  NO34
//
//  Created by wanyakun on 2020/11/12.
//

#include <stdio.h>
#include "NO34.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int* nums = malloc(6*sizeof(int));
    nums[0] = 5;
    nums[1] = 7;
    nums[2] = 7;
    nums[3] = 8;
    nums[4] = 8;
    nums[5] = 10;
    
    int target = 8;
    
    int returnSize = 0;
    int *res = searchRange(nums, 6, target, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ,", res[i]);
    }
    printf("] \n");

    return 0;
}
