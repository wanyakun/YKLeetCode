//
//  NO102.c
//  NO102
//
//  Created by wanyakun on 2020/11/4.
//

#include "NO102.h"
#include <stdlib.h>

int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if(root == NULL) {
            *returnSize = 0;
            return NULL;
    }
    // 存储返回内容
    int** res = malloc(0);
    *returnSize = 0;
    *returnColumnSizes = malloc(0);
    // 存储队列
    TreeNode** queue = malloc(sizeof(TreeNode));
    queue[0] = root;
    int index = 0, length = 1; // 队列下标和长度
    int level = 0; // 层
    while(index < length) {
        int n = length - index;
        (*returnColumnSizes) = realloc((*returnColumnSizes), (++level)*sizeof(int));
        (*returnColumnSizes)[level-1] = n;
        res = realloc(res, level*sizeof(int*));
        int* row = malloc(n*sizeof(int));
        for(int i = 0; i < n; i++) {
            TreeNode* node = queue[index];
            index++;
            row[i] = node->val;
            if(node->left) {
                queue = realloc(queue, (++length)*sizeof(TreeNode));
                queue[length-1] = node->left;
            }
            if(node->right) {
                queue = realloc(queue, (++length)*sizeof(TreeNode));
                queue[length-1] = node->right;
            }
        }
        res[(*returnSize)] = row;
        (*returnSize)++;
    }
    return res;
}
