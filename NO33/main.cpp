//
//  main.cpp
//  NO33
//
//  Created by wanyakun on 2020/12/28.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        // base case
        if(!n) {
            return -1;
        }
        if(n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n -1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(target == nums[mid]) return mid;
            if(nums[0] <= nums[mid]) {
                // 左侧有序
                if(nums[0] <= target && target < nums[mid]) {
                    // target 在左侧
                    r = mid -1;
                } else {
                    // target 在右侧
                    l = mid + 1;
                }
            } else {
                // 右侧有序
                if(nums[mid] < target && target <= nums[n-1]) {
                    // target 在右侧
                    l = mid + 1;
                } else {
                    // target 在左侧
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<int> nums(7, 0);
    nums = {4,5,6,7,0,1,2};
    int res = s.search(nums, 0);
    std::cout << res << "\n";
    return 0;
}
