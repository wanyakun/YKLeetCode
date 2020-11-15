//
//  main.c
//  NO337
//
//  Created by wanyakun on 2020/11/15.
//

#include <stdio.h>
#include "TreeNode.h"
#include "NO337.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node33 = createTreeNode(3, NULL, NULL);
    TreeNode* node31 = createTreeNode(1, NULL, NULL);

    TreeNode* node22 = createTreeNode(2, NULL, node33);
    TreeNode* node23 = createTreeNode(3, NULL, node31);

    TreeNode* node13 = createTreeNode(3, node22, node23);

    int res = rob(node13);
    printf("%d \n", res);
    
    return 0;
}
