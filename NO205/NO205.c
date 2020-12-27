//
//  NO205.c
//  NO205
//
//  Created by wanyakun on 2020/12/27.
//

#include "NO205.h"
#include <stdlib.h>
#include "uthash.h"

typedef struct {
    char key;
    char val;
    UT_hash_handle hh;
} HashMap;

bool isIsomorphic(char * s, char * t){
    int len = strlen(s);
    HashMap* map = NULL;
    HashMap* map1 = NULL;
    for(int i = 0; i < len; i++) {
        char c = s[i];
        char v = t[i];
        HashMap *tmp = NULL;
        HASH_FIND(hh, map, &c, sizeof(char), tmp);
        if(tmp == NULL) {
            tmp = malloc(sizeof(HashMap));
            tmp->key = c;
            tmp->val = v;
            HASH_ADD(hh, map, key, sizeof(char), tmp);
        } else {
            if(tmp->val != v) {
                return false;
            }
        }

        HashMap *tmp1 = NULL;
        HASH_FIND(hh, map1, &v, sizeof(char), tmp1);
        if(tmp1 == NULL) {
            tmp1 = malloc(sizeof(HashMap));
            tmp1->key = v;
            tmp1->val = c;
            HASH_ADD(hh, map1, key, sizeof(char), tmp1);
        } else {
            if(tmp1->val != c) {
                return false;
            }
        }
    }
    return true;
}
