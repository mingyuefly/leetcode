//
//  main.cpp
//  FindFirstAndLastElementInSortedArray
//
//  Created by mingyue on 2022/2/7.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        if (nums.size() == 0) {
            return result;
        }
        int first = searchFirstElement(nums, target);
        int last = searchLastElement(nums, target);
        result[0] = first;
        result[1] = last;
        return result;
    }
    
private:
    int searchFirstElement(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int low = 0;
        int high = int(nums.size()) - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 2);
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if (mid == 0 || nums[mid - 1] != target) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
    
    int searchLastElement(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        int low = 0;
        int high = int(nums.size()) - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 2);
            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                if (mid == (int(nums.size()) - 1) || nums[mid + 1] != target) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
//    vector<int> nums = {5,7,7,8,8,10};
//    int target = 8;
    
//    vector<int> nums = {5,7,7,8,8,10};
//    int target = 6;
    
    vector<int> nums = {};
    int target = 0;
    Solution solution = Solution();
    vector<int> result = solution.searchRange(nums, target);
    size_t count = result.size();
    for (int i = 0; i < count; i++) {
        cout << result.at(i) << ' ';
    }
    cout << endl;
    return 0;
}
