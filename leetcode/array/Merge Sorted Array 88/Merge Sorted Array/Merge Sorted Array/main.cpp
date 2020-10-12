//
//  main.cpp
//  Merge Sorted Array
//
//  Created by mingyue on 2020/10/13.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iA = m-1;
        int iB = n-1;
        int iNew = m+n-1;
        
        // Fill in the longer vector when both A and B
        while (iA >= 0 && iB >= 0)
        {
            nums1[iA] > nums2[iB] ? nums1[iNew--] = nums1[iA--] : nums1[iNew--] = nums2[iB--];
        }
        
        // Fill in the rest with either A or B leftover
        
        while (iA >= 0)
        {
            nums1[iNew--] = nums1[iA--];
        }
        
        while (iB >= 0 )
        {
            nums1[iNew--] = nums2[iB--];
        }
    }
};

int main(int argc, const char * argv[]) {
    /*
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
     */
    vector<int> nums1 = {2, 0};
    int m = 1;
    vector<int> nums2 = {1};
    int n = 1;
    Solution solution = Solution();
    solution.merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
