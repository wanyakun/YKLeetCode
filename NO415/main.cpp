//
//  main.cpp
//  NO415
//
//  Created by wanyakun on 2020/12/31.
//
/**
 415. 字符串相加
 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

  

 提示：

 num1 和num2 的长度都小于 5100
 num1 和num2 都只包含数字 0-9
 num1 和num2 都不包含任何前导零
 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式

 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
// 123 + 456 = 579
    string addStrings(string num1, string num2) {
        // 获取两个字符串的最后一位的下标
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        // 保存进位
        int add = 0;
        // 保存结果
        string ans;
        // 倒序遍历两个字符串
        while(i >=0 || j >= 0 || add != 0) {
            // 如果num1下标小于0， 取0，否则去下标出字符， num2做同样操作
            int x = i >= 0 ? num1.at(i) - '0' : 0;
            int y = j >= 0 ? num2.at(j) - '0' : 0;
            // 相加
            int result = x + y + add;
            ans.push_back(result%10);
            add = result/10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        for(auto &c : ans) {
            c += '0';
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string res = s.addStrings("126", "456");
    std::cout << res << "\n";
    return 0;
}
