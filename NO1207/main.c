//
//  main.c
//  NO1207
//
//  Created by wanyakun on 2020/10/28.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO1207.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    int* arr = malloc(sizeof(int)*6);
//    arr[0] = 1;
//    arr[1] = 2;
//    arr[2] = 2;
//    arr[3] = 1;
//    arr[4] = 1;
//    arr[5] = 3;
    
    int* arr = malloc(sizeof(int)*2);
    arr[0] = 1;
    arr[1] = 2;
    
    bool result = uniqueOccurrences(arr, 2);
    printf("result: %d \n", result);
    return 0;
}
