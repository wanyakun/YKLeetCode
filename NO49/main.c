//
//  main.c
//  NO49
//
//  Created by wanyakun on 2020/12/14.
//

#include <stdio.h>
#include "NO49.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* strs[14] = {"eat","tea","tan","ate","nat","bat","ac","bd","aac","bbd","aacc","bbdd","acc","bdd"};
//    char* strs[6] = {"tea","","eat","","tea",""};
    int returnSize;
    int *returnColumnSizes;
    char *** res = groupAnagrams2(strs, 14, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s,", res[i][j]);
        }
        printf("] \n");
    }
    return 0;
}
