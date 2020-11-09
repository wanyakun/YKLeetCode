//
//  NO111.c
//  NO111
//
//  Created by wanyakun on 2020/11/9.
//

#include "NO111.h"
#include <stdlib.h>

typedef struct TreeNode TreeNode;

int minDepth(TreeNode* root){
    if(root == NULL) return 0;
    TreeNode** queue = malloc(sizeof(TreeNode));
    int index = 0, length = 1;
    queue[0] = root;
    int depth = 1;
    while (index < length) {
        // 出队列
        int len = length - index;
        for (int i = 0; i < len; i++) {
            TreeNode* node = queue[index++];
            if(node->left == NULL && node->right == NULL) return depth;
            if(node->left != NULL) {
                queue = realloc(queue, (++length)*sizeof(TreeNode));
                queue[length-1] = node->left;
            }
            if(node->right != NULL) {
                queue = realloc(queue, (++length)*sizeof(TreeNode));
                queue[length-1] = node->right;
            }
        }
        depth++;
    }
    
    return depth;
}
