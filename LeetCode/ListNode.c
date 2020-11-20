//
//  ListNode.c
//  LeetCode
//
//  Created by wanyakun on 2020/11/20.
//

#include "ListNode.h"
#include <stdlib.h>

ListNode* createListNode(int val, ListNode* next) {
    ListNode* node = malloc(sizeof(ListNode));
    node->val = val;
    node->next = next;
    return node;
}

void traverseListNode(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        printf("%d", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
