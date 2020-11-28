//
//  main.c
//  NO494
//
//  Created by wanyakun on 2020/11/28.
//

#include <stdio.h>
#include "NO494.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[5] = {1,1,1,1,1};
    int res = findTargetSumWays(nums, 5, 3);
    printf("%d \n", res);
    return 0;
}
