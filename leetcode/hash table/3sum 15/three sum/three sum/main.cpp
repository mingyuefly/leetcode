//
//  main.cpp
//  three sum
//
/**
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 Note:

 The solution set must not contain duplicate triplets.

 Example:

 Given array nums = [-1, 0, 1, 2, -1, -4],

 A solution set is:
 [
   [-1, 0, 1],
   [-1, -1, 2]
 ]
 */
//  Created by mingyue on 2020/8/20.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> attendsVectors;
        set<int> firsts;
        unsigned long size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            int a = nums[i];
            if (firsts.count(a)) {
                continue;
            } else {
                firsts.insert(a);
            }
            int target = 0 - a;
            unordered_map<int, int> dic;
            vector<int> addends;
            set<int> seconds;
            for (int j = i + 1; j < size; j++) {
                if (dic.count(target - nums[j])) {
                    if (seconds.count(target - nums[j])) {
                        continue;
                    } else {
                        seconds.insert(target - nums[j]);
                        addends.push_back(a);
                        addends.push_back(nums[dic[target - nums[j]]]);
                        addends.push_back(nums[j]);
                        attendsVectors.push_back(addends);
                        addends.clear();
                    }
                } else {
                    dic[nums[j]] = j;
                }
            }
        }
        return attendsVectors;
    }
};

int main(int argc, const char * argv[]) {
    //vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0, 0, 0, 0};
    Solution solution = Solution();
    vector<vector<int>> attendsVectors = solution.threeSum(nums);
    for (int i = 0; i < attendsVectors.size(); i++) {
        vector<int> attends = attendsVectors[i];
        for (int j = 0; j < attends.size(); j++) {
            cout << attends[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
