//
//  main.c
//  NO76
//
//  Created by wanyakun on 2020/11/12.
//

#include <stdio.h>
#include "NO76.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "aa";
    char* t = "aa";
    
    char* res = minWindow(s, t);
    printf("%s \n", res);
    
    return 0;
}
