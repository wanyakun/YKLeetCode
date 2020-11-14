//
//  NO188.c
//  NO188
//
//  Created by wanyakun on 2020/11/14.
//

#include "NO188.h"
#include <stdlib.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxProfit_MAXK(int* prices, int pricesSize){
    int dp_i_0 = 0, dp_i_1 = -INT_MAX;
    for (int i = 0; i < pricesSize; i++) {
        int tmp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1+prices[i]);
        dp_i_1 = max(dp_i_1, tmp-prices[i]);
    }
    return dp_i_0;
}

int maxProfit(int k, int* prices, int pricesSize){
    if(k > pricesSize/2) return maxProfit_MAXK(prices, pricesSize);
    int dp_0[k+1], dp_1[k+1];
    memset(dp_0, 0, (k+1)*sizeof(0));
    memset(dp_1, 0, (k+1)*sizeof(0));
    for(int i = 0; i < pricesSize; i++) {
        for(int j = k; j >= 1; j--) {
            //base case
            if(i-1 == -1) {
                dp_0[j] = 0;
                dp_1[j] = -prices[i];
            }
            dp_0[j] = max(dp_0[j], dp_1[j]+prices[i]);
            dp_1[j] = max(dp_1[j], dp_0[j-1]-prices[i]);
        }
    }
    return dp_0[k];
}
