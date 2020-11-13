//
//  NO3.c
//  NO3
//
//  Created by wanyakun on 2020/11/13.
//

#include "NO3.h"
#include "uthash.h"
#include <stdlib.h>

typedef struct {
    char c;
    int cnt;
    UT_hash_handle hh;
} unorderd_map;

int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLongestSubstring(char * s){
    unorderd_map *window = NULL;
    int left = 0, right = 0, res = 0;
    while(right < strlen(s)) {
        // c代表将要移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一些列更新
        unorderd_map* tWindow = NULL;
        HASH_FIND(hh, window, &c, sizeof(char), tWindow);
        if (tWindow == NULL) {
            tWindow = malloc(sizeof(unorderd_map));
            tWindow->c = c;
            tWindow->cnt = 1;
            HASH_ADD(hh, window, c, sizeof(char), tWindow);
        } else {
            tWindow->cnt += 1;
        }
        while(tWindow->cnt > 1) {
            // d代表将要移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            unorderd_map* tLeft = NULL;
            HASH_FIND(hh, window, &d, sizeof(char), tLeft);
            tLeft->cnt -= 1;
        }
        res = max(res, right-left);
    }
    return res;
}
