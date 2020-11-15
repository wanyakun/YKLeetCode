//
//  NO337.c
//  NO337
//
//  Created by wanyakun on 2020/11/15.
//

#include "NO337.h"
#include "uthash.h"

int max(int a, int b) {
    return a > b ? a : b;
}

// 方案二，二维数组存放抢和不抢的结果
// arr[0],arr[1] 表示不抢和抢
int* dp2(TreeNode* root) {
    int* res = malloc(2*sizeof(int));
    if(root == NULL) {
        res[0] = 0;
        res[1] = 0;
        return res;
    }
    int* left = dp2(root->left);
    int* right = dp2(root->right);
    // 抢, 叶子结点不抢
    int do_it = root->val + left[0] + right[0];
    // 不抢, 字节点可抢可不抢，看哪种情况大
    int not_do = max(left[0], left[1]) + max(right[0], right[1]);
    res[0] = not_do;
    res[1] = do_it;
    return res;
}

int rob2(TreeNode* root) {
    int* res = dp2(root);
    return max(res[0], res[1]);
}

 // 方案1，用HashTable记录缓存, 居然超出时间限制
 typedef struct {
     TreeNode* node;
     int val;
     UT_hash_handle hh;
 } unorder_map;


 int dp(TreeNode* root, unorder_map* memo) {
     if(root == NULL) return 0;
     unorder_map* tmp = NULL;
     HASH_FIND(hh, memo, &root, sizeof(TreeNode), tmp);
     if(tmp) {
         // 备忘录消除子问题
         return tmp->val;
     } else {
         // 抢, 然后抢下下家
         int do_it = root->val + (root->left == NULL ? 0 : dp(root->left->left, memo)+dp(root->left->right, memo)) + (root->right == NULL ? 0 : dp(root->right->left, memo)+dp(root->right->right, memo));
         // 不抢
         int not_do = dp(root->left, memo)+dp(root->right, memo);
         int res = max(do_it, not_do);
         tmp = malloc(sizeof(unorder_map));
         tmp->node = root;
         tmp->val = res;
         HASH_ADD(hh, memo, node, sizeof(TreeNode), tmp);
         return res;
     }
 }

 int rob(TreeNode* root) {
     unorder_map* memo = NULL;
     return dp(root, memo);
 }
