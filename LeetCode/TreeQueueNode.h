//
//  TreeQueueNode.h
//  LeetCode
//
//  Created by wanyakun on 2020/10/30.
//

#ifndef TreeQueueNode_h
#define TreeQueueNode_h

#include "TreeNode.h"

typedef struct TreeQueueNode TreeQueueNode;
struct TreeQueueNode {
    int val;
    TreeNode *treeNode;
    TreeQueueNode *next;
};

TreeQueueNode* createTreeQueueNode(int val, TreeNode* treeNode);

#endif /* TreeQueueNode_h */
