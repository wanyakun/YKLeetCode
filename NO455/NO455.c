//
//  NO455.c
//  NO455
//
//  Created by wanyakun on 2020/12/25.
//

#include "NO455.h"
#include <stdlib.h>

int cmp(const void * _a, const void * _b) {
    int a = *(int *)_a;
    int b = *(int *)_b;
    return a - b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int count = 0;
    for(int i = 0, j = 0; i < gSize && j < sSize; i++, j++) {
        while(j < sSize && g[i] > s[j]) {
            j++;
        }
        if(j < sSize) {
            count++;
        }
    }
    return count;
}
