//
//  main.c
//  NO217
//
//  Created by wanyakun on 2020/12/13.
//

#include <stdio.h>
#include <stdbool.h>
#include "NO217.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[4] = {1,2,3,1};
    bool res = containsDuplicate1(nums, 4);
    printf("%d \n", res);
    return 0;
}
