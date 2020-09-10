//
//  main.cpp
//  Majority Element
//
//  Created by mingyue on 2020/9/10.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> myMap;
        int max = 0;
        int maxValue = 0;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            if (myMap.find(a) != myMap.end()) {
                int num = myMap[a];
                num++;
                myMap[a] = num;
                if (num > max) {
                    max = num;
                    maxValue = a;
                }
            } else {
                myMap[a] = 1;
                if (max == 0) {
                    maxValue = a;
                }
            }
        }
        return maxValue;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution = Solution();
    //vector<int> nums = {3, 2, 3};
    vector<int> nums = {2,2,1,1,1,2,2};
    int maxValue = solution.majorityElement(nums);
    cout << maxValue << endl;
    
    return 0;
}
