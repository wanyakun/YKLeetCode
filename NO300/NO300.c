//
//  NO300.c
//  NO300
//
//  Created by wanyakun on 2020/11/29.
//

#include "NO300.h"
#include <stdlib.h>
#include <string.h>

// 二分法
int lengthOfLIS(int* nums, int numsSize){
    // 存储堆顶元素
    int* top = malloc(numsSize*sizeof(int));
    memset(top, 0, numsSize*sizeof(int));
    // 牌堆个数
    int piles = 0;
    for(int i = 0; i < numsSize; i++) {
        // 要处理的扑克牌
        int poker = nums[i];
        int left = 0, right = piles;
        while(left < right) {
            int mid = (left + right)/2;
            if(poker <= top[mid]) {
                right = mid;
            } else if (poker > top[mid]) {
                left = mid + 1;
            }
        }
        // 没有找到合适的堆, 新建一堆
        if(left == piles) {
            piles++;
        }
        // 扑克放到堆顶
        top[left] = poker;
    }
    return piles;
}

// 动态规划
 int max(int a, int b) {
     return a > b ? a : b;
 }
 int lengthOfLIS1(int* nums, int numsSize){
     int* dp = malloc(numsSize*sizeof(int));
     // base case
     for(int i = 0; i < numsSize; i++) {
         dp[i] = 1;
     }
     for(int i = 0; i < numsSize; i++) {
         for(int j = 0; j < i; j++) {
             if(nums[j] < nums[i]) {
                 dp[i] = max(dp[i], dp[j]+1);
             }
         }
     }
     int res = 0;
     for(int i = 0; i < numsSize; i++) {
         res = max(res, dp[i]);
     }
     return res;
 }
