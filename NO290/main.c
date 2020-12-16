//
//  main.c
//  NO290
//
//  Created by wanyakun on 2020/12/16.
//

#include <stdio.h>
#include "NO290.h"
#include <stdbool.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    bool res = wordPattern("abba", "dog cat cat dog");
    printf("%d \n", res);
    return 0;
}
