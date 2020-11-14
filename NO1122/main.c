//
//  main.c
//  NO1122
//
//  Created by wanyakun on 2020/11/14.
//

#include <stdio.h>
#include "NO1122.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr1[11] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr2[6] = {2,1,4,3,9,6};
    
    int resultSize;
    int* res = relativeSortArray(arr1, 11, arr2, 6, &resultSize);
    printf("[");
    for (int i = 0; i < resultSize; i++) {
        printf("%d,", res[i]);
    }
    printf("] \n");
    
    
    return 0;
}
