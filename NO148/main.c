//
//  main.c
//  NO148
//
//  Created by wanyakun on 2020/11/21.
//

#include <stdio.h>
#include "ListNode.h"
#include "NO148.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* node3 = createListNode(3, NULL);
    ListNode* node1 = createListNode(1, node3);
    ListNode* node2 = createListNode(2, node1);
    ListNode* node4 = createListNode(4, node2);

    ListNode* res = sortList(node4);
    traverseListNode(res);
    return 0;
}
