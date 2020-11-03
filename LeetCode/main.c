//
//  main.c
//  LeetCode
//
//  Created by wanyakun on 2020/10/27.
//

#include <stdio.h>
#include "TreeNode.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...

    //    [1,2,5,3,4,null,6]
    TreeNode* node3 = createTreeNode(3, NULL, NULL);
    TreeNode* node4 = createTreeNode(4, NULL, NULL);
    TreeNode* node6 = createTreeNode(6, NULL, NULL);

    TreeNode* node2 = createTreeNode(2, node3, node4);
    TreeNode* node5 = createTreeNode(5, NULL, node6);

    TreeNode* node1 = createTreeNode(1, node2, node5);

    printf("前序遍历：");
    preOrderTraverse(node1);
    printf("\n");
    
    printf("前序遍历：");
    preOrderTraverse11(node1);
    printf("\n");
    
    printf("中序遍历：");
    inOrderTravers(node1);
    printf("\n");

    printf("中序遍历：");
    inOrderTravers1(node1);
    printf("\n");
    
    printf("后序遍历：");
    postOrderTravers(node1);
    printf("\n");
    
    printf("后序遍历：");
    postOrderTravers1(node1);
    printf("\n");
    
    printf("层次遍历：");
    levelOrderTravers(node1);
    printf("\n");
    
    return 0;
}
