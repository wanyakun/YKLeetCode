//
//  main.cpp
//  Offer07
//
//  Created by wanyakun on 2021/1/7.
//
/**
 剑指 Offer 07. 重建二叉树
 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

  

 例如，给出

 前序遍历 preorder = [3,9,20,15,7]
 中序遍历 inorder = [9,3,15,20,7]
 返回如下的二叉树：

     3
    / \
   9  20
     /  \
    15   7
  

 限制：

 0 <= 节点个数 <= 5000

  

 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */
#include <iostream>
#include <vector>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode* build(vector<int>::iterator preBegin, vector<int>::iterator preEnd, vector<int>::iterator inBegin, vector<int>::iterator inEnd) {
        if(inBegin == inEnd) return NULL;
        TreeNode* node = new TreeNode(*preBegin);
        auto root = find(inBegin, inEnd, *preBegin);
        node->left = build(preBegin+1, preBegin+1+(root-inBegin), inBegin, root);
        node->right = build(preBegin+1+(root-inBegin), preEnd, root+1, inEnd);
        return node;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* res = s.buildTree(preorder, inorder);
    std::cout << "Hello, World!\n";
    return 0;
}
