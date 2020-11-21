//
//  NO148.c
//  NO148
//
//  Created by wanyakun on 2020/11/21.
//

#include "NO148.h"
#include <stdlib.h>

ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode* dummyHead = malloc(sizeof(ListNode));
    dummyHead->val = 0;
    ListNode *tmp = dummyHead, *tmp1 = head1, *tmp2 = head2;
    while(tmp1 != NULL && tmp2 != NULL) {
        if(tmp1->val <= tmp2->val) {
            tmp->next = tmp1;
            tmp1 = tmp1->next;
        } else {
            tmp->next = tmp2;
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    if(tmp1 != NULL) {
        tmp->next = tmp1;
    } else if(tmp2 != NULL) {
        tmp->next = tmp2;
    }
    return dummyHead->next;
}

// 并归排序，自底而上
ListNode* sortList(ListNode *head) {
    if(head == NULL) {
        return head;
    }
    // 计算出链表长度
    int length = 0;
    ListNode* node = head;
    while(node != NULL) {
        length++;
        node = node->next;
    }
    ListNode* dummyHead = malloc(sizeof(ListNode));
    dummyHead->next = head;
    // 子链表长度从1开始，每次长度增加一倍
    for(int subLength = 1; subLength < length; subLength <<= 1) {
        ListNode *pre = dummyHead, *curr = dummyHead->next;
        while(curr != NULL) {
            ListNode* head1 = curr;
            for(int i = 1; i < subLength && curr->next != NULL; i++) {
                curr = curr->next;
            }
            ListNode* head2 = curr->next;
            curr->next = NULL;
            curr = head2;
            for(int i = 1; i < subLength && curr != NULL && curr->next != NULL; i++) {
                curr = curr->next;
            }
            ListNode* next = NULL;
            if(curr != NULL) {
                next = curr->next;
                curr->next = NULL;
            }
            ListNode* merged = merge(head1, head2);
            pre->next = merged;
            while(pre->next != NULL) {
                pre = pre->next;
            }
            curr = next;
        }
    }
    return dummyHead->next;
}

//归并排序, 自顶而下
 ListNode* toSortList(ListNode* head, ListNode* tail) {
     if(head == NULL) {
         return head;
     }
     if(head->next == tail) {
         head->next = NULL;
         return head;
     }
     ListNode *slow = head, *fast = head;
     while(fast != tail) {
         slow = slow->next;
         fast = fast->next;
         if(fast != tail) {
             fast = fast->next;
         }
     }
     ListNode* mid = slow;
     return merge(toSortList(head, mid), toSortList(mid, tail));
 }

 ListNode* sortList1(ListNode *head) {
     return toSortList(head, NULL);
 }


// 插入排序，时间复杂度O(n²)
 ListNode* sortList2(ListNode* head){
     //base case
     if(head == NULL) return NULL;
     ListNode* res = malloc(sizeof(ListNode));
     res->val = 0;
     res->next = head;

     ListNode* lastSortted = head;
     ListNode* curr = head->next;
     while(curr != NULL) {
         if(curr->val >= lastSortted->val) {
             lastSortted = lastSortted->next;
         } else {
             ListNode* pre = res;
             while(pre->next->val <= curr->val) {
                 pre = pre->next;
             }
             lastSortted->next = curr->next;
             curr->next = pre->next;
             pre->next = curr;
         }
         curr = lastSortted->next;
     }
     return res->next;
 }
