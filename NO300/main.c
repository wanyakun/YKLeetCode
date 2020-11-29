//
//  main.c
//  NO300
//
//  Created by wanyakun on 2020/11/29.
//

#include <stdio.h>
#include "NO300.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[8] = {10,9,2,5,3,7,101,18};
    int res = lengthOfLIS1(nums, 8);
    printf("%d \n", res);
    return 0;
}
