//
//  main.c
//  NO516
//
//  Created by wanyakun on 2020/11/28.
//

#include <stdio.h>
#include "NO516.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int res = longestPalindromeSubseq("bbbab");
    printf("%d \n", res);
    int res1 = longestPalindromeSubseq1("bbbab");
    printf("%d \n", res1);
    return 0;
}
