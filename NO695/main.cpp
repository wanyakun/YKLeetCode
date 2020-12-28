//
//  main.cpp
//  NO695
//
//  Created by wanyakun on 2020/12/28.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {1, -1, 0, 0};
public:
    // 深度有先搜索
    // 如果我们在一个土地上，以 4 个方向探索与之相连的每一个土地（以及与这些土地相连的土地），那么探索过的土地总数将是该连通形状的面积。
    // 为了确保每个土地访问不超过一次，我们每次经过一块土地时，将这块土地的值置为 0。这样我们就不会多次访问同一土地。
    int dfs(vector<vector<int>>& grid, int curr_i, int curr_j) {
        if(curr_i < 0 || curr_j < 0 || curr_i == grid.size() || curr_j == grid[0].size() || grid[curr_i][curr_j] != 1) {
            return 0;
        }
        grid[curr_i][curr_j] = 0;
        int ans = 1;
        for(int i = 0; i < 4; i++) {
            int next_i = curr_i + dx[i], next_j = curr_j + dy[i];
            ans += dfs(grid, next_i, next_j);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 存储最大的岛屿面积
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution s;
    vector<vector<int>> grid(4, vector<int>(5, 0));
    grid[0][0] = 1;
    grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[2][3] = 1;
    grid[2][4] = 1;
    grid[3][3] = 1;
    grid[3][4] = 1;
    int res = s.maxAreaOfIsland(grid);
    std::cout<< res << "\n";
    return 0;
}
