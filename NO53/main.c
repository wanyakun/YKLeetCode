//
//  main.c
//  NO53
//
//  Created by wanyakun on 2020/11/29.
//

#include <stdio.h>
#include "NO53.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray1(nums, 9);
    printf("%d \n", res);
    return 0;
}
