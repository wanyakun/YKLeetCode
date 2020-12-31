//
//  main.cpp
//  NO43
//
//  Created by wanyakun on 2020/12/31.
//
/**
 43. 字符串相乘
 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

 示例 1:

 输入: num1 = "2", num2 = "3"
 输出: "6"
 示例 2:

 输入: num1 = "123", num2 = "456"
 输出: "56088"
 说明：

 num1 和 num2 的长度小于110。
 num1 和 num2 只包含数字 0-9。
 num1 和 num2 均不以零开头，除非是数字 0 本身。
 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 两个字符串相加
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
    
    string multiply(string num1, string num2) {
        // base case
        if(num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();
        string ans = "0";
        for(int i = m - 1; i >= 0; i--) {
            // 保存字符串1 当前下标和字符串2相乘的结果
            string result;
            // 保存进位
            int add = 0;
            // 相当于翻转后乘以10的倍数
            for(int j = m - 1; j > i; j--) {
                result.push_back(0);
            }
            // 分别于第二个字符串的每一位相乘，并加上进位
            int x = num1.at(i) - '0';
            for(int j = n -1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                int curr = x*y + add;
                result.push_back(curr%10);
                add = curr/10;
            }
            // 进位有可能大于10
            while(add != 0) {
                result.push_back(add%10);
                add = add / 10;
            }
            // 对当前轮结果进行翻转
            reverse(result.begin(), result.end());
            for(auto &c : result) {
                c += '0';
            }
            ans = addStrings(ans, result);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string res = s.multiply("123", "456");
    std::cout << res << "\n";
    return 0;
}
