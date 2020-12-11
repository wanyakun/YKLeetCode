//
//  Tencent0001.c
//  Tencent0001
//
//  Created by wanyakun on 2020/12/11.
//

#include "Tencent0001.h"
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

bool isMoveLeft(int* window, int m) {
    for (int i = 1; i <= m; i++) {
        if (window[i] == 0) {
            return false;
        }
    }
    return true;
}

int minShoot(int* array, int n, int m) {
    if (n <= 0 || m <= 0) {
        return  0;
    }
    int left = 0, right = 0;
    int* window = malloc(m*sizeof(int));
    memset(window, 0, m*sizeof(int));
    int res = INT_MAX;
    while(right < n) {
        int num = array[right];
        right++;
        window[num]++;
        while (isMoveLeft(window, m)) {
            res = fmin(res, right-left);
            int numLeft = array[left];
            left++;
            window[numLeft]--;
        }
    }
    return res;
}
