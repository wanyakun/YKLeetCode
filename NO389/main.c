//
//  main.c
//  NO389
//
//  Created by wanyakun on 2020/12/18.
//

#include <stdio.h>
#include "NO389.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    char* s = "abcd";
    char* t = "abcde";
    char res = findTheDifference3(s, t);
    printf("%c \n", res);
    return 0;
}
