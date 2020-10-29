//
//  NO129.c
//  NO129
//
//  Created by wanyakun on 2020/10/29.
//

#include "NO129.h"

int dfs(TreeNode *root, int preSum) {
    if(root == NULL) return 0;
    int sum = preSum*10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        return sum;
    }
    return dfs(root->left, sum) + dfs(root->right, sum);
}

int sumNumbers(TreeNode* root){
    return dfs(root, 0);
}
