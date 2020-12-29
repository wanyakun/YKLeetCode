//
//  main.cpp
//  NO42
//
//  Created by wanyakun on 2020/12/29.
//
/**
 42. 接雨水
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

  

 示例 1：



 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 输出：6
 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
 示例 2：

 输入：height = [4,2,0,3,2,5]
 输出：9
  

 提示：

 n == height.length
 0 <= n <= 3 * 104
 0 <= height[i] <= 105
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 方案三，双指针
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n-1;
        int res = 0;
        
        int l_max = height[0];  // 代表height[0...left]中最高的柱子
        int r_max = height[n-1];    // 代表height[rihgt..n-1]中最高的柱子
        while(left <= right) {
            l_max = max(l_max, height[left]);
            r_max = max(r_max, height[right]);
            // res += max(l_max, r_max) - heigt[i]
            if(l_max < r_max) {
                res += l_max - height[left];
                left++;
            } else {
                res += r_max - height[right];
                right--;
            }
        }
        return res;
    }
    // 方案二，使用备忘录
    int trap2(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        int res = 0;
        // 备忘录
        vector<int> l_max(n, 0);
        vector<int> r_max(n, 0);
        // base case
        l_max[0] = height[0];
        r_max[n-1] = height[n-1];
        // 从左到右找左边最高的柱子
        for(int i = 1; i < n; i++) {
            l_max[i] = max(l_max[i-1], height[i]);
        }
        // 从右往左找到右边最高的柱子
        for(int i = n-2; i >= 0; i--) {
            r_max[i] = max(r_max[i+1], height[i]);
        }
        for(int i = 1; i < n-1; i++) {
            res += min(l_max[i], r_max[i]) - height[i];
        }
        return res;
    }
    // 方案一，暴力递归
    int trap1(vector<int>& height) {
        int n = height.size();
        int res = 0;
        for(int i = 1; i < n-1; i++) {
            int l_max = 0, r_max = 0;
            // 找到右边最高的柱子
            for(int j = i; j < n; j++) {
                r_max = max(r_max, height[j]);
            }
            // 找到左边最高的柱子
            for(int j = i; j >= 0; j--) {
                l_max = max(l_max, height[j]);
            }
            res += min(l_max, r_max) - height[i];
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> height(12);
    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int res = s.trap(height);
    std::cout << res << "\n";
    return 0;
}
