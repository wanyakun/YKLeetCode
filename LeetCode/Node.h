//
//  Node.h
//  LeetCode
//
//  Created by wanyakun on 2020/10/29.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>

typedef struct Node Node;

struct Node {
    int val;
    int numChildren;
    Node** children;
};

Node* createNode(int val, int numChildren, Node** children);

#endif /* Node_h */
