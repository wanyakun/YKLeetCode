//
//  NO976.c
//  NO976
//
//  Created by wanyakun on 2020/11/29.
//

#include "NO976.h"
#include <stdlib.h>

int cmp(const void* _a, const void* _b) {
    int a = *(int *)_a;
    int b = *(int *)_b;
    return a -b;
}
int largestPerimeter(int* A, int ASize){
    qsort(A, ASize, sizeof(int), cmp);
    int i = ASize - 1;
    while(i - 2 >= 0) {
        if(A[i-2] + A[i-1] > A[i]) {
            return A[i] + A[i-1] + A[i-2];
        } else {
            i--;
        }
    }
    return 0;
}
