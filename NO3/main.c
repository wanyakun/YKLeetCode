//
//  main.c
//  NO3
//
//  Created by wanyakun on 2020/11/13.
//

#include <stdio.h>
#include "NO3.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "abcabcbb";
    
    int res = lengthOfLongestSubstring(s);
    printf("%d \n", res);
    
    return 0;
}
