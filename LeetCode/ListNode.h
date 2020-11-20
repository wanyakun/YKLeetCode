//
//  ListNode.h
//  LeetCode
//
//  Created by wanyakun on 2020/11/20.
//

#ifndef ListNode_h
#define ListNode_h

#include <stdio.h>

typedef struct ListNode ListNode;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* createListNode(int val, ListNode* next);

void traverseListNode(ListNode* head);

#endif /* ListNode_h */
