//
//  main.cpp
//  NO151
//
//  Created by wanyakun on 2020/12/31.
//
/**
 151. 翻转字符串里的单词
 给定一个字符串，逐个翻转字符串中的每个单词。

 说明：

 无空格字符构成一个 单词 。
 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
  

 示例 1：

 输入："the sky is blue"
 输出："blue is sky the"
 示例 2：

 输入："  hello world!  "
 输出："world! hello"
 解释：输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 示例 3：

 输入："a good   example"
 输出："example good a"
 解释：如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 示例 4：

 输入：s = "  Bob    Loves  Alice   "
 输出："Alice Loves Bob"
 示例 5：

 输入：s = "Alice does not even like bob"
 输出："bob like even not does Alice"
  

 提示：

 1 <= s.length <= 104
 s 包含英文大小写字母、数字和空格 ' '
 s 中 至少存在一个 单词
  

 进阶：

 请尝试使用 O(1) 额外空间复杂度的原地解法。

 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 对整个字符串进行翻转
        reverse(s.begin(), s.end());
        
        int n = s.size();
        int idx = 0;
        for(int start = 0; start < n; start++) {
            if (s[start] != ' ') {
                // 填一个空白字符串，然后将idx移动到下一个单词开头位置
                if(idx != 0) s[idx++] = ' ';
                
                // end标记单词结束位置
                int end = start;
                while(end < n && s[end] != ' ') s[idx++] = s[end++];
                // 翻转单词
                reverse(s.begin()+idx -(end - start), s.begin()+idx);
                // 更新start 寻找下一个单词
                start = end;
            }
        }
        // 去除后面的空格
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    string res = s.reverseWords("the sky is blue");
    std::cout << res << "\n";
    return 0;
}
