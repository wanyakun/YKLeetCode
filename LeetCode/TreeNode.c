//
//  TreeNode.c
//  NO226
//
//  Created by wanyakun on 2020/10/27.
//

#include <stdlib.h>
#include "TreeNode.h"
#include <stdio.h>

TreeNode* createTreeNode(int val, TreeNode* left, TreeNode* right) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

TreeNode* createTreeNodeWithNums(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return NULL;
    }
    TreeNode* root = malloc(sizeof(TreeNode));
    root->val = nums[0];
    TreeNode** stack = malloc(numsSize*sizeof(TreeNode*));
    stack[0] = root;
    int index = 0;
    int top = 1;
    for (int i = 1; i < numsSize-1; i = i + 2) {
        TreeNode* indexNode = stack[index];
        TreeNode* left = (nums[i] == NULL) ? NULL : createTreeNode(nums[i], NULL, NULL);
        TreeNode* right = (nums[i+1] == NULL) ? NULL :createTreeNode(nums[i+1], NULL, NULL);
        indexNode->left = left;
        indexNode->right = right;
        stack[top++] = left;
        stack[top++] = right;
        index++;
    }
    return root;
}
// 前序遍历，递归
void preOrderTraverse(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    printf("%d", root->val);
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);
}

// 前序遍历，迭代
void preOrderTraverse1(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    TreeNode** stk = malloc(sizeof(TreeNode));
    stk[0] = root;
    int stk_top = 1;
    while (stk_top > 0) {
        TreeNode* curr = stk[--stk_top];
        printf("%d", curr->val);
        if (curr->right) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = curr->right;
        }
        if (curr->left) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = curr->left;
        }
    }
}

// 前序遍历，迭代
void preOrderTraverse11(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    TreeNode** stk = malloc(0);
    int stk_top = 0;
    TreeNode* node = root;
    while (stk_top > 0 || node != NULL) {
        while (node != NULL) {
            printf("%d", node->val);
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = node;
            node = node->left;
        }
        node = stk[--stk_top];
        node = node->right;
    }
}

// 中序遍历，递归
void inOrderTravers(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inOrderTravers(root->left);
    printf("%d", root->val);
    inOrderTravers(root->right);
}

void inOrderTravers1(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    TreeNode** stk = malloc(sizeof(TreeNode));
    int stk_top = 0;
    TreeNode* node = root;
    while (stk_top > 0 || node != NULL) {
        while (node != NULL) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = node;
            node = node->left;
        }
        node = stk[--stk_top];
        printf("%d", node->val);
        node = node->right;
    }
}

// 后续序遍历，递归
void postOrderTravers(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrderTravers(root->left);
    postOrderTravers(root->right);
    printf("%d", root->val);
}

void postOrderTravers1(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    TreeNode** stk = malloc(sizeof(TreeNode));
    int stk_top = 0;
    TreeNode* node = root;
    TreeNode* pre = NULL; // 记录上一次遍历的节点
    while (stk_top > 0 || node != NULL) {
        while (node != NULL) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = node;
            node = node->left;
        }
        node = stk[--stk_top];
        if (node->right != NULL && node->right != pre) {
            stk_top++;
            stk = realloc(stk, stk_top*sizeof(TreeNode));
            stk[stk_top-1] = node;
            node = node->right;
        } else {
            printf("%d", node->val);
            pre = node;
            node = NULL;
        }
    }
}

void levelOrderTravers(TreeNode* root) {
    // base case
    if (root == NULL) {
        return;
    }
    TreeNode** queue = malloc(sizeof(TreeNode));
    int index = 0, length = 1; // 分别标示队列的下标和长度
    queue[0] = root;
    while(index < length) {
        // 出队
        TreeNode* node = queue[index];
        printf("%d", node->val);
        // 左节点入队
        if (node->left != NULL) {
            queue = realloc(queue, (++length)*sizeof(TreeNode));
            queue[length-1] = node->left;
        }
        // 右节点入队
        if (node->right != NULL) {
            queue = realloc(queue, (++length)*sizeof(TreeNode));
            queue[length-1] = node->right;
        }
        index++;
    }
}
