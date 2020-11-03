//
//  main.c
//  NO94
//
//  Created by wanyakun on 2020/11/3.
//

#include <stdio.h>
#include "NO94.h"
#include "TreeNode.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node3 = createTreeNode(3, NULL, NULL);
    TreeNode* node2 = createTreeNode(2, node3, NULL);
    TreeNode* node1 = createTreeNode(1, NULL, node2);
    
    int returnSize = 0;
    int* res = inorderTraversal1(node1, &returnSize);
    
    for(int i =0; i < returnSize; i++) {
        int num = res[i];
        printf("%d", num);
    }
    return 0;
}
