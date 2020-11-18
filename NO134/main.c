//
//  main.c
//  NO134
//
//  Created by wanyakun on 2020/11/18.
//

#include <stdio.h>
#include "NO134.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int gas[5] = {1,2,3,4,5};
    int cost[5] = {3,4,5,1,2};
    int res = canCompleteCircuit(gas, 5, cost, 5);
    printf("%d \n", res);
    return 0;
}
