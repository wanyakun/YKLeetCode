//
//  main.cpp
//  NO96
//
//  Created by wanyakun on 2021/1/25.
//
/**
 96. 不同的二叉搜索树
 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

 示例:

 输入: 3
 输出: 5
 解释:
 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

    1         3     3      2      1
     \       /     /      / \      \
      3     2     1      1   3      2
     /     /       \                 \
    2     1         2                 3

 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // G[i] = F[0] + F[1] + ... + F[n];
    // F[i] = G[i-1]*G[n-i];
    int numTrees(int n) {
        vector<int> G(n+1, 0);
        G[0] = 1;
        G[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    int res = s.numTrees(3);
    std::cout << res << "\n";
    return 0;
}
