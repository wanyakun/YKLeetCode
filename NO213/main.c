//
//  main.c
//  NO213
//
//  Created by wanyakun on 2020/11/15.
//

#include <stdio.h>
#include "NO213.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[3] = {2,3,2};
    int res = rob(nums, 3);
    printf("%d \n", res);
    return 0;
}
