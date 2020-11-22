//
//  main.c
//  NO242
//
//  Created by wanyakun on 2020/11/22.
//

#include <stdio.h>
#include "NO242.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "anagram";
    char* t = "nagaram";
    bool res = isAnagram(s, t);
    printf("%d \n", res);
    return 0;
}
