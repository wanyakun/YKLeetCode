//
//  main.c
//  NO14
//
//  Created by wanyakun on 2020/12/11.
//

#include <stdio.h>
#include "NO14.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char** strs = malloc(3*sizeof(char*));
    strs[0] = "flower";
    strs[1] = "flow";
    strs[2] = "flight";
    char* res = longestCommonPrefix(strs, 3);
    printf("%s", res);
    return 0;
}
