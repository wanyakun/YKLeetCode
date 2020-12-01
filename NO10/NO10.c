//
//  NO10.c
//  NO10
//
//  Created by wanyakun on 2020/12/1.
//

#include "NO10.h"
#include "uthash.h"
#include <stdlib.h>

typedef struct {
    char* key;
    bool val;
    UT_hash_handle hh;
} HashMap;
HashMap *memo = NULL;
// 暴力递归 i标示s的索引，j表示p的索引
bool dp(char * s, char * p, int i, int j) {
    // 备忘录查找
     char* key = malloc(6*sizeof(char));
     sprintf(key, "%d,%d", i, j);
     HashMap* tmp = NULL;
     HASH_FIND_STR(memo, key, tmp);
     if(tmp) {
         return tmp->val;
     }
    // base case
    if(strlen(p) == j) return strlen(s) == i;
    bool val = false;
    // 匹配'.'字符
    bool first = (i < strlen(s)) && ((p[j] == s[i]) || p[j] == '.');
    if(j <= strlen(p) - 2 && p[j+1] == '*') {
        // 遇到'*', 匹配0次，然后跳过该字符和'*', 或者当s[i]和p[j]匹配后，移动s
        val = dp(s, p, i, j+2) || (first && dp(s, p, i+1, j));
    } else {
        val = first && dp(s, p, i+1, j+1);
    }
    // 结果添加到备忘录
     tmp = malloc(sizeof(HashMap));
     tmp->key = key;
     tmp->val = val;
     HASH_ADD_STR(memo, key, tmp);
    return val;
}

bool isMatch(char * s, char * p){
    return dp(s, p, 0, 0);
}
