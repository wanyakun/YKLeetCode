//
//  NO649.c
//  NO649
//
//  Created by wanyakun on 2020/12/12.
//

#include "NO649.h"
#include <string.h>

char * predictPartyVictory(char * senate){
    int m = strlen(senate);
    int radiant[m], dire[m];
    int left_r = 0, right_r = 0;
    int left_d = 0, right_d = 0;
    for(int i = 0; i < m; i++) {
        if(senate[i] == 'R') {
            radiant[right_r++] = i;
        } else {
            dire[right_d++] = i;
        }
    }
    while(left_r < right_r && left_d < right_d) {
        if(radiant[left_r] < dire[left_d]) {
            radiant[right_r++] = radiant[left_r]+m;
        } else {
            dire[right_d++] = dire[left_d]+m;
        }
        left_r++;
        left_d++;
    }
    if(left_r < right_r) {
        return "Radiant";
    } else {
        return "Dire";
    }
}
