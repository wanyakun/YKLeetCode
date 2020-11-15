//
//  main.c
//  NO198
//
//  Created by wanyakun on 2020/11/15.
//

#include <stdio.h>
#include "NO198.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[4] = {1,2,3,1};
    int res = rob(nums, 4);
    printf("%d \n", res);
    
    return 0;
}
