//
//  NO46.h
//  NO46
//
//  Created by wanyakun on 2020/11/2.
//
/**
 46. 全排列
 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

 示例:

 输入: [1,2,3]
 输出:
 [
   [1,2,3],
   [1,3,2],
   [2,1,3],
   [2,3,1],
   [3,1,2],
   [3,2,1]
 ]
 */
#ifndef NO46_h
#define NO46_h

#include <stdio.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

#endif /* NO46_h */
