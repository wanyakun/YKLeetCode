//
//  main.c
//  NO112
//
//  Created by wanyakun on 2020/10/30.
//

#include <stdio.h>
#include <stdbool.h>
#include "TreeNode.h"
#include "NO112.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node1 = createTreeNode(1, NULL, NULL);
    TreeNode* node2 = createTreeNode(2, NULL, NULL);
    TreeNode* node7 = createTreeNode(7, NULL, NULL);

    TreeNode* node4 = createTreeNode(4, NULL, node1);
    TreeNode* node13 = createTreeNode(13, NULL, NULL);
    TreeNode* node11 = createTreeNode(11, node7, node2);
    
    TreeNode* node8 = createTreeNode(8, node13, node4);
    TreeNode* node24 = createTreeNode(4, node11, NULL);

    TreeNode* node5 = createTreeNode(5, node24, node8);
    
    bool result = hasPathSum(node5, 22);
    printf("%d \n", result);
    
    bool result1 = hasPathSum1(node5, 22);
    printf("%d \n", result1);
    
    bool result2 = hasPathSum2(node5, 22);
    printf("%d \n", result2);
    
    return 0;
}
