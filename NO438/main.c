//
//  main.c
//  NO438
//
//  Created by wanyakun on 2020/11/13.
//

#include <stdio.h>
#include "NO438.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "cbaebabacd";
    char* t = "abc";
    int returnSize;
    int* res = findAnagrams(s, t, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d, ", res[i]);
    }
    printf("] \n");
    return 0;
}
