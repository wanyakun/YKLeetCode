//
//  main.c
//  NO1030
//
//  Created by wanyakun on 2020/11/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO1030.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int R = 1, C = 2, r0 = 0, c0 = 0;
    int returnSize;
    int* returnColumnSizes;
    int** res = allCellsDistOrder(R, C, r0, c0, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] \n", res[i][0], res[i][1]);
    }
    return 0;
}
