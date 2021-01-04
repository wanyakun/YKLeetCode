//
//  main.cpp
//  NO69
//
//  Created by wanyakun on 2021/1/4.
//
/**
 69. x 的平方根
 实现 int sqrt(int x) 函数。

 计算并返回 x 的平方根，其中 x 是非负整数。

 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

 示例 1:

 输入: 4
 输出: 2
 示例 2:

 输入: 8
 输出: 2
 说明: 8 的平方根是 2.82842...,
      由于返回类型是整数，小数部分将被舍去。
 */
#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        // 二分查找 x的平方根的整数部分res 是满足k² <= x的最大k值，对k进行二分查找
        int left = 0, right = x, res = -1;
        while(left <= right) {
            int mid = left + (right-left)/2;
            if((long long)mid*mid <= x) {
                res = mid;
                left = mid +1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    int res = s.mySqrt(8);
    std::cout << res << "\n";
    return 0;
}
