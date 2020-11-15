//
//  NO986.c
//  NO986
//
//  Created by wanyakun on 2020/11/15.
//

#include "NO986.h"
#include <stdlib.h>

int max(int a, int b) {
     return a > b ? a : b;
 }
 int min(int a, int b) {
     return a < b ? a : b;
 }
int** intervalIntersection(int** A, int ASize, int* AColSize, int** B, int BSize, int* BColSize, int* returnSize, int** returnColumnSizes){
    int i = 0, j = 0; // 双指针，游走于A和B
    int** res = malloc((ASize+BSize)*sizeof(int**));
    (*returnColumnSizes) = malloc((ASize+BSize)*sizeof(int));
    (*returnSize) = 0;
    while(i < ASize && j < BSize) {
        int a1 = A[i][0], a2 = A[i][1], b1 = B[j][0], b2 = B[j][1];
        // a2 < b1 || b2 < a1 无交集情况，所以取反
        if(a2 >= b1 && b2 >= a1) {
            // 计算交集，加入res
            int* tmp = malloc(2*sizeof(int));
            tmp[0] = max(a1, b1);
            tmp[1] = min(a2, b2);
            res[(*returnSize)] = tmp;
            (*returnColumnSizes)[(*returnSize)] = 2;
            (*returnSize)++;
        }
        // 指针前进
        if(a2 <= b2) {
            i++;
        } else {
            j++;
        }
    }
    return res;
}
