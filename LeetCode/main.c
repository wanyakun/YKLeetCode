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
    int* coins = calloc(3, sizeof(int));
    coins[0] = 1;
    coins[1] = 2;
    coins[2] = 5;
    int coinsSize = 3;
    int amount = 11;
    int result = coinChange(coins, coinsSize, amount);
    printf("coinChange result: %d \n", result);
    return 0;
}
