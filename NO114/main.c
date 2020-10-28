//
//  main.c
//  NO114
//
//  Created by wanyakun on 2020/10/28.
//

#include <stdio.h>
#include "NO114.h"
#include "TreeNode.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    [1,2,5,3,4,null,6]
    TreeNode* node3 = createNode(3, NULL, NULL);
    TreeNode* node4 = createNode(4, NULL, NULL);
    TreeNode* node6 = createNode(6, NULL, NULL);

    TreeNode* node2 = createNode(2, node3, node4);
    TreeNode* node5 = createNode(5, NULL, node6);

    TreeNode* node1 = createNode(1, node2, node5);
    
    preOrderTraverse(node1);
    printf("\n");
    preOrderTraverse1(node1);
    printf("\n");
//    [1,null,2,3]
//    TreeNode* node3 = createNode(3, NULL, NULL);
//    TreeNode* node2 = createNode(2, node3, NULL);
//
//    TreeNode* node1 = createNode(1, NULL, node2);

//    flatten2(node1);
    
    return 0;
}
