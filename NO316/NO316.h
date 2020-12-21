//
//  NO316.h
//  NO316
//
//  Created by wanyakun on 2020/12/21.
//
/**
 316. 去除重复字母
 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters 相同

  

 示例 1：

 输入：s = "bcabc"
 输出："abc"
 示例 2：

 输入：s = "cbacdcbc"
 输出："acdb"
  

 提示：

 1 <= s.length <= 104
 s 由小写英文字母组成
 */
#ifndef NO316_h
#define NO316_h

#include <stdio.h>

char * removeDuplicateLetters(char * s);

#endif /* NO316_h */
