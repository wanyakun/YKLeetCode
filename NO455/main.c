//
//  main.c
//  NO455
//
//  Created by wanyakun on 2020/12/25.
//

#include <stdio.h>
#include "NO455.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int g[2] = {1,2};
    int s[3] = {1,2,3};
    int res = findContentChildren(g, 2, s, 3);
    printf("%d \n", res);
    return 0;
}
