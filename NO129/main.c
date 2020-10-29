//
//  main.c
//  NO129
//
//  Created by wanyakun on 2020/10/29.
//

#include <stdio.h>
#include "NO129.h"
#include "TreeNode.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node5 = createTreeNode(5, NULL, NULL);
    TreeNode* node1 = createTreeNode(1, NULL, NULL);
    TreeNode* node0 = createTreeNode(0, NULL, NULL);

    TreeNode* node9 = createTreeNode(9, node5, node1);
    TreeNode* node4 = createTreeNode(4, node9, node0);

    int sum = sumNumbers(node4);
    printf("%d \n", sum);

    return 0;
}
