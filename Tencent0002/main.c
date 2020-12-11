//
//  main.c
//  Tencent0002
//
//  Created by wanyakun on 2020/12/11.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Tencent0002.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int** arr = malloc(8*sizeof(int*));
    for (int i = 0; i < 8; i++) {
        arr[i] = malloc(8*sizeof(int));
        for (int j = 0; j < 8; j++) {
            arr[i][j] = 0;
        }
    }
    arr[0][3] = 1;
    arr[1][2] = 1;
    int arrColSize[8] = {8,8,8,8,8,8,8,8};
    bool res = checkConflict(arr, 8, arrColSize);
    printf("%d \n", res);
    return 0;
}
