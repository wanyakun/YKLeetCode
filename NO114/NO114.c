//
//  NO114.c
//  NO114
//
//  Created by wanyakun on 2020/10/28.
//

#include "NO114.h"
#include <stdlib.h>

#pragma mark - 方案1 递归寻找前驱节点
TreeNode* help (TreeNode* root) {
    // base case
    if (root == NULL) return NULL;
    TreeNode* left = root->left;
    TreeNode* right = root->right;
    TreeNode* cur = root;
    if (root->left != NULL) {
        // 递归左子树
        root->right = help(left);
        root->left = NULL;
        // 展开左子树递归结果
        while (cur->right != NULL) {
            cur = cur->right;
        }
    }
    // 递归右子树
    cur->right = help(right);

    return root;
}

void flatten(TreeNode* root){
    help(root);
}

#pragma mark - 迭代选择前驱结点
void flatten0(TreeNode* root) {
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            TreeNode* next = curr->left;
            TreeNode* predecessor = next;
            while (predecessor->right != NULL) {
                predecessor = predecessor->right;
            }
            predecessor->right = curr->right;
            curr->left = NULL;
            curr->right = next;
        }
        curr = curr->right;
    }
}

#pragma mark - 方案2 前序遍历递归
int num;
void preOrderTraversal(TreeNode* root, TreeNode*** l) {
    if (root != NULL) {
        num++;
        (*l) = (TreeNode **)realloc((*l), sizeof(TreeNode)*num);
        (*l)[num-1] = root;
        preOrderTraversal(root->left, l);
        preOrderTraversal(root->right, l);
    }
}

void flatten1(TreeNode* root){
    num = 0;
    TreeNode** l = (TreeNode **)malloc(0);
    preOrderTraversal(root, &l);
    for (int i = 1; i < num; i++) {
        TreeNode *pre = l[i-1], *curr = l[i];
        pre->left = NULL;
        pre->right = curr;
    }
    free(l);
}

#pragma mark - 方案3 前序遍历迭代
void flatten2(TreeNode* root) {
    TreeNode** stk = malloc(0);
    TreeNode** vec = malloc(0);
    int stk_top = 0;
    int vec_len = 0;
    TreeNode* node = root;
    while (node != NULL || stk_top > 0) {
        while (node != NULL) {
            // vec 存储节点
            vec_len++;
            vec = realloc(vec, vec_len*sizeof(TreeNode));
            vec[vec_len-1] = node;
            // stk做遍历栈
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = node;
            
            node = node->left;
        }
        node = stk[--stk_top];
        node = node->right;
    }
    // 遍历结束重新设置左右节点
    for (int i = 1; i < vec_len; i++) {
        TreeNode *pre = vec[i-1], *curr = vec[i];
        pre->left = NULL;
        pre->right = curr;
    }
    free(vec);
    free(stk);
}

#pragma mark - 方案4 前序遍历,边迭代边展开
void flatten3(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    TreeNode** stk = malloc(sizeof(TreeNode));
    stk[0] = root;
    int stk_top = 1;

    TreeNode* pre = NULL;
    while (stk_top > 0) {
        TreeNode* curr = stk[--stk_top];
        if (pre != NULL) {
            pre->left = NULL;
            pre->right = curr;
        }
        TreeNode *left = curr->left, *right = curr->right;
        // 右子树入栈
        if (right != NULL) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = right;
        }
        // 左子树入栈
        if (left != NULL) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = left;
        }
        pre = curr;
    }
    free(stk);
}
