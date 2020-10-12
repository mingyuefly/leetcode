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
        if (n == 0) {
            return;
        }
        vector<int> sum;
        int im = 0, in = 0;
        for (int i = 0; i < m + n; i++) {
            if (im <= m - 1 && nums1[im] <= nums2[in]) {
                sum.push_back(nums1[im]);
                im++;
                continue;
            }
            if (in <= n - 1 && nums1[im] > nums2[in]) {
                sum.push_back(nums2[in]);
                in++;
                continue;
            }
            if (im >= m) {
                for (int j = in; j < n; j++) {
                    sum.push_back(nums2[j]);
                }
                break;
            }
            if (in >= n) {
                for (int j = im; j < m; j++) {
                    sum.push_back(nums1[j]);
                }
                break;
            }
        }
        for (int i = 0; i < m + n; i++) {
            nums1[i] = sum[i];
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
