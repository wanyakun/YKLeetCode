//
//  main.c
//  NO107
//
//  Created by wanyakun on 2020/11/4.
//

#include <stdio.h>
#include "TreeNode.h"
#include "NO107.h"
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node15 = createTreeNode(15, NULL, NULL);
    TreeNode* node7 = createTreeNode(7, NULL, NULL);

    TreeNode* node9 = createTreeNode(9, NULL, NULL);
    TreeNode* node20 = createTreeNode(20, node15, node7);

    TreeNode* node3 = createTreeNode(3, node9, node20);

    int returnSize = 0;
    int* returnColumnSize;
    int** res = levelOrderBottom(node3, &returnSize, &returnColumnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSize[i]; j++) {
            int num = res[i][j];
            printf("%d ", num);
        }
        printf("] \n");
    }
    return 0;
}
