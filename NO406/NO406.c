//
//  NO406.c
//  NO406
//
//  Created by wanyakun on 2020/11/16.
//

#include "NO406.h"
#include <stdlib.h>

int cmp(const void* _a, const void* _b) {
    int* a = *(int**)_a;
    int* b = *(int**)_b;
    return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
}
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    qsort(people, peopleSize, sizeof(int*), cmp);
    int** res = malloc(peopleSize*sizeof(int*));
    (*returnSize) = peopleSize;
    (*returnColumnSizes) = malloc(peopleSize*sizeof(int));
    for(int i = 0; i < peopleSize; i++) {
        int spaces = people[i][1]+1;
        for(int j = 0; j < peopleSize; j++) {
            if(res[j] == NULL) {
                --spaces;
                if(spaces == 0) {
                    res[j] = malloc(2*sizeof(int)); //people[i];
                    res[j][0] = people[i][0];
                    res[j][1] = people[i][1];
                    (*returnColumnSizes)[j] = 2;
                    break;
                }
            }
        }
    }
    return res;
}
