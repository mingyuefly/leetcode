//
//  main.cpp
//  Triangle
//
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/


//  Created by guomingyue on 2020/12/20.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 每次只需要记录一层的状态即可
        vector<int> mini = triangle[triangle.size() - 1];
        for (int i = triangle.size() - 2; i >= 0; i--) {
            // 从下到上递推到顶部
            for (int j = 0; j < triangle[i].size(); j++) {
                // 记录没一行的状态值
                mini[j] = triangle[i][j] + min(mini[j], mini[j + 1]);
            }
        }
        return mini[0];
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution solution = Solution();
    int minPath = solution.minimumTotal(triangle);
    cout << minPath << endl;
    
    return 0;
}
