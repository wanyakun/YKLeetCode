//
//  main.c
//  NO652
//
//  Created by wanyakun on 2020/11/20.
//

#include <stdio.h>
#include "TreeNode.h"
#include "NO652.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node44 = createTreeNode(4, NULL, NULL);
    
    TreeNode* node314 = createTreeNode(4, NULL, NULL);
    TreeNode* node32 = createTreeNode(2, node44, NULL);
    TreeNode* node324 = createTreeNode(4, NULL, NULL);
    
    TreeNode* node22 = createTreeNode(2, node314, NULL);
    TreeNode* node23 = createTreeNode(3, node32, node324);
    
    TreeNode* node1 = createTreeNode(1, node22, node23);

    int returnSize;
    TreeNode** res = findDuplicateSubtrees(node1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        TreeNode* root = res[i];
        preOrderTraverse(root);
    }

    return 0;
}
