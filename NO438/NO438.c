//
//  NO438.c
//  NO438
//
//  Created by wanyakun on 2020/11/13.
//

#include "NO438.h"
#include "uthash.h"
#include <string.h>
#include <limits.h>

typedef struct {
    char c;
    int cnt;
    UT_hash_handle hh;
} unorderd_map;

int* findAnagrams(char * s, char * t, int* returnSize){
    // 初始化容器
    int tLen = (int)strlen(t);
    unorderd_map *need = NULL, *window = NULL;
    for (int i = 0; i < tLen; i++) {
        unorderd_map* tmp = NULL;
        HASH_FIND(hh, need, &t[i], sizeof(char), tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(unorderd_map));
            tmp->c = t[i];
            tmp->cnt = 1;
            HASH_ADD(hh, need, c, sizeof(char), tmp);
        } else {
            tmp->cnt += 1;
        }
        
        unorderd_map* tmp1 = NULL;
        HASH_FIND(hh, window, &t[i], sizeof(char), tmp1);
        if (tmp1 == NULL) {
            tmp1 = malloc(sizeof(unorderd_map));
            tmp1->c = t[i];
            tmp1->cnt = 0;
            HASH_ADD(hh, window, c, sizeof(char), tmp1);
        }
    }
    // 初试窗口变量
    int left = 0, right = 0, valid = 0; // valid代表need中和window中字符数量相同的个数
    int* res = malloc(0);
    *returnSize = 0;
    while (right < strlen(s)) {
        // c代表将要移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一些列更新
        unorderd_map* tNeed = NULL;
        unorderd_map* tWindow = NULL;
        HASH_FIND(hh, need, &c, sizeof(char), tNeed);
        if (tNeed) {
            HASH_FIND(hh, window, &c, sizeof(char), tWindow);
            tWindow->cnt += 1;
            if (tNeed->cnt == tWindow->cnt) {
                valid++;
            }
        }
        
        // 判断左侧窗口是否需要收缩
        while ((right-left) >= strlen(t)) {
            // 在这里更新最小覆盖字符串
            if (valid == HASH_COUNT(need)) {
                // 添加到结果res中
                res = realloc(res, (++(*returnSize))*sizeof(int));
                res[(*returnSize)-1] = left;
            }
            // d代表将要移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            tNeed = NULL;
            HASH_FIND(hh, need, &d, sizeof(char), tNeed);
            if (tNeed) {
                tWindow = NULL;
                HASH_FIND(hh, window, &d, sizeof(char), tWindow);
                if (tWindow->cnt == tNeed->cnt) {
                    valid--;
                }
                tWindow->cnt -= 1;
            }
        }
    }
    return res;
}
