//
//  main.c
//  NO226
//
//  Created by wanyakun on 2020/10/27.
//

#include <stdio.h>
#include <stdlib.h>

#include "NO226.h"
#include "TreeNode.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node1 = createTreeNode(1, NULL, NULL);
    TreeNode* node3 = createTreeNode(3, NULL, NULL);
    TreeNode* node6 = createTreeNode(6, NULL, NULL);
    TreeNode* node9 = createTreeNode(9, NULL, NULL);

    TreeNode* node2 = createTreeNode(2, node1, node3);
    TreeNode* node7 = createTreeNode(7, node6, node9);
    
    TreeNode* root = createTreeNode(4, node2, node7);
    
    TreeNode* result = invertTree1(root);

    return 0;
}
