//
//  NO14.h
//  NO14
//
//  Created by wanyakun on 2020/12/11.
//
/**
 14. 最长公共前缀
 编写一个函数来查找字符串数组中的最长公共前缀。

 如果不存在公共前缀，返回空字符串 ""。

 示例 1:

 输入: ["flower","flow","flight"]
 输出: "fl"
 示例 2:

 输入: ["dog","racecar","car"]
 输出: ""
 解释: 输入不存在公共前缀。
 说明:

 所有输入只包含小写字母 a-z 。
 */
#ifndef NO14_h
#define NO14_h

#include <stdio.h>

char * longestCommonPrefix(char ** strs, int strsSize);
char * longestCommonPrefix1(char ** strs, int strsSize);

#endif /* NO14_h */
