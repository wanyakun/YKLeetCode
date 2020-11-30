//
//  NO45.c
//  NO45
//
//  Created by wanyakun on 2020/11/30.
//

#include "NO45.h"

int max(int a, int b) {
    return a > b ? a : b;
}
int jump(int* nums, int numsSize){
    // 代表可跳跃的最远距离
    int farthest = 0;
    // 代表当前这次跳跃可以到达的最远位置
    int end = 0;
    // 代表跳跃次数
    int jumps = 0;
    for(int i = 0; i < numsSize-1; i++) {
        farthest = max(farthest, i+nums[i]);
        if(end == i) {
            end = farthest;
            jumps++;
        }
    }
    return jumps;
}
