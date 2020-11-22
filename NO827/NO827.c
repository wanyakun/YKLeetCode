//
//  NO827.c
//  NO827
//
//  Created by wanyakun on 2020/11/22.
//

#include "NO827.h"
#include "uthash.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    char key;
    int cnt;
    UT_hash_handle hh;
} unordered_map;

bool isAnagram(char * s, char * t){
    int sLen = strlen(s);
    int tLen = strlen(t);
    if(sLen != tLen) return false;
    unordered_map* memo = NULL;
    for(int i = 0; i < sLen; i++) {
        unordered_map* tmp = NULL;
        HASH_FIND(hh, memo, &s[i], sizeof(char), tmp);
        if(tmp == NULL) {
            tmp = malloc(sizeof(unordered_map));
            tmp->key = s[i];
            tmp->cnt = 1;
            HASH_ADD(hh, memo, key, sizeof(char), tmp);
        } else {
            tmp->cnt += 1;
        }
    }
    for(int i = 0; i < tLen; i++) {
        unordered_map* tmp = NULL;
        HASH_FIND(hh, memo, &t[i], sizeof(char), tmp);
        if(tmp == NULL || tmp->cnt == 0) {
            return false;
        } else {
            tmp->cnt -= 1;
        }
    }
    return true;
}
