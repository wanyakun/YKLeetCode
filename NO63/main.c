//
//  main.c
//  NO63
//
//  Created by wanyakun on 2020/11/23.
//

#include <stdio.h>
#include "NO63.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int** obstacleGrid = malloc(3*sizeof(int*));
    obstacleGrid[0] = malloc(3*sizeof(int));
    obstacleGrid[0][0] = 0;
    obstacleGrid[0][1] = 0;
    obstacleGrid[0][2] = 0;
    
    obstacleGrid[1] = malloc(3*sizeof(int));
    obstacleGrid[1][0] = 0;
    obstacleGrid[1][1] = 1;
    obstacleGrid[1][2] = 0;
    
    obstacleGrid[2] = malloc(3*sizeof(int));
    obstacleGrid[2][0] = 0;
    obstacleGrid[2][1] = 0;
    obstacleGrid[2][2] = 0;

    int obstacleGridColSize[3] = {3,3,3};
    
    int res = uniquePathsWithObstacles(obstacleGrid, 3, obstacleGridColSize);
    printf("%d \n", res);
    return 0;
}
