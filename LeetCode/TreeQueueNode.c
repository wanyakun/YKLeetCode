//
//  TreeQueueNode.c
//  LeetCode
//
//  Created by wanyakun on 2020/10/30.
//

#include "TreeQueueNode.h"
#include <stdlib.h>

TreeQueueNode* createTreeQueueNode(int val, TreeNode* treeNode) {
    TreeQueueNode* treeQueueNode = malloc(sizeof(TreeQueueNode));
    treeQueueNode->val = val;   // 存储路径之和
    treeQueueNode->treeNode = treeNode;
    treeQueueNode->next = NULL;
    return treeQueueNode;
}
