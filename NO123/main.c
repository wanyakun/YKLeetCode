//
//  main.c
//  NO123
//
//  Created by wanyakun on 2020/11/14.
//

#include <stdio.h>
#include "NO123.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int prices[8] = {3,3,5,0,0,3,1,4};
    int res = maxProfit(prices, 8);
    printf("%d \n", res);
    
    
    return 0;
}
