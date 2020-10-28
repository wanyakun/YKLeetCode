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

#endif /* TreeNode_h */
