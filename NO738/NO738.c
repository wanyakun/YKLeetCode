//
//  NO738.c
//  NO738
//
//  Created by wanyakun on 2020/12/15.
//

#include "NO738.h"
#include <stdlib.h>

// 暴力超时
// int monotoneIncreasingDigits(int N){
//     if (N <=10) return N-1;
//     int res = INT_MIN;
//     while(N > 0) {
//         char c[10] = {'\0'};
//         sprintf(c, "%d", N);
//         bool isIncreasing = true;
//         for(int i = 0; i < strlen(c) - 1; i++) {
//             if(c[i] > c[i+1]) {
//                 isIncreasing = false;
//                 break;
//             }
//         }
//         if(isIncreasing) {
//             res = N;
//             break;
//         }
//         N--;
//     }
//     return res;
// }
void itoa(int num, char* str, int* strSize) {
    *strSize = 0;
    while(num > 0) {
        str[(*strSize)++] = num%10 + '0';
        num /= 10;
    }
    // 翻转
    for(int i = 0; i < (*strSize)/2; i++) {
        int tmp = str[i];
        str[i] = str[(*strSize) - 1 - i];
        str[(*strSize) - 1 - i] = tmp;
    }
}


int monotoneIncreasingDigits(int N){
    // int 转 char* 字符串
    int strNSize;
    char strN[11];
    itoa(N, strN, &strNSize);
    // 找到出现不满足递增的位置
    int i = 1;
    while(i < strNSize && strN[i-1] <= strN[i]) {
        i += 1;
    }
    if(i < strNSize) {
        // 从出现不满足递增的位置往前一次减一，知道减一后前面的都满足递增
        while(i > 0 && strN[i-1] > strN[i]) {
            strN[i-1] -= 1;
            i -= 1;
        }
        // 从i下一个位置开始，所有的都设置成9
        for(i += 1; i < strNSize; i++) {
            strN[i] = '9';
        }
    }
    return atoi(strN);
}
