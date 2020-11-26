//
//  main.c
//  NO518
//
//  Created by wanyakun on 2020/11/26.
//

#include <stdio.h>
#include "NO518.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int amount = 5;
    int coins[3] = {1,2,5};
    int res = change1(amount, coins, 3);
    printf("%d \n", res);
    return 0;
}
