//
//  NO1081.c
//  NO1081
//
//  Created by wanyakun on 2020/12/21.
//

#include "NO1081.h"
#include <string.h>
#include <stdlib.h>

char * smallestSubsequence(char * s){
    int len = strlen(s);
    // 存储每个字母的个数，和字母是否访问过
    int nums[26], vist[26];
    memset(nums, 0, sizeof(nums));
    memset(vist, 0, sizeof(vist));
    
    // 更新个数
    for (int i = 0; i < len; i++) {
        nums[s[i]-'a']++;
    }
    
    // 用栈存储结果
    char* stk = malloc((len+1)*sizeof(char));
    int top = 0; // 栈顶
    for (int i = 0; i < len; i++) {
        // 处理未被访问过的字符
        if (!vist[s[i]-'a']) {
            // 如果栈顶不为空，且大于当前访问的字符，则判断nums中字符的个数，如果>0则出栈，并标记位未访问过，否则跳过
            while (top > 0 && stk[top-1] > s[i]) {
                if (nums[stk[top-1]-'a'] > 0) {
                    vist[stk[--top]-'a'] = 0;
                } else {
                    break;
                }
            }
            // 入栈，标记为访问过
            stk[top++] = s[i];
            vist[s[i]-'a'] = 1;
        }
        nums[s[i]-'a']--;
    }
    stk[top] = '\0';
    return stk;
}
