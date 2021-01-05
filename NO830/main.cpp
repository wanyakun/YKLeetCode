//
//  main.cpp
//  NO830
//
//  Created by wanyakun on 2021/1/5.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int start = 0, end = 0;
        while (end < s.length()) {
            // 窗口右滑
            end++;
            // 判断是否满足条件
            if(end == s.length() || s.at(start) != s.at(end)) {
                if(end - start >= 3) {;
                    res.push_back({start, end -1});
                }
                start = end;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>> res = s.largeGroupPositions("abcdddeeeeaabbbcd");
    for (vector<int> sub : res) {
        std::cout << "[" << sub[0] << "," << sub[1] << "]" << "\n";
    }
    return 0;
}
