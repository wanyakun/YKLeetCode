//
//  main.c
//  NO860
//
//  Created by wanyakun on 2020/12/10.
//

#include <stdio.h>
#include "NO860.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int bills[5] = {5,5,5,10,20};
    bool res = lemonadeChange(bills, 5);
    printf("%d \n", res);
    return 0;
}
