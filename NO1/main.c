//
//  main.c
//  NO1
//
//  Created by wanyakun on 2020/11/16.
//

#include <stdio.h>
#include "NO1.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* res = twoSum(nums, 4, target, &returnSize);
    printf("[%d, %d] \n", res[0], res[1]);
    return 0;
}
