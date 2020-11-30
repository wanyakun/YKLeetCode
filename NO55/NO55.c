//
//  NO55.c
//  NO55
//
//  Created by wanyakun on 2020/11/30.
//

#include "NO55.h"

int max(int a,  int b) {
    return a > b ? a : b;
}
bool canJump(int* nums, int numsSize){
    // 保持跳跃的最远距离
    int farthest = 0;
    for(int i = 0; i < numsSize-1; i++) {
        // 不断计算最远距离，比较最远距离和当前位置能够跳跃的最远距离
        farthest = max(farthest, i+nums[i]);
        // 可能碰到0了，卡住跳不动了
        if(farthest <= i) return false;
    }
    // 判断是否跳出到最后一个位置
    return farthest >= numsSize-1;
}
