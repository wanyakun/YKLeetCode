//
//  main.c
//  NO51
//
//  Created by wanyakun on 2020/11/5.
//

#include <stdio.h>
#include "NO51.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 4;
    int returnSize;
    int* returnColumnSizes;
    char *** res = solveNQueens(n, &returnSize, &returnColumnSizes);
    
    printf("[ \n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        char** board = res[i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char c = board[i][j];
                printf("%c", c);
            }
            printf(",\n");
        }
        printf("],\n");
    }
    printf("] \n");

    return 0;
}
