//
//  main.c
//  NO842
//
//  Created by wanyakun on 2020/12/8.
//

#include <stdio.h>
#include "NO842.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    char* S = "123456579";
    int returnSize;
    int* res = splitIntoFibonacci(S, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d, ", res[i]);
    }
    printf("\n");
    return 0;
}
