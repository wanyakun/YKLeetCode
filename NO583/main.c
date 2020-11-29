//
//  main.c
//  NO583
//
//  Created by wanyakun on 2020/11/30.
//

#include <stdio.h>
#include "NO583.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* word1 = "sea";
    char* word2 = "eat";
    int res = minDistance1(word1, word2);
    printf("%d \n", res);
    return 0;
}
