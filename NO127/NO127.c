//
//  NO127.c
//  NO127
//
//  Created by wanyakun on 2020/11/5.
//

#include "NO127.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canChange(char* a, char* b) {
    int len = (int)strlen(a);
    int cnt = 0;
    for (int i =0; i < len; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
        if (cnt > 1) {
            return false;
        }
    }
    return true;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize){
    char** queue = malloc(sizeof(char*)); // 核心数据结构
    int start = 0, end = 0; // 标记当前层的开始和结束
    int flag[wordListSize]; // 避免走回头路
    memset(flag, 0, sizeof(int)*wordListSize);
    
    queue[end++] = beginWord;   // 将起点加入到队列
    int changeNum = 1;  // 记录单词变换次数
    
    while (start < end) {
        int currentLevelNum = end - start;
        // 将当前队列中所有节点向四周扩散
        for (int i = 0; i < currentLevelNum; i++) {
            char* curr = queue[start + i];
            // 判断是否到的终点
            if (strcmp(curr, endWord) == 0) {
                return changeNum;
            }
            // 将和curr能够转换的单词加入到队列中
            for (int j = 0; j < wordListSize; j++) {
                if (flag[j] == 0 && canChange(curr, wordList[j])) {
                    queue = realloc(queue, (end+1)*sizeof(char*));
                    queue[end++] = wordList[j];
                    flag[j] = 1;
                }
            }
        }
        start += currentLevelNum;
        changeNum++;
    }
    return 0;
}
