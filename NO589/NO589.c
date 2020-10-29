//
//  NO589.c
//  NO589
//
//  Created by wanyakun on 2020/10/29.
//

#include "NO589.h"
#include <stdlib.h>

int* preorderNode(Node* root, int* returnSize) {
    // base case
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    // 结果存储
    int* result = malloc(sizeof(int));
    result[0] = root->val;
    *returnSize = 0;
    // 模拟栈
    Node** stk = malloc(sizeof(Node));
    stk[0] = root;
    int stk_top = 1;
    while(stk_top > 0) {
        // 出栈
        Node* node = stk[--stk_top];
        (*returnSize)++;
        result = realloc(result, (*returnSize)*sizeof(int));
        result[(*returnSize)-1] = node->val;
        //子节点入栈
        if ((node->numChildren) > 0) {
            stk_top += (node->numChildren);
            stk = realloc(stk, stk_top*sizeof(Node));
            for (int i = (node->numChildren) - 1; i >= 0; i--) {
                stk[stk_top - i - 1] = (node->children)[i];
            }
        }
    }
    free(stk);
    return result;
}
