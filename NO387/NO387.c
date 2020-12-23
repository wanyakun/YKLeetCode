//
//  NO387.c
//  NO387
//
//  Created by wanyakun on 2020/12/23.
//

#include "NO387.h"
#include <stdlib.h>
#include <string.h>

int firstUniqChar(char * s){
    int len = strlen(s);
    if(s == NULL || len == 0) return -1;
    int cnt[26];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < len; i++) {
        cnt[s[i]-'a']++;
    }
    for(int i = 0; i < len; i++) {
        if(cnt[s[i]-'a'] == 1) {
            return i;
        }
    }
    return -1;
}
