//
//  main.c
//  Tencent0001
//
//  Created by wanyakun on 2020/12/11.
//

#include <stdio.h>
#include "Tencent0001.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int array[12] = {2,5,3,1,3,2,4,1,5,0,4,3};
    int res = minShoot(array, 12, 5);
    printf("%d \n", res);
    return 0;
}
