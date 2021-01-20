//
//  main.cpp
//  NO628
//
//  Created by wanyakun on 2021/1/20.
//
/**
 628. 三个数的最大乘积
 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

 示例 1:

 输入: [1,2,3]
 输出: 6
 示例 2:

 输入: [1,2,3,4]
 输出: 24
 注意:

 给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 线性扫描，找出最大的三个数和最小的两个数
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for(int x : nums) {
            if(x < min1) {
                min2 = min1;
                min1 = x;
            } else if( x < min2) {
                min2 = x;
            }
            if(x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if(x > max2) {
                max3 = max2;
                max2 = x;
            } else if(x > max3) {
                max3 = x;
            }
        }
        return max(min1*min2*max1, max3*max2*max1);
    }
    int maximumProduct1(vector<int>& nums) {
        // 1. 先进行排序
        // 2. 如果全为正数或全为负数，则为最后三个数的乘积，若有正数也有负数，则为两个最小负数和最大正数乘积
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return max(nums[len-1]*nums[len-2]*nums[len-3], nums[0]*nums[1]*nums[len-1]);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums1 = {1,2,3};
    int res1 = s.maximumProduct(nums1);
    std::cout << res1 << "\n";
    
    vector<int> nums2 = {1,2,3};
    int res2 = s.maximumProduct1(nums2);
    std::cout << res2 << "\n";
    return 0;
}
