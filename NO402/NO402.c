//
//  NO402.c
//  NO402
//
//  Created by wanyakun on 2020/11/15.
//

#include "NO402.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * removeKdigits(char * num, int k){
    if(num == NULL) return NULL;
    int len = (int)strlen(num);
    char* stk = malloc((len+1)*sizeof(char));
    int top = 0;
    for(int i = 0; i < len; i++) {
        while(stk[top] > num[i] && k > 0 && top > 0) {
            top--;
            k--;
        }
        stk[++top] = num[i];
    }
    top -= k;

    char* res = malloc((len+1)*sizeof(char));
    bool isZero = true;
    int resSize = 0;
    for(int i = 1; i <= top; i++) {
        if(isZero && stk[i] == '0') {
            continue;
        }
        isZero = false;
        res[resSize++] = stk[i];
    }
    if(resSize == 0) {
        res[0] = '0', res[1] = 0;
    } else {
        res[resSize] = 0;
    }
    return res;
}
