//
//  TreeNode.c
//  NO226
//
//  Created by wanyakun on 2020/10/27.
//

#include <stdlib.h>
#include "TreeNode.h"

TreeNode* createNode(int val, TreeNode* left, TreeNode* right) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

// 前序遍历，递归
void preOrderTraverse(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    printf("%d", root->val);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

// 前序遍历，迭代
void preOrderTraverse1(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    TreeNode** stk = malloc(sizeof(TreeNode));
    stk[0] = root;
    int stk_top = 1;
    while (stk_top > 0) {
        TreeNode* curr = stk[--stk_top];
        printf("%d", curr->val);
        if (curr->right) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = curr->right;
        }
        if (curr->left) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = curr->left;
        }
    }
}

// 中序遍历，递归
void inOrderTravers(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    preOrderTraverse(root->left);
    printf("%d", root->val);
    preOrderTraverse(root->right);
}

// 后续序遍历，递归
void postOrderTravers(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
    printf("%d", root->val);
}
