//
//  TreeNode.h
//  NO226
//
//  Created by wanyakun on 2020/10/27.
//

#ifndef TreeNode_h
#define TreeNode_h

typedef struct TreeNode TreeNode;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode* createTreeNode(int val, TreeNode* left, TreeNode* right);
void preOrderTraverse(TreeNode* root);
void preOrderTraverse1(TreeNode* root);
void preOrderTraverse11(TreeNode* root);
void inOrderTravers(TreeNode* root);
void inOrderTravers1(TreeNode* root);
void postOrderTravers(TreeNode* root);
void postOrderTravers1(TreeNode* root);
void levelOrderTravers(TreeNode* root);

#endif /* TreeNode_h */
