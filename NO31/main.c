//
//  main.c
//  NO31
//
//  Created by wanyakun on 2020/11/10.
//

#include <stdio.h>
#include "NO31.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int* nums = malloc(3*sizeof(int));
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    
    nextPermutation(nums, 3);
    
    printf("[");
    for (int i = 0; i < 3; i++) {
        printf("%d, ", nums[i]);
    }
    printf("] \n");
    
    return 0;
}
