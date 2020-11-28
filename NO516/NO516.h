//
//  NO516.h
//  NO516
//
//  Created by wanyakun on 2020/11/28.
//
/**
 516. 最长回文子序列
 难度
 中等

 336





 给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

  

 示例 1:
 输入:

 "bbbab"
 输出:

 4
 一个可能的最长回文子序列为 "bbbb"。

 示例 2:
 输入:

 "cbbd"
 输出:

 2
 一个可能的最长回文子序列为 "bb"。

  

 提示：

 1 <= s.length <= 1000
 s 只包含小写英文字母
 */
#ifndef NO516_h
#define NO516_h

#include <stdio.h>

int longestPalindromeSubseq(char * s);
int longestPalindromeSubseq1(char * s);

#endif /* NO516_h */
