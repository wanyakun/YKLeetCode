//
//  main.c
//  NO861
//
//  Created by wanyakun on 2020/12/7.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO861.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int** A = malloc(3*sizeof(int*));
    A[0] = malloc(4*sizeof(int));
    A[0][0] = 0;
    A[0][1] = 0;
    A[0][2] = 1;
    A[0][3] = 1;
    A[1] = malloc(4*sizeof(int));
    A[1][0] = 1;
    A[1][1] = 0;
    A[1][2] = 1;
    A[1][3] = 0;
    A[2] = malloc(4*sizeof(int));
    A[2][0] = 1;
    A[2][1] = 1;
    A[2][2] = 0;
    A[2][3] = 0;
    int AColSize[3] = {4,4,4};
    int res = matrixScore(A, 3, AColSize);
    printf("%d \n", res);
    return 0;
}
