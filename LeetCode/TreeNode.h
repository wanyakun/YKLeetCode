//
//  TreeNode.h
//  NO226
//
//  Created by wanyakun on 2020/10/27.
//

#ifndef TreeNode_h
#define TreeNode_h

#include <stdio.h>

typedef struct TreeNode TreeNode;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* createNode(int val, TreeNode* left, TreeNode* right);
void preOrderTraverse(TreeNode* root);
void preOrderTraverse1(TreeNode* root);
void inOrderTravers(TreeNode* root);
void postOrderTravers(TreeNode* root);

#endif /* TreeNode_h */
