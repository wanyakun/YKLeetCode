//
//  main.c
//  NO55
//
//  Created by wanyakun on 2020/11/30.
//

#include <stdio.h>
#include "NO55.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[5] = {2,3,1,1,4};
    bool res = canJump(nums, 5);
    printf("%d \n", res);
    return 0;
}
