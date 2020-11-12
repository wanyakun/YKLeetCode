//
//  NO752.c
//  NO752
//
//  Created by wanyakun on 2020/11/9.
//

#include "NO752.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* plusOne(char* _s, int j) {
    char* s = malloc(5*sizeof(char));
    memcpy(s, _s, 5*sizeof(char));
    if(s[j] == '9') {
        s[j] = '0';
    } else {
        s[j] += 1;
    }
    return s;
}

char* minusOne(char* _s, int j) {
    char* s = malloc(5*sizeof(char));
    memcpy(s, _s, 5*sizeof(char));
    if(s[j] == '0') {
        s[j] = '9';
    } else {
        s[j] -= 1;
    }
    return s;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    char** queue = malloc(10000*sizeof(char*));
    queue[0] = "0000";
    int* visited = malloc(10000*sizeof(int));
    memset(visited, 0, 10000*sizeof(int));
    for(int i = 0; i < deadendsSize; i++) {
        visited[atoi(deadends[i])] = 1;
    }
    if(visited[atoi("0000")] == 1) return -1;
    visited[atoi("0000")] = 1;
    int index = 0, length = 1, step = 0;
    while(index < length) {
        int size = length - index;
        for(int i = 0; i < size; i++) {
            char* curr = queue[index++];
            // 判断是否到的终点
            // if(visited[atoi(curr)] == 1) continue;
            if(strncmp(curr, target, 4) == 0) {
                free(visited);
                free(queue);
                return step;
            }
            // 展开
            for(int j = 0; j < 4; j++) {
                char* up = plusOne(curr, j);
                if(visited[atoi(up)] == 0) {
                    queue[length++] = up;
                    visited[atoi(up)] = 1;
                }
                char* down = minusOne(curr, j);
                if(visited[atoi(down)] == 0) {
                    queue[length++] = down;
                    visited[atoi(down)] = 1;
                }
            }
        }
        step++;
    }
    free(visited);
    free(queue);
    return -1;
}

