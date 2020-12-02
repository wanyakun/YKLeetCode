//
//  NO583.h
//  NO583
//
//  Created by wanyakun on 2020/11/30.
//
/**
 583. 两个字符串的删除操作
 给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

  

 示例：

 输入: "sea", "eat"
 输出: 2
 解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
  

 提示：

 给定单词的长度不超过500。
 给定单词中的字符只含有小写字母。
 */
#ifndef NO583_h
#define NO583_h

#include <stdio.h>

int minDistance(char * word1, char * word2);
int minDistance1(char * word1, char * word2);

#endif /* NO583_h */