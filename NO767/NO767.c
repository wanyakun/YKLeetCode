//
//  NO767.c
//  NO767
//
//  Created by wanyakun on 2020/11/30.
//

#include "NO767.h"
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}
char * reorganizeString(char * S){
    int length = strlen(S);
    if (length == 2) {
        return S;
    }
    int* count = malloc(26*sizeof(int));
    memset(count, 0, 26*sizeof(int));
    // 记录最多字母的个数
    int maxCount = 0;
    // 统计每个字母的个数，并放入数组count中
    for(int i = 0; i < length; i++) {
        count[S[i]-'a']++;
        maxCount = max(maxCount, count[S[i]-'a']);
    }
    // 最多字母个数超过总长度的一般，无法重新排序
    if(maxCount > (length+1)/2) return "";
    // 通过队列存储大于0的字符
    char* queue = malloc(length*sizeof(char));
    int qIndex = 0;
    int qSize = 0;
    // 将数量大于0的字符放入队列中
    for(char c = 'a'; c <= 'z'; c++) {
        if(count[c-'a'] > 0) {
            queue[qSize++] = c;
        }
    }
    // 重构后的字符串
    char* res = malloc(length*sizeof(char));
    int resSize = 0;
    while(qSize - qIndex > 1 ) {
        // 从队列中取出两个字符，放到res中
        char letter1 = queue[qIndex++];
        char letter2 = queue[qIndex++];
        res[resSize++] = letter1;
        res[resSize++] = letter2;
        count[letter1-'a']--;
        count[letter2-'a']--;
        // 再次从数组count中取字符letter1和letter2放入队列
        if(count[letter1-'a'] > 0) {
            queue[qSize++] = letter1;
        }
        if(count[letter2-'a'] > 0) {
            queue[qSize++] = letter2;
        }
    }
    if(qSize - qIndex > 0) {
        res[resSize++] = queue[qIndex];
    }
    return res;
}

char * reorganizeString1(char * S){
    int length = strlen(S);
    int* count = malloc(26*sizeof(int));
    memset(count, 0, 26*sizeof(int));
    // 记录最多字母的个数
    int maxCount = 0;
    // 统计每个字母的个数，并放入数组count中
    for(int i = 0; i < length; i++) {
        count[S[i]-'a']++;
        maxCount = max(maxCount, count[S[i]-'a']);
    }
    // 最多字母个数超过总长度的一般，无法重新排序
    if(maxCount > (length+1)/2) return "";
    // 通过队列存储大于0的字符
    char* res = malloc((length+1)*sizeof(char));
    int halfLength = length/2;
    for(int i = 0; i < length; i++) {
        res[i] = ' ';
    }
    res[length] = '\0';
    int evenIndex = 0, oddIndex = 1; // 偶数和积数位置索引
    for(int i = 0; i < 26; i++) {
        char c = i + 'a';
        // 优先放入奇数位置
        while(count[i] > 0 && count[i] <= halfLength && oddIndex < length) {
            res[oddIndex] = c;
            count[i]--;
            oddIndex += 2;
        }
        while(count[i] > 0) {
            res[evenIndex] = c;
            count[i]--;
            evenIndex += 2;
        }
    }
    return res;
}
