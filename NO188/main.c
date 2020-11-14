//
//  main.c
//  NO188
//
//  Created by wanyakun on 2020/11/14.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int prices[3] = {2,4,1};
    int res = maxProfit(2, prices, 3);
    printf("%d \n", res);
    
    return 0;
}
