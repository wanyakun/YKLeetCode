//
//  main.c
//  NO463
//
//  Created by wanyakun on 2020/10/30.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO463.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int* row0 = malloc(4*sizeof(int));
    row0[0] = 0;
    row0[1] = 1;
    row0[2] = 0;
    row0[3] = 0;

    int* row1 = malloc(4*sizeof(int));
    row1[0] = 1;
    row1[1] = 1;
    row1[2] = 1;
    row1[3] = 0;
    
    int* row2 = malloc(4*sizeof(int));
    row2[0] = 0;
    row2[1] = 1;
    row2[2] = 0;
    row2[3] = 0;
    
    int* row3 = malloc(4*sizeof(int));
    row3[0] = 1;
    row3[1] = 1;
    row3[2] = 0;
    row3[3] = 0;
    
    int** grid = malloc(4*sizeof(int*));
//    grid[0][0] = 0;
//    grid[0][1] = 1;
//    grid[0][2] = 0;
//    grid[0][3] = 0;
//
//    grid[1][0] = 1;
//    grid[1][1] = 1;
//    grid[1][2] = 1;
//    grid[1][3] = 0;
//
//    grid[2][0] = 0;
//    grid[2][1] = 1;
//    grid[2][2] = 0;
//    grid[2][3] = 0;
//
//    grid[3][0] = 1;
//    grid[3][1] = 1;
//    grid[3][2] = 0;
//    grid[3][3] = 0;

    grid[0] = row0;
    grid[1] = row1;
    grid[2] = row2;
    grid[3] = row3;
    
    int* gridColSize = malloc(4*sizeof(int));
    gridColSize[0] = 4;
    gridColSize[1] = 4;
    gridColSize[2] = 4;
    gridColSize[3] = 4;

    int result = islandPerimeter(grid, 4, gridColSize);
    printf("%d \n", result);
    
    int result1 = islandPerimeter1(grid, 4, gridColSize);
    printf("%d \n", result1);
    return 0;
}
