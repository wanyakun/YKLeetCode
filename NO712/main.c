//
//  main.c
//  NO712
//
//  Created by wanyakun on 2020/11/30.
//

#include <stdio.h>
#include "NO712.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s1 = "sea";
    char* s2 = "eat";
    int res = minimumDeleteSum(s1, s2);
    printf("%d \n", res);
    return 0;
}
