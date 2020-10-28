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
