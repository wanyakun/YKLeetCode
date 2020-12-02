//
//  main.c
//  NO321
//
//  Created by wanyakun on 2020/12/2.
//

#include <stdio.h>
#include "NO321.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums1[4] = {3,4,6,5};
    int nums2[6] = {9,1,2,5,8,3};
    int k = 5;
    int returnSize = 0;
    int* res = maxNumber(nums1, 4, nums2, 6, k, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d,", res[i]);
    }
    printf("\n");
    return 0;
}
