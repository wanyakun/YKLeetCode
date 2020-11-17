//
//  NO1030.c
//  NO1030
//
//  Created by wanyakun on 2020/11/17.
//

#include "NO1030.h"
#include <stdlib.h>
#include <math.h>

int R0, C0;
int cmp(const void* _a, const void* _b) {
    int* a = *(int**)_a;
    int* b = *(int**)_b;
    return abs(a[0]-R0) + abs(a[1]-C0) - abs(b[0]-R0) - abs(b[1]-C0);
}

int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    R0 = r0;
    C0 = c0;
    int** res = malloc(R*C*sizeof(int*));
    (*returnColumnSizes) = malloc(R*C*sizeof(int));
    (*returnSize) = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            res[*returnSize] = malloc(2*sizeof(int));
            res[*returnSize][0] = i;
            res[*returnSize][1] = j;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
        }
    }
    qsort(res, R*C, sizeof(int*), cmp);
    return res;
}
