//
//  main.c
//  NO746
//
//  Created by wanyakun on 2020/12/21.
//

#include <stdio.h>
#include "NO746.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int cost[10] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int res = minCostClimbingStairs1(cost, 10);
    printf("%d \n", res);
    return 0;
}
