//
//  NO122.c
//  NO122
//
//  Created by wanyakun on 2020/11/14.
//

#include "NO122.h"
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}
int maxProfit(int* prices, int pricesSize){
    int dp_i_0 = 0, dp_i_1 = -INT_MAX;
    for (int i = 0; i < pricesSize; i++) {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
        dp_i_1 = max(dp_i_1, tmp-prices[i]);
    }
    return dp_i_0;
}
