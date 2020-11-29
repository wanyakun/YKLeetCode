//
//  main.c
//  NO1143
//
//  Created by wanyakun on 2020/11/29.
//

#include <stdio.h>
#include "NO1143.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* text1 = "abcde";
    char* text2 = "ace";
    int res = longestCommonSubsequence1(text1, text2);
    printf("%d \n", res);
    return 0;
}
