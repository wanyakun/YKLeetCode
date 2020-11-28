//
//  main.c
//  NO493
//
//  Created by wanyakun on 2020/11/28.
//

#include <stdio.h>
#include "NO493.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[5] = {1,3,2,3,1};
    int res = reversePairs(nums, 5);
    printf("%d \n", res);
    return 0;
}
