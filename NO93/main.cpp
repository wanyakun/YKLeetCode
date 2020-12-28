//
//  main.cpp
//  NO93
//
//  Created by wanyakun on 2020/12/28.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

static constexpr int SEG_COUNT = 4;
vector<string> ans;
vector<int> segments;

void dfs(const string& s, int segId, int segStart) {
    // 如果已经找到了4段（segId从0开始），且字符串遍历完，则为一种结果，加入到ans中
    if(segId == SEG_COUNT) {
        if(segStart == s.size()) {
            string ipAddr;
            for(int i = 0; i < SEG_COUNT; i++) {
                ipAddr += to_string(segments[i]);
                if(i != SEG_COUNT-1) {
                    ipAddr += ".";
                }
            }
            ans.push_back(move(ipAddr));
        }
        return;
    }
    // 如果还没到4段ip地址，就已经遍历完字符串了，则提前回溯
    if(segStart == s.size()) {
        return;
    }
    // 由于ip段不能以0开头，如果遇到0， 只能做为1个段
    if(s[segStart] == '0') {
        segments[segId] = 0;
        dfs(s, segId+1, segStart+1);
    }
    // 一般情况，枚举每一种可能行，并递归
    int addr = 0;
    for(int i = segStart; i < s.size(); i++) {
        addr = addr*10 + (s[i] - '0');
        if(addr > 0 && addr <= 255) {
            segments[segId] = addr;
            dfs(s, segId+1, i+1);
        } else {
            break;
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    segments.resize(SEG_COUNT);
    dfs(s, 0, 0);
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string> res = restoreIpAddresses("25525511135");
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << "\n";
    }
    return 0;
}
