//
//  main.c
//  NO354
//
//  Created by wanyakun on 2020/11/29.
//

#include <stdio.h>
#include "NO354.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
//    int envelopes[4][2] = {{5,4}, {6,4}, {6,7}, {2,3}};
    int** envelopes = malloc(4*sizeof(int*));
    envelopes[0] = malloc(2*sizeof(int));
    envelopes[0][0] = 5;
    envelopes[0][1] = 4;
    envelopes[1] = malloc(2*sizeof(int));
    envelopes[1][0] = 6;
    envelopes[1][1] = 4;
    envelopes[2] = malloc(2*sizeof(int));
    envelopes[2][0] = 6;
    envelopes[2][1] = 7;
    envelopes[3] = malloc(2*sizeof(int));
    envelopes[3][0] = 2;
    envelopes[3][1] = 3;
    int envelopesColSize[4] = {2,2,2,2};
    int res = maxEnvelopes(envelopes, 4, envelopesColSize);
    printf("%d \n", res);
    return 0;
}
