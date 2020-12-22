//
//  NO103.c
//  NO103
//
//  Created by wanyakun on 2020/12/22.
//

#include "NO103.h"
#include <stdlib.h>
#include <stdbool.h>

#define N 2000
int** zigzagLevelOrder(TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    // 定义返回内容
    int** ans = malloc(N*sizeof(int*));
    *returnColumnSizes = malloc(N*sizeof(int));
    *returnSize = 0;
    // 定义队列
    TreeNode* queue[N];
    int left = 0; int right = 1;
    queue[0] = root;
    // 是否为向左
    bool isOrderLeft = true;
    while(left < right) {
        // 存储当前层的个数
        int levelList[N*2];
        // 以N作为起点，如果是从左到右，则往右侧添加数据，否则往左侧添加数据
        int front = N, rear = N;
        // 当前层的个数
        int size = right - left;
        for(int i = 0; i < size; i++) {
            TreeNode* node = queue[left++];
            if(isOrderLeft) {
                levelList[rear++] = node->val;
            } else {
                levelList[--front] = node->val;
            }
            // 队列中都是层遍历存储的节点
            if(node->left) {
                queue[right++] = node->left;
            }
            if(node->right) {
                queue[right++] = node->right;
            }
        }
        // 一层中的数据放入到levelList中，取出放入ans中
        int leveSize = rear - front;
        int* tmp = malloc(leveSize*sizeof(int));
        for(int i = 0; i < leveSize; i++) {
            tmp[i] = levelList[i+front];
        }
        ans[*returnSize] = tmp;
        (*returnColumnSizes)[*returnSize] = leveSize;
        (*returnSize)++;
        isOrderLeft = !isOrderLeft;
    }
    return ans;
}
