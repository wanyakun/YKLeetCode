//
//  NO376.c
//  NO376
//
//  Created by wanyakun on 2020/12/12.
//

#include "NO376.h"
#include <math.h>

// 动态规划+状态压缩
int wiggleMaxLength(int* nums, int numsSize){
    if(numsSize < 2) {
        return numsSize;
    }
    int up = 1; // 表示前i个数字中上升摆动序列
    int down = 1; // 表示前i个数字中下降摆动序列
    for(int i = 1; i < numsSize; i++) {
        // 状态转移
        if(nums[i] < nums[i-1]) {
            down = fmax(up+1, down); // 下降为前一个下降或者前一个上升+1
        } else if(nums[i] > nums[i-1]) {
            up = fmax(down+1, up);
        }
    }
    return fmax(up, down);
}
 // 动态规划
 int wiggleMaxLength1(int* nums, int numsSize){
     if(numsSize < 2) {
         return numsSize;
     }
     int up[numsSize]; // 表示前i个数字中上升摆动序列
     int down[numsSize]; // 表示前i个数字中下降摆动序列
     up[0] = down[0] = 1; // base case
     for(int i = 1; i < numsSize; i++) {
         // 状态转移
         if(nums[i] < nums[i-1]) {
             up[i] = up[i-1]; // 上升和前一个相同
             down[i] = fmax(up[i-1]+1, down[i-1]); // 下降为前一个下降或者前一个上升+1
         } else if(nums[i] > nums[i-1]) {
             up[i] = fmax(down[i-1]+1, up[i-1]);
             down[i] = down[i-1];
         } else {
             up[i] = up[i-1];
             down[i] = down[i-1];
         }
     }
     return fmax(up[numsSize-1], down[numsSize-1]);
 }
