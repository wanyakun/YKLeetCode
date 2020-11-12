//
//  main.c
//  NO922
//
//  Created by wanyakun on 2020/11/12.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO922.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int* A = malloc(4*sizeof(int));
    A[0] = 4;
    A[1] = 2;
    A[2] = 5;
    A[3] = 7;
    
    int returnSize;
    int* res = sortArrayByParityII(A, 4, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d, ", res[i]);
    }
    printf("] \n");
    
    return 0;
}
