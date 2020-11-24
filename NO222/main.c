//
//  main.c
//  NO222
//
//  Created by wanyakun on 2020/11/24.
//

#include <stdio.h>
#include "NO222.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    TreeNode* node4 = createTreeNode(4, NULL, NULL);
    TreeNode* node5 = createTreeNode(5, NULL, NULL);
    TreeNode* node6 = createTreeNode(6, NULL, NULL);

    TreeNode* node2 = createTreeNode(2, node4, node5);
    TreeNode* node3 = createTreeNode(3, node6, NULL);
    TreeNode* node1 = createTreeNode(1, node2, node3);

    int res = countNodes(node1);
    
    printf("%d \n", res);
    
    return 0;
}
