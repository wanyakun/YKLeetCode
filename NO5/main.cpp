//
//  main.cpp
//  NO5
//
//  Created by wanyakun on 2020/11/27.
//
/**
 5. 最长回文子串
 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

 示例 1：

 输入: "babad"
 输出: "bab"
 注意: "aba" 也是一个有效答案。
 示例 2：

 输入: "cbbd"
 输出: "bb"

 */
#include <iostream>
#include <string>
using namespace std;

string palindrome(string& s, int l, int r) {
    while(l >=0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l+1, r - l -1);
}
string longestPalindrome(string s) {
    string res;
    for(int i = 0; i < s.size(); i++) {
        // 以s[i]为中心的最长回文字符
        string str1 = palindrome(s, i, i);
        // 以s[i], s[i+1]为中心的最长回文字符
        string str2 = palindrome(s, i, i+1);
        res = res.size() > str1.size() ? res : str1;
        res = res.size() > str2.size() ? res : str2;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "babad";
    string res = longestPalindrome(s);
    std::cout << res << "\n";
    return 0;
}
