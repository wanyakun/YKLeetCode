//
//  main.c
//  NO1356
//
//  Created by wanyakun on 2020/11/6.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO1356.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int* arr = malloc(9*sizeof(int));
    for (int i = 0; i < 9; i++) {
        arr[i] = i;
    }
    int returnSize;
    int* res = sortByBits1(arr, 9, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ,", res[i]);
    }
    printf("]");
    return 0;
}
