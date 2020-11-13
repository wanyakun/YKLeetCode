//
//  main.c
//  NO567
//
//  Created by wanyakun on 2020/11/13.
//

#include <stdio.h>
#include "NO567.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "eidbaooo";
    char* t = "ab";
    
    bool check = checkInclusion(t, s);
    printf("%d \n", check);
    
    return 0;
}
