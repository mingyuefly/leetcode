//
//  main.cpp
//  sliding window maxinum
//
/**
 Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

 Follow up:
 Could you solve it in linear time?

 Example:

 Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 Output: [3,3,5,5,6,7]
 Explanation:

 Window position                Max
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
  1 [3  -1  -3] 5  3  6  7       3
  1  3 [-1  -3  5] 3  6  7       5
  1  3  -1 [-3  5  3] 6  7       5
  1  3  -1  -3 [5  3  6] 7       6
  1  3  -1  -3  5 [3  6  7]      7
 */
//  Created by mingyue on 2020/8/16.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k <= 0) {
            return {};
        }
        deque<int> window;
        vector<int> result;
        
        for(int i = 0; i < k; i++)
        {
            while(!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        result.push_back(nums[window.front()]);
        
        for(int i = k; i < nums.size(); i++)
        {
            if (!window.empty() && window.front() == i - k) {
                window.pop_front();
            }
            
            while(!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            
            window.push_back(i);
            result.push_back(nums[window.front()]);
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    //vector<int> arr = {1,3,-1,-3,5,3,6,7};
    //vector<int> arr = {1,-1};
    //vector<int> arr = {7, 2, 4};
    vector<int> arr = {1,3,1,2,0,5};
    Solution solution = Solution();
    //vector<int> result = solution.maxSlidingWindow(arr, 3);
    //vector<int> result = solution.maxSlidingWindow(arr, 1);
    //vector<int> result = solution.maxSlidingWindow(arr, 2);
    vector<int> result = solution.maxSlidingWindow(arr, 3);
    for (int i = 0; i < result.size(); i++) {
        cout << result.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}
