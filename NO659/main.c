//
//  main.c
//  NO659
//
//  Created by wanyakun on 2020/12/4.
//

#include <stdio.h>
#include <stdbool.h>
#include "NO659.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[6] = {1,2,3,3,4,5};
    bool res = isPossible(nums, 6);
    printf("%d \n", res);
    return 0;
}
