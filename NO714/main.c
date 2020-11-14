//
//  main.c
//  NO714
//
//  Created by wanyakun on 2020/11/14.
//

#include <stdio.h>
#include "NO714.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int prices[6] = {1,3,2,8,4,9};
    int res = maxProfit(prices, 6, 2);
    printf("%d \n", res);
    return 0;
}
