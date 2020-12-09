//
//  NO860.c
//  NO860
//
//  Created by wanyakun on 2020/12/10.
//

#include "NO860.h"

bool lemonadeChange(int* bills, int billsSize){
    int nums_5 = 0;
    int nums_10 = 0;
    for(int i = 0; i < billsSize; i++) {
        int num = bills[i];
        if(num == 5) {
            nums_5++;
        } else if(num == 10) {
            if(nums_5 > 0) {
                nums_5--;
                nums_10++;
            } else {
                return false;
            }
        } else {
            if(nums_10 > 0 && nums_5) {
                nums_10--;
                nums_5--;
            } else if(nums_5 >= 3) {
                nums_5 -= 3;
            } else {
                return false;
            }
        }
    }
    return true;
}
