//
//  NO1370.c
//  NO1370
//
//  Created by wanyakun on 2020/11/25.
//

#include "NO1370.h"
#include <stdlib.h>
#include <string.h>

char * sortString(char * s){
    // 构建一个26字符的数组，存放每个字符的个数
    int nums[26];
    memset(nums, 0, sizeof(nums));
    int n = strlen(s);
    for(int i = 0; i < n; i++) {
        nums[s[i]-'a']++;
    }
    // 存放结果
    char* res = malloc((n+1)*sizeof(char));
    int resSize = 0;
    // 重复循环操作知道结果字符和s长度相等
    while(resSize < n) {
        // 循环26个字母，构建上升字符
        for(int i = 0; i < 26; i++) {
            if(nums[i]) {
                res[resSize++] = i+'a';
                nums[i]--;
            }
        }
        // 循环s，构建下降字符
        for(int i = 25; i >= 0; i--) {
            if(nums[i]) {
                res[resSize++] = i+'a';
                nums[i]--;
            }
        }
    }
    res[resSize] = 0;
    return res;
}
