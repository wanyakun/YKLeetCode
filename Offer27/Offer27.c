//
//  Offer27.c
//  Offer27
//
//  Created by wanyakun on 2020/12/10.
//

#include "Offer27.h"
#include <stdlib.h>

// 递归
 TreeNode* mirrorTree(TreeNode* root){
     if(root == NULL) return NULL;
     TreeNode* tmp = root->left;
     root->left = mirrorTree(root->right);
     root->right = mirrorTree(tmp);
     return root;
 }

// 辅助栈
TreeNode* mirrorTree1(TreeNode* root){
    if(root == NULL) return NULL;
    TreeNode** stack = malloc(1000*sizeof(TreeNode*));
    stack[0] = root;
    int size = 1;
    int index = 0;
    while(index < size) {
        TreeNode* node = stack[index];
        if(node->left) {
            stack[size++] = node->left;
        }
        if(node->right) {
            stack[size++] = node->right;
        }
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        index++;
    }
    return root;
}
