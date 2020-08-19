//
//  main.cpp
//  two sum
//
//  Created by mingyue on 2020/8/19.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (dic.count(target - nums[i])) {
                indices.push_back(i);
                indices.push_back(dic[target - nums[i]]);
                return indices;
            } else {
                dic[nums[i]] = i;
            }
        }
        return indices;
    }
};

int main(int argc, const char * argv[]) {
    
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution = Solution();
    vector<int> result = solution.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
