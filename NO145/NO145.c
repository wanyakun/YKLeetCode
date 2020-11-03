//
//  NO145.c
//  NO145
//
//  Created by wanyakun on 2020/11/3.
//

#include "NO145.h"
#include <stdlib.h>

// 递归
void traversal(TreeNode* root, int* returnSize, int** res) {
    // base case
    if(root == NULL) return;
    traversal(root->left, returnSize, res);
    traversal(root->right, returnSize, res);
    //后续遍历
    (*res) = realloc((*res), (++(*returnSize))*sizeof(int));
    (*res)[(*returnSize)-1] = root->val;
}

int* postorderTraversal(TreeNode* root, int* returnSize){
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int* res = malloc(0);
    *returnSize = 0;
    traversal(root, returnSize, &res);
    return res;
}

// 迭代
int* postorderTraversal1(TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    // 存储结果
    int* res = malloc(0);
    *returnSize = 0;
    // 存储节点栈
    TreeNode** stk = malloc(0);
    int stk_top = 0;
    TreeNode* node = root;
    TreeNode* pre = NULL;
    while(stk_top > 0 || node != NULL) {
        while (node != NULL) {
            // 节点入栈并设置为左节点
            stk = realloc(stk, (++stk_top)*sizeof(TreeNode));
            stk[stk_top-1] = node;
            node = node->left;
        }
        
        // 节点出栈
        node = stk[--stk_top];
        if (node->right == NULL || node->right == pre) {
            res = realloc(res, (++(*returnSize))*sizeof(int));
            res[(*returnSize)-1] = node->val;
            pre = node;
            node = NULL;
        } else {
            stk = realloc(stk, (++stk_top)*sizeof(TreeNode));
            stk[stk_top-1] = node;
            node = node->right;
        }
    }
    return res;
}
