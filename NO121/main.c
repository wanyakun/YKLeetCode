//
//  main.c
//  NO121
//
//  Created by wanyakun on 2020/11/14.
//

#include <stdio.h>
#include "NO121.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int prices[6] = {7,1,5,3,6,4};
    int res = maxProfit(prices, 6);
    printf("%d \n", res);
    return 0;
}
