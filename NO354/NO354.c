//
//  NO354.c
//  NO354
//
//  Created by wanyakun on 2020/11/29.
//

#include "NO354.h"
#include <stdlib.h>
#include <string.h>

int cmp(const void * _a, const void * _b) {
    int* a = *(int **)_a;
    int* b = *(int **)_b;
    return a[0] == b[0] ? b[1] - a[1] : a[0] - b[0];
}

int lengthOfLIS(int* nums, int numsSize) {
    // 二分查找
    // 存储堆顶数据
    int* top = malloc(numsSize*sizeof(int));
    memset(top, 0, numsSize*sizeof(int));
    // 存储堆个数
    int piles = 0;
    for(int i = 0; i < numsSize; i++) {
        int poker = nums[i];
        int left = 0, right = piles;
        while(left < right) {
            int mid = (left + right) / 2;
            if(poker <= top[mid]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        // 没有堆可以放，新建堆
        if(left == piles) piles++;
        // 讲poker放到堆顶
        top[left] = poker;
    }
    return piles;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    // base case
    if(envelopesSize == 0) return 0;
    // 安装宽度升序，高度降序排序
    qsort(envelopes, envelopesSize, sizeof(int*), cmp);
    // 存储高度数组
    int* height = malloc(envelopesSize*sizeof(int));
    for(int i = 0; i < envelopesSize; i++) {
        height[i] = envelopes[i][1];
    }
    return lengthOfLIS(height, envelopesSize);
}
