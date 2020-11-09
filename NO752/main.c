//
//  main.c
//  NO752
//
//  Created by wanyakun on 2020/11/9.
//

#include <stdio.h>
#include "NO752.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char** deadends = malloc(5*sizeof(char*));
    deadends[0] = "0201";
    deadends[1] = "0101";
    deadends[2] = "0102";
    deadends[3] = "1212";
    deadends[4] = "2002";
    
    int step = openLock(deadends, 5, "0202");
    printf("%d \n", step);

    return 0;
}
