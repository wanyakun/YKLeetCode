//
//  NO589.h
//  NO589
//
//  Created by wanyakun on 2020/10/29.
//

/**
 589. N叉树的前序遍历
 给定一个 N 叉树，返回其节点值的前序遍历。

 例如，给定一个 3叉树 :

  



  

 返回其前序遍历: [1,3,5,6,2,4]。

  

 说明: 递归法很简单，你可以使用迭代法完成此题吗?
 */

#ifndef NO589_h
#define NO589_h

#include <stdio.h>
#include "Node.h"

int* preorderNode(Node* root, int* returnSize);

#endif /* NO589_h */
