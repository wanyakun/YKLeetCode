//
//  Offer10-I.c
//  Offer10-I
//
//  Created by wanyakun on 2020/12/21.
//

#include "Offer10-I.h"

int fib(int n){
    if(n <= 1) return n;
    int f_n_2 = 0, f_n_1 = 1, sum = 0;
    for(int i = 2; i <= n; i++) {
        sum = (f_n_1 + f_n_2)%1000000007;
        f_n_2 = f_n_1;
        f_n_1 = sum;
    }
    return f_n_1;
}
