//
//  main.c
//  NO10
//
//  Created by wanyakun on 2020/12/1.
//

#include <stdio.h>
#include "NO10.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "aa";
    char* p = "a*";
    bool res = isMatch(s, p);
    printf("%d \n", res);
    return 0;
}
