//
//  NO114.h
//  NO114
//
//  Created by wanyakun on 2020/10/28.
//
/**
 114. 二叉树展开为链表
 给定一个二叉树，原地将它展开为一个单链表。

  

 例如，给定二叉树

     1
    / \
   2   5
  / \   \
 3   4   6
 将其展开为：

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 */
#ifndef NO114_h
#define NO114_h

#include <stdio.h>
#include "TreeNode.h"

void flatten(TreeNode* root);
void flatten1(TreeNode* root);
void flatten2(TreeNode* root);

#endif /* NO114_h */
