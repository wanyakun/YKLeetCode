//
//  NO922.c
//  NO922
//
//  Created by wanyakun on 2020/11/12.
//

#include "NO922.h"
#include <stdlib.h>

int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int* res = malloc(ASize*sizeof(int));
    *returnSize = ASize;
    int m = 0, n = 0;
    for (int i = 0; i < ASize; i++) {
        if(i%2 == 0) {
            // 寻找偶数
            for(int j = m; j < ASize; j++) {
                if(A[j]%2 == 0) {
                    res[i] = A[j];
                    m = j;
                    break;
                }
            }
        } else {
            // 寻找奇数
            for(int j = n; j < ASize; j++) {
                if(A[j]%2 == 1) {
                    res[i] = A[j];
                    n = j;
                    break;
                }
            }
        }
    }
    return res;
}

int* sortArrayByParityII2(int* A, int ASize, int* returnSize){
    int* res = malloc(ASize*sizeof(int));
    *returnSize = ASize;
    int m = 0, n = 1;
    for (int i = 0; i < ASize; i++) {
        if(A[i]%2 == 0) {
            // 偶数
            res[m] = A[i];
            m += 2;
        } else {
            // 奇数
            res[n] = A[i];
            n += 2;
        }
    }
    return res;
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int* sortArrayByParityII3(int* A, int ASize, int* returnSize){
    int j = 1;
    for (int i = 0; i < ASize; i += 2) {
        if(A[i]%2 == 1) {
            while(A[j]%2 == 1) {
                j += 2;
            }
            swap(&A[i], &A[j]);
        }
    }
    *returnSize = ASize;
    return A;
}
