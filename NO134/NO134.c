//
//  NO134.c
//  NO134
//
//  Created by wanyakun on 2020/11/18.
//

#include "NO134.h"

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int i = 0;
    while(i < gasSize) {
        int sumOfGas = 0, sumOfCost = 0;
        int cnt = 0;
        while(cnt < gasSize) {
            int j = (i+cnt)%gasSize;
            sumOfGas += gas[j];
            sumOfCost += cost[j];
            if(sumOfCost > sumOfGas) {
                break;
            }
            cnt++;
        }
        if(cnt == gasSize) {
            return i;
        } else {
            i = i + cnt + 1;
        }
    }
    return -1;
}
