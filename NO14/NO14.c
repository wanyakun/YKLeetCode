//
//  NO14.c
//  NO14
//
//  Created by wanyakun on 2020/12/11.
//

#include "NO14.h"
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    if(strsSize <= 0) return "";
    if(strsSize == 1) return strs[0];
    int minSize = INT_MAX;
    for(int i = 0; i < strsSize; i++) {
        minSize = fmin(minSize, strlen(strs[i]));
    }
    char * res = malloc((minSize+1)*sizeof(char));
    int resSize = 0;
    for(int i = 0; i < minSize; i++) {
        char c = strs[0][i];
        for(int j = 1; j < strsSize; j++) {
            if(strs[j][i] != c) {
                res[resSize] = '\0';
                return res;
            }
        }
        res[i] = c;
        resSize++;
    }
    res[resSize] = '\0';
    return res;
}
