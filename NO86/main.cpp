//
//  main.cpp
//  NO86
//
//  Created by wanyakun on 2021/1/4.
//
/**
 86. 分隔链表
 给你一个链表和一个特定值 x ，请你对链表进行分隔，使得所有小于 x 的节点都出现在大于或等于 x 的节点之前。

 你应当保留两个分区中每个节点的初始相对位置。

  

 示例：

 输入：head = 1->4->3->2->5->2, x = 3
 输出：1->2->2->4->3->5
 通过次数81,409提交次数131,070
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(x),  next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *before_head = new ListNode(-1);
        ListNode *before = before_head;
        ListNode *after_head = new ListNode(-1);
        ListNode *after = after_head;

        while(head != NULL) {
            if(head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        after->next = NULL;
        before->next = after_head->next;
        return before_head->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
