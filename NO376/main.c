//
//  main.c
//  NO376
//
//  Created by wanyakun on 2020/12/12.
//

#include <stdio.h>
#include "NO376.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[6] = {1,7,4,9,2,5};
    int res = wiggleMaxLength1(nums, 6);
    printf("%d \n", res);
    return 0;
}
