//
//  NO103.h
//  NO103
//
//  Created by wanyakun on 2020/12/22.
//

/**
 103. 二叉树的锯齿形层序遍历
 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 例如：
 给定二叉树 [3,9,20,null,null,15,7],

     3
    / \
   9  20
     /  \
    15   7
 返回锯齿形层序遍历如下：

 [
   [3],
   [20,9],
   [15,7]
 ]

 */
#ifndef NO103_h
#define NO103_h

#include <stdio.h>
#include "TreeNode.h"

int** zigzagLevelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes);

#endif /* NO103_h */
