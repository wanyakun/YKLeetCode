//
//  NO290.c
//  NO290
//
//  Created by wanyakun on 2020/12/16.
//

#include "NO290.h"
#include "uthash.h"
#include <stdlib.h>
#include <string.h>


typedef struct {
    int key;
    char* val;
    UT_hash_handle hh;
} HashMap;

typedef struct {
    const char *key;
    int val;
    UT_hash_handle hh;
} HashMap1;

bool wordPattern(char * pattern, char * s){
    if(strlen(pattern) == 0 || strlen(s) == 0) return true;
    // 将s转成字符串数组
    char** strs = malloc(strlen(s)*sizeof(char*));
    char* subStr = strtok(s, " ");
    int strsSize = 0;
    while(subStr != NULL) {
        strs[strsSize] = malloc((sizeof(subStr)+1)*sizeof(char));
        // strcpy(strs[strsSize], subStr);
        strs[strsSize] = subStr;
        strsSize++;
        subStr = strtok(NULL, " ");
    }
    if(strlen(pattern) != strsSize) return false;
    HashMap* map = NULL;
    HashMap1* map1 = NULL;
    for(int i = 0; i < strsSize; i++) {
        int tkey = pattern[i] - 'a';
        char* str = strs[i];
        HashMap* tmp = NULL;
        HASH_FIND_INT(map, &tkey, tmp);
        if(tmp == NULL) {
            tmp = malloc(sizeof(HashMap));
            tmp->key = tkey;
            tmp->val = str;
            HASH_ADD_INT(map, key, tmp);
        } else {
            if(strcmp(str, tmp->val) != 0) {
                return false;
            }
        }

        HashMap1* tmp1 = NULL;
        HASH_FIND_STR(map1, str, tmp1);
        if(tmp1 == NULL) {
            tmp1 = malloc(sizeof(HashMap1));
            tmp1->key = str;
            tmp1->val = tkey;
            HASH_ADD_STR(map1, key, tmp1);
        } else {
            if(tmp1->val != tkey) {
                return false;
            }
        }
    }
    return true;
}
