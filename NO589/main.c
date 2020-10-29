//
//  main.c
//  NO589
//
//  Created by wanyakun on 2020/10/29.
//

#include <stdio.h>
#include <stdlib.h>
#include "NO589.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    Node *node5 = createNode(5, 0, NULL);
    Node *node6 = createNode(6, 0, NULL);
    Node *node2 = createNode(2, 0, NULL);
    Node *node4 = createNode(4, 0, NULL);
    Node** node3Child = malloc(2*sizeof(Node));
    node3Child[0] = node5;
    node3Child[1] = node6;
    Node *node3 = createNode(3, 2, node3Child);

    Node** node1Child = malloc(3*sizeof(Node));
    node1Child[0] = node3;
    node1Child[1] = node2;
    node1Child[2] = node4;

    Node *node1 = createNode(1, 3, node1Child);
    
    int returnSize = 0;

    int* result = preorderNode(node1, &returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    
    return 0;
}
