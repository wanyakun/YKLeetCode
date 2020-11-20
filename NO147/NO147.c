//
//  NO147.c
//  NO147
//
//  Created by wanyakun on 2020/11/20.
//

#include "NO147.h"
#include <stdlib.h>

ListNode* insertionSortList(ListNode* head){
    // base case
    if(head == NULL) return NULL;
    ListNode *res = malloc(sizeof(ListNode));
    res->val = 0;
    res->next = head;

    ListNode* lastSorted = head;
    ListNode* curr = head->next;
    while(curr != NULL) {
        if(lastSorted->val <= curr->val) {
            lastSorted = lastSorted->next;
        } else {
            ListNode* pre = res;
            while(pre->next->val <= curr->val) {
                pre = pre->next;
            }
            lastSorted->next = curr->next;
            curr->next = pre->next;
            pre->next = curr;
        }
        curr = lastSorted->next;
    }
    
    return res->next;
}
