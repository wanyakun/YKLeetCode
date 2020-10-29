//
//  NO144.c
//  NO144
//
//  Created by wanyakun on 2020/10/28.
//

#include "NO144.h"
#include <stdlib.h>
int* preorderTraversal(TreeNode* root, int* returnSize){
    if (root == NULL)  {
        *returnSize = 0;
        return NULL;
    }
    // 存储结果
    int* result = malloc(sizeof(int));
    result[0] = root->val;
    *returnSize = 0;
    // 存储栈
    TreeNode** stk = malloc(sizeof(TreeNode));
    stk[0] = root;
    int stk_top = 1;
    while(stk_top > 0) {
        // 出栈
        TreeNode* curr = stk[--stk_top];
        // 存储
        (*returnSize)++;
        result = realloc(result, (*returnSize)*sizeof(int));
        result[(*returnSize)-1] = curr->val;
        // 右节点入栈
        if(curr->right) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = curr->right;
        }
        // 左节点入栈
        if(curr->left) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = curr->left;
        }
    }
    return result;
}
