//
//  main.cpp
//  Maximum Product Subarray
//
/**
 Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

 Example 1:

 Input: [2,3,-2,4]
 Output: 6
 Explanation: [2,3] has the largest product 6.
 Example 2:

 Input: [-2,0,-1]
 Output: 0
 Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 */
//  Created by guomingyue on 2020/12/27.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> maxs(nums.size(), 0);
        vector<int> minus_maxs(nums.size(), 0);
        int currentMax = 0;
        maxs[0] = nums[0];
        minus_maxs[0] = nums[0];
        currentMax = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int tmp0 = maxs[i - 1] * nums[i];
            int tmp1 = minus_maxs[i - 1] * nums[i];
            maxs[i] = max(max(tmp0, tmp1), nums[i]);
            minus_maxs[i] = min(min(tmp0, tmp1), nums[i]);
            currentMax = max(currentMax, maxs[i]);
        }
        return currentMax;
    }
};

int main(int argc, const char * argv[]) {
    //vector<int> nums = {2,3,-2,4};
    //vector<int> nums = {2,3,-2,4,-2};
    vector<int> nums = {2,3,-2,4,-2,-1,-2};
    //vector<int> nums = {-2,0,-1};
    //vector<int> nums = {0, 2};
    Solution solution = Solution();
    int result = solution.maxProduct(nums);
    cout << result << endl;
    return 0;
}
