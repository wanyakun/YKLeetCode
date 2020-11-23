//
//  main.c
//  NO64
//
//  Created by wanyakun on 2020/11/23.
//

#include <stdio.h>
#include "NO64.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    int grid[3][3] = {{1,3,1}, {1,5,1}, {4,2,1}};
    int** grid = malloc(3*sizeof(int*));
    grid[0] = malloc(3*sizeof(int));
    grid[0][0] = 1;
    grid[0][1] = 3;
    grid[0][2] = 1;
    
    grid[1] = malloc(3*sizeof(int));
    grid[1][0] = 1;
    grid[1][1] = 5;
    grid[1][2] = 1;
    
    grid[2] = malloc(3*sizeof(int));
    grid[2][0] = 4;
    grid[2][1] = 2;
    grid[2][2] = 1;

    int gridColSize[3] = {3,3,3};
    
    int res = minPathSum(grid, 3, gridColSize);
    printf("%d \n", res);
    return 0;
}
