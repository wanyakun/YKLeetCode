//
//  main.c
//  NO454
//
//  Created by wanyakun on 2020/11/27.
//

#include <stdio.h>
#include "NO454.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int A[2] = {1,2};
    int B[2] = {-2,-1};
    int C[2] = {-1,2};
    int D[2] = {0,2};
    
    int res = fourSumCount(A, 2, B, 2, C, 2, D, 2);
    printf("%d \n", res);
    
    return 0;
}
