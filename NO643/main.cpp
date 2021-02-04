//
//  main.cpp
//  NO643
//
//  Created by wanyakun on 2021/2/4.
//
/**
 643. 子数组最大平均数 I
 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

  

 示例：

 输入：[1,12,-5,-6,50,3], k = 4
 输出：12.75
 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
  

 提示：

 1 <= k <= n <= 30,000。
 所给数据范围 [-10,000，10,000]。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        for(int i = k; i < n; i++) {
            sum = sum - nums[i-k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum)/k;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums = {1,12,-5,-6,50,3};
    double res = s.findMaxAverage(nums, 4);
    std::cout << res << "\n";
    return 0;
}
