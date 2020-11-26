//
//  NO164.c
//  NO164
//
//  Created by wanyakun on 2020/11/26.
//

#include "NO164.h"
#include <stdlib.h>

int cmp(const void* _a, const void* _b) {
    int a = *(int *)_a;
    int b = *(int *)_b;
    return a - b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int maximumGap(int* nums, int numsSize){
    if(numsSize <=1 ) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int index = 1;
    int res = 0;
    while(index < numsSize) {
        res = max(res, (nums[index]-nums[index-1]));
        index++;
    }
    return res;
}
