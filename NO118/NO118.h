//
//  NO118.h
//  NO118
//
//  Created by wanyakun on 2020/12/6.
//
/**
 118. 杨辉三角
 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。



 在杨辉三角中，每个数是它左上方和右上方的数的和。

 示例:

 输入: 5
 输出:
 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
 ]
 */
#ifndef NO118_h
#define NO118_h

#include <stdio.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

#endif /* NO118_h */
