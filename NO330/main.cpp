//
//  main.cpp
//  NO330
//
//  Created by wanyakun on 2020/12/29.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //  保存结果
        int res = 0;
        // 被覆盖的值
        long long x = 1;
        int len = nums.size();
        // 变量数组下班
        int i = 0;
        while(x <= n) {
            if(i < len && nums[i] <= x) {
                // 如果当前数字在覆盖范围内，被覆盖区间增加到x + num[i]
                x += nums[i];
                i++;
            } else {
                // 如果当前数字不在覆盖范围，内，则需要将x补充到数组中，被覆盖区间增加到2x，并更新结果
                x *= 2;
                res++;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> nums(3, 0);
    nums = {1,5, 10};
    int res = s.minPatches(nums, 20);
    std::cout << res << "\n";
    return 0;
}
