//
//  main.c
//  NO283
//
//  Created by wanyakun on 2020/11/19.
//

#include <stdio.h>
#include "NO283.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[5] = {0,1,0,3,12};
    moveZeroes(nums, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", nums[i]);
    }
    printf("\n");
    return 0;
}
