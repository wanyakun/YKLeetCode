//
//  main.cpp
//  NO1046
//
//  Created by wanyakun on 2020/12/30.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int s : stones) {
            q.push(s);
        }
        while(q.size() > 1) {
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if(x > y) {
                q.push(x-y);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> stones(6);
    stones = {2,7,4,1,8,1};
    int res = s.lastStoneWeight(stones);
    std::cout << res << "\n";
    return 0;
}
