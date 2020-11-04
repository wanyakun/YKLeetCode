//
//  NO107.h
//  NO107
//
//  Created by wanyakun on 2020/11/4.
//
/**
 107. 二叉树的层次遍历 II
 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

 例如：
 给定二叉树 [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 返回其自底向上的层次遍历为：

 [
   [15,7],
   [9,20],
   [3]
 ]
 */
#ifndef NO107_h
#define NO107_h

#include <stdio.h>
#include "TreeNode.h"

int** levelOrderBottom(TreeNode* root, int* returnSize, int** returnColumnSizes);
int** levelOrderBottom1(TreeNode* root, int* returnSize, int** returnColumnSizes);

#endif /* NO107_h */
