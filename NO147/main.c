//
//  main.c
//  NO147
//
//  Created by wanyakun on 2020/11/20.
//

#include <stdio.h>
#include "ListNode.h"
#include "NO147.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode* node3 = createListNode(3, NULL);
    ListNode* node1 = createListNode(1, node3);
    ListNode* node2 = createListNode(2, node1);
    ListNode* node4 = createListNode(4, node2);

    ListNode* res = insertionSortList(node4);
    
    traverseListNode(res);
    return 0;
}
