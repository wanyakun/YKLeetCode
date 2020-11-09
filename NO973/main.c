//
//  main.c
//  NO973
//
//  Created by wanyakun on 2020/11/9.
//

#include <stdio.h>
#include "NO973.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int** points = malloc(2*sizeof(int*));
    points[0] = malloc(2*sizeof(int));
    points[0][0] = 1;
    points[0][1] = 3;
    
    points[1] = malloc(2*sizeof(int));
    points[1][0] = -2;
    points[1][1] = 2;
    
    int* pointsColSize = malloc(2*sizeof(int));
    pointsColSize[0] = 2;
    pointsColSize[1] = 2;
    
    int returnSize = 0;
    int *returnColumSizes;
    int** res = kClosest(points, 2, pointsColSize, 1, &returnSize, &returnColumSizes);
    
    for (int i = 0; i < returnSize; i++) {
        int num0 = res[i][0];
        int num1 = res[i][1];
        
        printf("[%d, %d] \n", num0, num1);
    }
    
    return 0;
}
