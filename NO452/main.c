//
//  main.c
//  NO452
//
//  Created by wanyakun on 2020/11/23.
//

#include <stdio.h>
#include "NO452.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int** points = malloc(sizeof(int*)*4);
    int* pointsColSize = malloc(sizeof(int)*4);
    points[0] = malloc(sizeof(int)*2);
    points[0][0] = 10;
    points[0][1] = 16;
    pointsColSize[0] = 2;
    
    points[1] = malloc(sizeof(int)*2);
    points[1][0] = 2;
    points[1][1] = 8;
    pointsColSize[1] = 2;

    points[2] = malloc(sizeof(int)*2);
    points[2][0] = 1;
    points[2][1] = 6;
    pointsColSize[2] = 2;

    points[3] = malloc(sizeof(int)*2);
    points[3][0] = 7;
    points[3][1] = 12;
    pointsColSize[3] = 2;

    int res = findMinArrowShots(points, 4, pointsColSize);
    
    printf("%d \n", res);
    
    return 0;
}
