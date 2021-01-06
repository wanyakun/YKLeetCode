//
//  main.cpp
//  NO399
//
//  Created by wanyakun on 2021/1/6.
//
/**
 399. 除法求值
 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。

 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。

 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。

  

 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。

  

 示例 1：

 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 解释：
 条件：a / b = 2.0, b / c = 3.0
 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 示例 2：

 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 输出：[3.75000,0.40000,5.00000,0.20000]
 示例 3：

 输入：equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
 输出：[0.50000,2.00000,-1.00000,-1.00000]
  

 提示：

 1 <= equations.length <= 20
 equations[i].length == 2
 1 <= Ai.length, Bi.length <= 5
 values.length == equations.length
 0.0 < values[i] <= 20.0
 1 <= queries.length <= 20
 queries[i].length == 2
 1 <= Cj.length, Dj.length <= 5
 Ai, Bi, Cj, Dj 由小写英文字母与数字组成

 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    // 并集查找
    // 哈希表1，建立字符到其母节点的映射关系
    unordered_map<string, string> parents;
    // 哈希表2，建立字符到其母节点的权值
    unordered_map<string, double> weights;
    // 查 根节点
    // 在查的过程中合并到根节点的权值
    // 注意: 此处问题
    // string tmp = find(parents[a]);
    // weights[a] = weights[a]*weights[parents[a]];
    // a->b b->c 要先find(b),更新b的权重，再更新a的权重，否则会出错
    string find(string a) {
        if(parents[a] != a) {
            string tmp = find(parents[a]);
            weights[a] = weights[a]*weights[parents[a]];
            parents[a] = tmp;
        }
        return parents[a];
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 保存结果
        vector<double> res;
        // 1. 查并集初始化
        int n = equations.size();
        for(int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            // 初始化每个字符的母节点为自己，权值为1.0
            parents[a] = a;
            parents[b] = b;
            weights[a] = 1.0;
            weights[b] = 1.0;
        }
        // 2. 更新并查集权重
        for(int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            // 查找a的根节点， a->root_a, 并更新指向根节点的权值
            string root_a = find(a);
            // 建立 root_a->b的连接，并更新权值
            parents[root_a] = b;
            // a->root_a->b， a->b = a->root_a * root_a->b
            // values[i]: a->b的权值
            // weights[a]: a->root_a的权值（已知）
            // weights[roo_a]: root_a->b 权值，待求
            weights[root_a] = values[i]/weights[a];
        }
        // 3，计算最终结果
        int m = queries.size();
        for(int i = 0; i < m; i++) {
            string a = queries[i][0];
            string b = queries[i][1];
            // 如果
            // (1) 母节点哈希表不包含查询字符中的任意一个
            // (2) 两个字符最终的根节点不相同， 如a->c, b->d, ab不在一个集合，
            if(!parents.count(a) || !parents.count(b) || find(a) != find(b)) {
                res.push_back(-1.0);
            } else {
                res.push_back(weights[a]/weights[b]);
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
