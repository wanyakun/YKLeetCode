//
//  main.c
//  NO704
//
//  Created by wanyakun on 2020/11/10.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO704.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int* nums = malloc(6*sizeof(int));
    nums[0] = -1;
    nums[1] = 0;
    nums[2] = 3;
    nums[3] = 5;
    nums[4] = 9;
    nums[5] = 12;
    int index = search(nums, 6, 9);
    
    printf("%d \n", index);
    return 0;
}
