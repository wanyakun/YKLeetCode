//
//  main.c
//  LeetCode
//
//  Created by wanyakun on 2020/10/27.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO322.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int* coins = calloc(1, sizeof(int));
    coins[0] = 2;
//    coins[1] = 2;
//    coins[2] = 5;
    int coinsSize = 1;
    int amount = 3;
    int result = coinChange2(coins, coinsSize, amount);
    printf("coinChange result: %d \n", result);
    return 0;
}
