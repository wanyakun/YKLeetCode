//
//  NO18.h
//  NO18
//
//  Created by wanyakun on 2020/11/16.
//
/**
 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

 注意：

 答案中不可以包含重复的四元组。

 示例：

 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

 满足要求的四元组集合为：
 [
   [-1,  0, 0, 1],
   [-2, -1, 1, 2],
   [-2,  0, 0, 2]
 ]
 */

#ifndef NO18_h
#define NO18_h

#include <stdio.h>

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes);

#endif /* NO18_h */
