//
//  NO842.c
//  NO842
//
//  Created by wanyakun on 2020/12/8.
//

#include "NO842.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool backtrack(int* list, int* listSize, char* S, int length, int index, long long sum, int pre) {
    if(index == length) return (*listSize) >= 3;
    long long curr = 0;
    for(int i = index; i < length; i++) {
        // 0 开头不可以拆分
        if(i > index && S[index] == '0') {
            break;
        }
        curr = curr*10 + S[i] - '0';
        // 超出最大值，不可再分割
        if(curr > INT_MAX) {
            break;
        }
        // 如果列表中的个数大于等于2，则要判断当前值和前面两个值和的关系
        if((*listSize) >= 2) {
            if(curr < sum) {
                continue;
            } else if(curr > sum) {
                break;
            }
        }
        // curr = sum满足斐波那契, 做选择
        list[(*listSize)++] = curr;
        // 回溯
        if(backtrack(list, listSize, S, length, i+1, pre+curr, curr)) {
            return true;
        }
        // 撤销选择
        (*listSize)--;

    }
    return false;
}

int* splitIntoFibonacci(char * S, int* returnSize){
    int n = strlen(S);
    int* list = malloc(n*sizeof(int));
    *returnSize = 0;
    backtrack(list, returnSize, S, n, 0, 0, 0);
    return list;
}
