//
//  Offer27.h
//  Offer27
//
//  Created by wanyakun on 2020/12/10.
//
/**
 剑指 Offer 27. 二叉树的镜像
 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

 例如输入：

      4
    /   \
   2     7
  / \   / \
 1   3 6   9
 镜像输出：

      4
    /   \
   7     2
  / \   / \
 9   6 3   1

  

 示例 1：

 输入：root = [4,2,7,1,3,6,9]
 输出：[4,7,2,9,6,3,1]
 */
#ifndef Offer27_h
#define Offer27_h

#include <stdio.h>
#include "TreeNode.h"

TreeNode* mirrorTree(TreeNode* root);
TreeNode* mirrorTree1(TreeNode* root);
#endif /* Offer27_h */