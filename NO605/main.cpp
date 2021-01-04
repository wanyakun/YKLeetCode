//
//  main.cpp
//  NO605
//
//  Created by wanyakun on 2021/1/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 标示可以种的花的数量
        int count = 0;
        // 数组长度
        int m = flowerbed.size();
        // 标示上一个已经种了花的位置
        int pre = -1;
        // 从左往右遍历数组，当遇到flowered[1] = 1时，计算pre和i之间内可以种植花的最多数量，然后令pre = i，继续遍历
        // pre和i之间可以种植花的最大数量为 (i-pre-2)/2
        for (int i = 0; i < m; i++) {
            if(flowerbed[i] == 1) {
                if(pre < 0) {
                    count += i/2;
                } else {
                    count += (i - pre - 2)/2;
                }
                pre = i;
            }
        }
        // 计算最后一个区间内可以种植花的数量
        if(pre < 0) {
            count += (m + 1)/2;
        } else {
            count += (m - pre - 2)/2;
        }
        return n <= count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> flowered(5, 0);
    flowered[0] = 1;
    flowered[4] = 1;
    Solution s;
    bool res = s.canPlaceFlowers(flowered, 1);
    std::cout << res << "\n";
    
    return 0;
}
