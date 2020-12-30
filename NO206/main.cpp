//
//  main.cpp
//  NO206
//
//  Created by wanyakun on 2020/12/30.
//

#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = NULL;
        ListNode* currNode = head;
        while(currNode != NULL) {
            ListNode* tmpNode = currNode->next;
            currNode->next = preNode;
            preNode = currNode;
            currNode = tmpNode;
        }
        return preNode;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...    
    std::cout << "Hello, World!\n";
    return 0;
}
