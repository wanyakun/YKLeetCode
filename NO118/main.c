//
//  main.c
//  NO118
//
//  Created by wanyakun on 2020/12/6.
//

#include <stdio.h>
#include "NO118.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int returnSize;
    int* returnColumnSizes;
    int** res = generate(5, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for(int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d, ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}
