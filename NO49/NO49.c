//
//  NO49.c
//  NO49
//
//  Created by wanyakun on 2020/12/14.
//

#include "NO49.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "uthash.h"
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool isAnagrams(char* str1, char* str2) {
    int len = strlen(str1);
    if(len != strlen(str2)) return false;

    int nums1[26];
    memset(nums1, 0, sizeof(nums1));
    int nums2[26];
    memset(nums2, 0, sizeof(nums2));
    for(int i = 0; i < len; i++) {
        nums1[str1[i]-'a']++;
        nums2[str2[i]-'a']++;
    }
    for(int i = 0; i < 26; i++) {
        if(nums1[i] != nums2[i]) return false;
    }
    return true;
}

// 暴力循环+分组备忘
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    if(strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    char *** res = malloc(strsSize*sizeof(char**));
    *returnSize = 0;
    *returnColumnSizes = malloc(strsSize*sizeof(int));
    // 备忘录
    bool* mem = malloc(strsSize*sizeof(bool));
    memset(mem, false, strsSize*sizeof(bool));

    for(int i = 0; i < strsSize; i++) {
        char* str = strs[i];
        if(mem[i]) continue;
        // 生成新的数组
        char** tmp = malloc(strsSize*sizeof(char*));
        tmp[0] = str;
        int tmpSize = 1;
        mem[i] = true;
        for(int j = i+1; j < strsSize; j++) {
            if(isAnagrams(str, strs[j])) {
                mem[j] = true;
                tmp[tmpSize++] = strs[j];
            }
        }
        (*returnColumnSizes)[(*returnSize)] = tmpSize;
        res[(*returnSize)] = tmp;
        (*returnSize)++;
    }

    return res;
}

// Hash表
typedef struct {
    const char* key;
    char** val;
    int valSize;
    UT_hash_handle hh;
} HashMap;

char *** groupAnagrams1(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    if(strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    HashMap *map = NULL;
    for (int i = 0; i < strsSize; i++) {
        char* str = strs[i];
        int nums[26];
        memset(nums, 0, sizeof(nums));
        for (int j = 0; j < strlen(str); j++) {
            nums[str[j] - 'a']++;
        }
        char key[100] = {'\0'};
        char tKey[100] = {'\0'}; 
        for (int j = 0; j < 26; j++) {
            sprintf(tKey, "%d,", nums[j]);
            strcat(key, tKey);
        }
        HashMap *tmp = NULL;
        HASH_FIND_STR(map, key, tmp); //(hh, map, &key, strlen(key), tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(HashMap));
            tmp->key = key;
            char** val = malloc(strsSize*sizeof(char*));
            val[0] = str;
            tmp->val = val;
            tmp->valSize = 1;
            HASH_ADD_STR(map, key, tmp); //(hh, map, key, strlen(key), tmp);
        } else {
            (tmp->val)[(tmp->valSize)++] = str;
        }
    }
    
    int count = HASH_COUNT(map);
    char *** res = malloc(count*sizeof(char**));
    *returnSize = 0;
    *returnColumnSizes = malloc(count*sizeof(int));
    
    HashMap* el = NULL;
    HashMap* tmp = NULL;
    HASH_ITER(hh, map, el, tmp) {
        (*returnColumnSizes)[(*returnSize)] = el->valSize;
        res[(*returnSize)++] = el->val;
    }
    
    return res;
}

int cmp(const void * _a, const void * _b) {
    char a = *(char*)_a;
    char b = *(char*)_b;
    return a-b;
}

char *** groupAnagrams2(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    if(strsSize == 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    HashMap *map = NULL;
    for (int i = 0; i < strsSize; i++) {
        char* str = strs[i];
        int len = strlen(str);
        char* key = malloc((len+1)*sizeof(char));;
        strcpy(key, str);
        key[len] = '\0';
        qsort(key, strlen(key), sizeof(char), cmp);
        HashMap *tmp = NULL;
        HASH_FIND_STR(map, key, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(HashMap));
            tmp->key = key;
            char** val = malloc(strsSize*sizeof(char*));
            val[0] = str;
            tmp->val = val;
            tmp->valSize = 1;
            HASH_ADD_STR(map, key, tmp);
        } else {
            (tmp->val)[(tmp->valSize)++] = str;
        }
    }

    int count = HASH_COUNT(map);
    char *** res = malloc(count*sizeof(char**));
    *returnSize = 0;
    *returnColumnSizes = malloc(count*sizeof(int));
    
    HashMap* el = NULL;
    HashMap* tmp = NULL;
    HASH_ITER(hh, map, el, tmp) {
        (*returnColumnSizes)[(*returnSize)] = el->valSize;
        res[(*returnSize)++] = el->val;
    }
    
    return res;
}
