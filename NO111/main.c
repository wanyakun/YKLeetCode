//
//  main.c
//  NO111
//
//  Created by wanyakun on 2020/11/9.
//

#include <stdio.h>
#include "TreeNode.h"
#include "NO111.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node3 = createTreeNode(3, NULL, NULL);
    TreeNode* node4 = createTreeNode(4, NULL, NULL);
    TreeNode* node5 = createTreeNode(5, NULL, NULL);

    TreeNode* node2 = createTreeNode(2, node4, node5);
    TreeNode* node1 = createTreeNode(1, node2, node3);

    int depth = minDepth(node1);
    printf("%d \n", depth);
    return 0;
}
