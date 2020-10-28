//
//  main.c
//  NO144
//
//  Created by wanyakun on 2020/10/28.
//

#include <stdio.h>
#include "NO144.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode* node3 = createNode(3, NULL, NULL);
    TreeNode* node2 = createNode(2, node3, NULL);
    TreeNode* node1 = createNode(1, NULL, node2);
    int returnSize = 0;
    int* result = preorderTraversal(node1, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
