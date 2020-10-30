//
//  NO112.c
//  NO112
//
//  Created by wanyakun on 2020/10/30.
//

#include "NO112.h"
#include "TreeQueueNode.h"

bool dfs(TreeNode* root, int preSum, int sum) {
    if (root == NULL) return 0;
    int currSum = preSum + root->val;
    if (root->left == NULL && root->right == NULL) {
        return currSum == sum;
    } else {
        return dfs(root->left, currSum, sum) || dfs(root->right, currSum, sum);
    }
}


bool hasPathSum(TreeNode* root, int sum){
    return dfs(root, 0, sum);
}
// 递归2
bool hasPathSum1(TreeNode* root, int sum){
    if (root == NULL) return false;
    if (root->left == NULL && root->right == NULL) {
        return sum == root->val;
    }
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}


bool hasPathSum2(TreeNode* root, int sum){
    if(root == NULL) return false;
    // leftQueue 有用遍历， rightQueue用于扩散节点
    TreeQueueNode* leftQueue = createTreeQueueNode(root->val, root);
    TreeQueueNode* rightQueue = leftQueue;
    while(leftQueue != NULL) {
        // 取出节点
        TreeNode *currNode = leftQueue->treeNode;
        int tmp = leftQueue->val;
        if(currNode->left == NULL && currNode->right == NULL) {
            //找到叶子节点
            if (tmp == sum) return true;
        }
        // 左右侧节点入栈
        if(currNode->left != NULL) {
            TreeQueueNode *left = createTreeQueueNode(tmp+currNode->left->val, currNode->left);
            rightQueue->next = left;
            rightQueue = rightQueue->next;
        }
        // 右侧节点入栈
        if(currNode->right != NULL) {
            TreeQueueNode *right = createTreeQueueNode(tmp+currNode->right->val, currNode->right);
            rightQueue->next = right;
            rightQueue = rightQueue->next;
        }
        leftQueue = leftQueue->next;
    }
    return false;
}
