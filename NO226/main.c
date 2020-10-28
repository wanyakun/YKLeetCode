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
    TreeNode* node1 = createNode(1, NULL, NULL);
    TreeNode* node3 = createNode(3, NULL, NULL);
    TreeNode* node6 = createNode(6, NULL, NULL);
    TreeNode* node9 = createNode(9, NULL, NULL);

    TreeNode* node2 = createNode(2, node1, node3);
    TreeNode* node7 = createNode(7, node6, node9);
    
    TreeNode* root = createNode(4, node2, node7);
    
    TreeNode* result = invertTree1(root);

    printPreOrderNode(result);
    return 0;
}
