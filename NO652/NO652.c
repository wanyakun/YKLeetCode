//
//  NO652.c
//  NO652
//
//  Created by wanyakun on 2020/11/20.
//

#include "NO652.h"
#include "uthash.h"
#include <stdlib.h>

typedef struct TreeNode TreeNode;
typedef struct {
    char* str;
    int cnt;
    UT_hash_handle hh;
} unorder_map;
unorder_map* memo; // 记录所有子树及出现次数
TreeNode** res; // 记录结果
int resSize;

char* traverse(TreeNode* root) {
    if(root == NULL) {
        return "#";
    }
    char* left = traverse(root->left);
    char* right = traverse(root->right);
    char* subTree = malloc((strlen(left)+strlen(right)+3)*sizeof(char));
    sprintf(subTree, "%s,%s,%d", left, right, root->val);
    unorder_map* tmp = NULL;
    HASH_FIND_STR(memo, subTree, tmp);
    if(tmp == NULL) {
        tmp = malloc(sizeof(unorder_map));
        tmp->str = subTree;
        tmp->cnt = 1;
        HASH_ADD_STR(memo, str, tmp);
    } else if(tmp->cnt == 1) {
        res = realloc(res, (++resSize)*sizeof(TreeNode));
        res[resSize-1] = root;
        tmp->cnt += 1;
    } else {
        tmp->cnt += 1;
    }
    return subTree;
}

TreeNode** findDuplicateSubtrees(TreeNode* root, int* returnSize){
    res = malloc(sizeof(TreeNode));
    resSize = 0;
    traverse(root);
    *returnSize = resSize;
    return res;
}
