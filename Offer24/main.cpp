//
//  main.cpp
//  Offer24
//
//  Created by wanyakun on 2020/12/30.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        return pre;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
