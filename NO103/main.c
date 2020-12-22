//
//  main.c
//  NO103
//
//  Created by wanyakun on 2020/12/22.
//

#include <stdio.h>
#include "TreeNode.h"
#include "NO103.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[7] = {3,9,20,NULL, NULL, 15,7};
    TreeNode* root = createTreeNodeWithNums(nums, 7);
    int returnSize;
    int* returnColumsSize;
    int** res = zigzagLevelOrder(root, &returnSize, &returnColumsSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumsSize[i]; j++) {
            printf("%d,", res[i][j]);
        }
        printf("] \n");
    }
    return 0;
}
