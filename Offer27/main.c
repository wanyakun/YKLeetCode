//
//  main.c
//  Offer27
//
//  Created by wanyakun on 2020/12/10.
//

#include <stdio.h>
#include "Offer27.h"
#include "TreeNode.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[7] = {4,2,7,1,3,6,9};
    TreeNode* root = createTreeNodeWithNums(nums, 7);
    TreeNode* res = mirrorTree1(root);
    levelOrderTravers(res);
    printf("\n");
    return 0;
}
