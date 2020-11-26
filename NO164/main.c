//
//  main.c
//  NO164
//
//  Created by wanyakun on 2020/11/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO164.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[4] = {3,6,9,1};
    int res = maximumGap(nums, 4);
    printf("%d \n", res);
    return 0;
}
