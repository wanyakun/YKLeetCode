//
//  NO145.h
//  NO145
//
//  Created by wanyakun on 2020/11/3.
//
/**
 145. 二叉树的后序遍历
 给定一个二叉树，返回它的 后序 遍历。

 示例:

 输入: [1,null,2,3]
    1
     \
      2
     /
    3

 输出: [3,2,1]
 进阶: 递归算法很简单，你可以通过迭代算法完成吗？


 */
#ifndef NO145_h
#define NO145_h

#include <stdio.h>
#include "TreeNode.h"

int* postorderTraversal(TreeNode* root, int* returnSize);
int* postorderTraversal1(TreeNode* root, int* returnSize);

#endif /* NO145_h */
