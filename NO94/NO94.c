//
//  NO94.c
//  NO94
//
//  Created by wanyakun on 2020/11/3.
//

#include "NO94.h"
#include <stdlib.h>

// 递归
void traversal(TreeNode* root, int* returnSize, int* res) {
    // base case
    if (root == NULL) return;
    traversal(root->left, returnSize, res);
    //中序遍历
    res = realloc(res, (++(*returnSize)*sizeof(int)));
    res[(*returnSize)-1] = root->val;
    traversal(root->right, returnSize, res);
}
int* inorderTraversal(TreeNode* root, int* returnSize){
    if (root == NULL)  return NULL;
    int* res = malloc(0);
    *returnSize = 0;
    traversal(root, returnSize, res);
    return res;
}
// 迭代
int* inorderTraversal1(TreeNode* root, int* returnSize){
    // base case
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    // 存储结果
    int* res = malloc(0);
    *returnSize = 0;
    // 存储栈
    TreeNode** stk = malloc(0);
    int stk_top = 0;
    TreeNode* node = root;
    while (stk_top > 0 || node != NULL) {
        // 当期节点入栈，并设置为左节点
        if (node) {
            stk = realloc(stk, (++stk_top)*sizeof(TreeNode));
            stk[stk_top-1] = node;
            node = node->left;
        } else {
            // 节点出栈
            node = stk[--stk_top];
            res = realloc(res, (++(*returnSize))*sizeof(int));
            res[(*returnSize)-1] = node->val;
            node = node->right;
        }
    }
    return res;
}
