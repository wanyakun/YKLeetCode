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
    char* s = malloc(4*sizeof(char));
    strcpy(s, _s);
    if(s[j] == '9') {
        s[j] = '0';
    } else {
        s[j] += 1;
    }
    return s;
}

char* minusOne(char* _s, int j) {
    char* s = malloc(4*sizeof(char));
    strcpy(s, _s);
    if(s[j] == '0') {
        s[j] = '9';
    } else {
        s[j] -= 1;
    }
    return s;
}

bool contains(char** cstr, int cstrSize, char* s) {
    bool res = false;
    for(int i = 0; i < cstrSize; i++) {
        if(strncmp(cstr[i], s, 4) == 0) {
            res = true;
            break;
        }
    }
    return res;
}

int openLock(char ** deadends, int deadendsSize, char * target){
    char** queue = malloc(sizeof(char*));
    queue[0] = "0000";
    char** visited = malloc(sizeof(char*));
    visited[0] = "0000";
    int index = 0, length = 1, step = 0, visitedSize = 1;
    while(index < length) {
        int size = length - index;
        for(int i = 0; i < size; i++) {
            char* curr = queue[index++];
            // 判断是否到的终点
            if(contains(deadends, deadendsSize, curr)) continue;
            if(strncmp(curr, target, 4) == 0) {
                free(visited);
                free(queue);
                return step;
            }
            // 展开
            for(int j = 0; j < 4; j++) {
                char* up = plusOne(curr, j);
                if(!contains(visited, visitedSize, up)) {
                    queue = realloc(queue, (++length)*sizeof(char*));
                    queue[length-1] = up;
                    visited = realloc(visited, (++visitedSize)*sizeof(char*));
                    visited[visitedSize-1] = up;
                }
                char* down = minusOne(curr, j);
                if(!contains(visited, visitedSize, down)) {
                    queue = realloc(queue, (++length)*sizeof(char*));
                    queue[length-1] = down;
                    visited = realloc(visited, (++visitedSize)*sizeof(char*));
                    visited[visitedSize-1] = down;
                }
            }
        }
        step++;
    }
    free(visited);
    free(queue);
    return -1;
}

