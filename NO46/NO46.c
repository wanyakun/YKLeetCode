//
//  NO46.c
//  NO46
//
//  Created by wanyakun on 2020/11/2.
//

#include "NO46.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void backtrack(int** res, int* returnSize, int* nums, int numsSize, int* track, int trackSize, bool* used) {
    // 触发结束条件
    if (trackSize == numsSize) {
        res[*returnSize] = malloc(numsSize*sizeof(int));
        memcpy(res[(*returnSize)++], track, numsSize*sizeof(int));
        return;
    }
    for(int i = 0; i < numsSize; i++) {
        //排除不合理的选择
        if (used[i]) continue;
        // 做选择
        track[trackSize] = nums[i];
        used[i] = true;
        // 进入下一决策
        backtrack(res, returnSize, nums, numsSize, track, trackSize+1, used);
        // 取消选择
        used[i] = false;
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (nums == NULL) return NULL;
    int s = 1;
    for (int i=1 ; i<=numsSize; ++i) s *= i;
    // 记录结果
    int** res = malloc(sizeof(int*)*s);
    // 记录是否使用
    bool* used = malloc(numsSize*sizeof(bool));
    memset(used, 0, numsSize*(sizeof(bool)));
    // 记录路径
    int* track = malloc(sizeof(int)*numsSize);
    *returnSize = 0;
    backtrack(res, returnSize, nums, numsSize, track, 0, used);
    free(used);
    // *returnSize = s;
    *returnColumnSizes = malloc(s*sizeof(int));
    for(int i = 0; i < s; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    
    return res;
}
