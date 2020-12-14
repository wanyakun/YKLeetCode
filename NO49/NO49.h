//
//  NO49.h
//  NO49
//
//  Created by wanyakun on 2020/12/14.
//
/**
 49. 字母异位词分组
 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

 示例:

 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 输出:
 [
   ["ate","eat","tea"],
   ["nat","tan"],
   ["bat"]
 ]
 说明：

 所有输入均为小写字母。
 不考虑答案输出的顺序。
 */
#ifndef NO49_h
#define NO49_h

#include <stdio.h>

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes);
char *** groupAnagrams1(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes);
char *** groupAnagrams2(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes);

#endif /* NO49_h */
