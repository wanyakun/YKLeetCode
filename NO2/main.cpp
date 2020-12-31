//
//  main.cpp
//  NO2
//
//  Created by wanyakun on 2020/12/31.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* curr = NULL;
        int plus = 0;
        while(l1 != NULL || l2 != NULL) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + plus;
            if(!head) {
                head = curr = new ListNode(sum%10);
            } else {
                curr->next = new ListNode(sum%10);
                curr = curr->next;
            }
            plus = sum/10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            
        }
        if(plus > 0) {
            curr->next = new ListNode(plus);
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);
    ListNode* curr = res;
    while (curr) {
        std::cout << curr->val << " -> ";
        curr = curr->next;
    }
    std::cout << "\n";
    return 0;
}
