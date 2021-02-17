//
//  main.cpp
//  Longest Increasing Subsequence
//
/**
 Given an integer array nums, return the length of the longest strictly increasing subsequence.

 A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

  

 Example 1:

 Input: nums = [10,9,2,5,3,7,101,18]
 Output: 4
 Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 Example 2:

 Input: nums = [0,1,0,3,2,3]
 Output: 4
 Example 3:

 Input: nums = [7,7,7,7,7,7,7]
 Output: 1
  

 Constraints:

 1 <= nums.length <= 2500
 -104 <= nums[i] <= 104
  

 Follow up:

 Could you come up with the O(n2) solution?
 Could you improve it to O(n log(n)) time complexity?
 */
//  Created by mingyue on 2021/2/17.
//  Copyright © 2021 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int numsCount = nums.size();
        vector<int> dp(numsCount, 1);
        vector<int>::iterator result;
        for (int i = 1; i < numsCount; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        result = max_element(dp.begin(), dp.end());
        return *result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int result = solution.lengthOfLIS(nums);
    cout << result << endl;
    return 0;
}
