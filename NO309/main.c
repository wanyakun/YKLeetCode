//
//  main.c
//  NO309
//
//  Created by wanyakun on 2020/11/14.
//

#include <stdio.h>
#include "NO309.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int prices[5] = {1,2,3,0,2};
    int res = maxProfit(prices, 5);
    printf("%d \n", res);
    
    return 0;
}
