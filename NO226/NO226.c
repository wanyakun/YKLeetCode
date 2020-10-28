//
//  NO226.c
//  NO226
//
//  Created by wanyakun on 2020/10/27.
//

#include "NO226.h"
#include <stdlib.h>

#pragma mark - 方案一递归
TreeNode* invertTree1(TreeNode* root){
    //base case
    if (root == NULL) return NULL;
    // 前序
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree1(root->left);
    invertTree1(root->right);
    return root;
}

TreeNode* invertTree2(TreeNode* root){
    //base case
    if (root == NULL) return NULL;
    TreeNode* left = invertTree2(root->left);
    TreeNode* right = invertTree2(root->right);
    // 后序
    root->left = right;
    root->right = left;
    return root;
}
