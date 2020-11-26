//
//  NO416.h
//  NO416
//
//  Created by wanyakun on 2020/11/26.
//
/**
 416. 分割等和子集
 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

 注意:

 每个数组中的元素不会超过 100
 数组的大小不会超过 200
 示例 1:

 输入: [1, 5, 11, 5]

 输出: true

 解释: 数组可以分割成 [1, 5, 5] 和 [11].
  

 示例 2:

 输入: [1, 2, 3, 5]

 输出: false

 解释: 数组不能分割成两个元素和相等的子集.
 */
#ifndef NO416_h
#define NO416_h

#include <stdio.h>
#include <stdbool.h>

bool canPartition(int* nums, int numsSize);
bool canPartition1(int* nums, int numsSize);

#endif /* NO416_h */
