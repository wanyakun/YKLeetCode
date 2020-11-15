//
//  main.c
//  NO402
//
//  Created by wanyakun on 2020/11/15.
//

#include <stdio.h>
#include "NO402.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* num = "1432219";
    char* res = removeKdigits(num, 3);
    printf("%s \n", res);
    return 0;
}
