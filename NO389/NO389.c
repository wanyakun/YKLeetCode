//
//  NO389.c
//  NO389
//
//  Created by wanyakun on 2020/12/18.
//

#include "NO389.h"
#include <stdlib.h>
#include <string.h>

#pragma mark - 排序后比较
int cmp(const void * _a, const void * _b) {
    char a = *(char *)_a;
    char b = *(char *)_b;
    return a - b;
}

char findTheDifference(char * s, char * t){
    qsort(s, strlen(s), sizeof(char), cmp);
    qsort(t, strlen(t), sizeof(char), cmp);
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] != t[i]) {
            return t[i];
        }
    }
    return t[strlen(t)-1];
}
#pragma mark - 计数
char findTheDifference1(char * s, char * t){
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }
    for (int i = 0; i < m; i++) {
        cnt[t[i]-'a']--;
        if (cnt[t[i]-'a'] < 0) {
            return t[i];
        }
    }
    return ' ';
}

#pragma mark - 求和
char findTheDifference2(char * s, char * t){
    int n = strlen(s), m = strlen(t);
    int as = 0, at = 0;
    for (int i = 0; i < n; i++) {
        as += s[i];
    }
    for (int i = 0; i < m; i++) {
        at += t[i];
    }
    return at - as;
}

#pragma mark - 位运算
// 将两个字符串合并成一个字符串，则问题转换成求字符串中出现奇数次的字符串
char findTheDifference3(char * s, char * t){
    int n = strlen(s), m = strlen(t);
    int res = 0;
    for (int i = 0; i < n; i++) {
        res ^= s[i];
    }
    for (int i = 0; i < m; i++) {
        res ^= t[i];
    }
    return res;
}
