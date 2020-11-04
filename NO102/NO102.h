//
//  NO102.h
//  NO102
//
//  Created by wanyakun on 2020/11/4.
//
/**
 102. 二叉树的层序遍历
 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

  

 示例：
 二叉树：[3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 返回其层次遍历结果：

 [
   [3],
   [9,20],
   [15,7]
 ]
 */

#ifndef NO102_h
#define NO102_h

#include <stdio.h>
#include "TreeNode.h"

int** levelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes);

#endif /* NO102_h */
