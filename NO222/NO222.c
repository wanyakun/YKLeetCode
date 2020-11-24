//
//  NO222.c
//  NO222
//
//  Created by wanyakun on 2020/11/24.
//

#include "NO222.h"
#include "stdbool.h"

bool exists(TreeNode* root, int level, int k) {
    int bits = 1 << (level -1);
    TreeNode* node = root;
    while(node != NULL && bits > 0) {
        if(!(bits & k)) {
            node = node->left;
        } else {
            node = node->right;
        }
        bits >>= 1;
    }
    return node != NULL;
}

int countNodes(TreeNode* root){
    if(root == NULL) return 0;
    int level = 0;
    TreeNode* node = root;
    while(node->left != NULL) {
        level++;
        node = node->left;
    }
    int low = 1 << level;
    int high = (1 << (level + 1)) -1;
    while(low < high) {
        int mid = low + (high - low + 1)/2;
        if(exists(root, level, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
 }

 int countNodes1(TreeNode* root){
     return root == NULL ? 0 : countNodes1(root->left) + countNodes1(root->right) + 1;
 }
