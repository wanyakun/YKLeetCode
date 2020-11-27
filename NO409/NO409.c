//
//  NO409.c
//  NO409
//
//  Created by wanyakun on 2020/11/27.
//

#include "NO409.h"
#include <string.h>

int longestPalindrome(char * s){
    int count[128] = {0};
    for(int i = 0; i < strlen(s); i++) {
        count[s[i]]++;
    }
    int res = 0;
    for(int i = 0; i < 128; i++) {
        // int num = count[i];
        // res += (num/2)*2;
        // if(num%2 == 1 && res%2 == 0) {
        //     res++;
        // }
        res += count[i] - count[i]%2;
    }
    // return res;
    return res+(res != strlen(s));
}
