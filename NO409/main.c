//
//  main.c
//  NO409
//
//  Created by wanyakun on 2020/11/27.
//

#include <stdio.h>
#include "NO409.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "abccccdd";
    int res = longestPalindrome(s);
    printf("%d \n", res);
    return 0;
}
