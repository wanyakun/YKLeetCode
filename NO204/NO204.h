//
//  NO204.h
//  NO204
//
//  Created by wanyakun on 2020/12/3.
//
/**
 204. 计数质数
 统计所有小于非负整数 n 的质数的数量。

  

 示例 1：

 输入：n = 10
 输出：4
 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 示例 2：

 输入：n = 0
 输出：0
 示例 3：

 输入：n = 1
 输出：0
  

 提示：

 0 <= n <= 5 * 106

 */

#ifndef NO204_h
#define NO204_h

#include <stdio.h>

int countPrimes(int n);
int countPrimes1(int n);
int countPrimes2(int n);
int countPrimes3(int n);

#endif /* NO204_h */
