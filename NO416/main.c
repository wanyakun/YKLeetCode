//
//  main.c
//  NO416
//
//  Created by wanyakun on 2020/11/26.
//

#include <stdio.h>
#include "NO416.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[4] = {1,5,11,5};
    int res = canPartition1(nums, 4);
    printf("%d \n", res);
    return 0;
}
