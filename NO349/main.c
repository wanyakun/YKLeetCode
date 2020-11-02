//
//  main.c
//  NO349
//
//  Created by wanyakun on 2020/11/2.
//

#include <stdio.h>
#include "NO349.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int* nums1 = malloc(sizeof(int)*4);
    nums1[0] = 1;
    nums1[1] = 2;
    nums1[2] = 2;
    nums1[3] = 1;

    int* nums2 = malloc(sizeof(int)*2);
    nums2[0] = 2;
    nums2[1] = 2;

    int returnSize;
    int* result = intersection1(nums1, 4, nums2, 2, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    
    return 0;
}
