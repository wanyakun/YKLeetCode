//
//  NO973.c
//  NO973
//
//  Created by wanyakun on 2020/11/9.
//

#include "NO973.h"
#include <stdlib.h>

int cmp(const void* _a, const void* _b) {
    int* a = *(int **)_a;
    int* b = *(int **)_b;
    return a[0]*a[0] + a[1]*a[1] - b[0]*b[0] - b[1]*b[1];
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    int** res = malloc(K*sizeof(int*));
    *returnSize = K;
    *returnColumnSizes = malloc(K*sizeof(int));
    qsort(points, pointsSize, sizeof(int*), cmp);
    for (int i = 0; i < K; i++) {
        res[i] = malloc(2*sizeof(int));
        res[i][0] = points[i][0];
        res[i][1] = points[i][1];
        (*returnColumnSizes)[i] = 2;
    }
    return res;
}
