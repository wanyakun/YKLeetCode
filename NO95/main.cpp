//
//  main.cpp
//  NO95
//
//  Created by wanyakun on 2021/1/20.
//
/**
 95. 不同的二叉搜索树 II
 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

  

 示例：

 输入：3
 输出：
 [
   [1,null,3,2],
   [3,2,null,1],
   [3,1,null,null,2],
   [2,1,3],
   [1,null,2,null,3]
 ]
 解释：
 以上的输出对应以下 5 种不同结构的二叉搜索树：

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3
  

 提示：

 0 <= n <= 8
 */

#include <iostream>
#include <vector>


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<TreeNode*> generateTrees(int start, int end) {
        if( start > end) {
            return { nullptr };
        }
        vector<TreeNode*> allTrees;
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i-1);
            vector<TreeNode*> rightTrees = generateTrees(i+1, end);
            for(auto& left : leftTrees) {
                for(auto& right : rightTrees) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left;
                    currTree->right = right;
                    allTrees.emplace_back(currTree);
                }
            }
        }

        return allTrees;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n) return {};
        return generateTrees(1, n);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
