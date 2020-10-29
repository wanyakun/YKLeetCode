//
//  Node.c
//  LeetCode
//
//  Created by wanyakun on 2020/10/29.
//

#include "Node.h"
#include <stdlib.h>

Node* createNode(int val, int numChildren, Node** children) {
    Node* node = malloc(sizeof(Node));
    node->val = val;
    node->numChildren = numChildren;
    node->children = children;
    return node;
}
