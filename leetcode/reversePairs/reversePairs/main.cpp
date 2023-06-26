//
//  main.cpp
//  reversePairs
//
/**
 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

  

 示例 1:

 输入: [7,5,6,4]
 输出: 5
  

 限制：

 0 <= 数组长度 <= 50000
 */
//  Created by gmy on 2023/6/26.
//

#include <iostream>

using namespace std;

// timeout
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int size = (int)nums.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (nums[i] > nums[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

//
class Solution1 {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        int size = (int)nums.size();
        if (size < 2) {
            return 0;
        }
        vector<int> tmpNums(size);
        count = sort(nums, tmpNums, 0, size - 1);
        return count;
    }
    
    int sort(vector<int>& nums, vector<int>& tmpNums, int lo, int h1) {
        if (h1 <= lo) {
            return 0;
        }
        int mid = lo + (h1 - lo) / 2;
        int left = sort(nums, tmpNums, lo, mid);
        int right = sort(nums, tmpNums, mid + 1, h1);
        // 加上下边优化后不再timeout，但仍需优化
        if (nums[mid] <= nums[mid + 1]) {
            return left + right;
        }
        int mergeCount = merge(nums, tmpNums, lo, mid, h1);
        return left + right + mergeCount;
    }
    
    int merge(vector<int>& nums, vector<int>& tmpNums, int lo, int mid, int h1) {
        tmpNums = nums;
        int i = lo, j = mid + 1, count = 0;
        for (int k = lo; k <= h1; k++) {
            if (i > mid) {
                nums[k] = tmpNums[j++];
            } else if (j > h1) {
                nums[k] = tmpNums[i++];
            } else if (tmpNums[i] <= tmpNums[j]) {
                nums[k] = tmpNums[i++];
            } else {
                nums[k] = tmpNums[j++];
                count = count + mid - i + 1;
            }
        }
        return count;
    }
};

// 
class Solution2 {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int inv_count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[pos] = nums[i];
                ++i;
                inv_count += (j - (mid + 1));
            }
            else {
                tmp[pos] = nums[j];
                ++j;
            }
            ++pos;
        }
        for (int k = i; k <= mid; ++k) {
            tmp[pos++] = nums[k];
            inv_count += (j - (mid + 1));
        }
        for (int k = j; k <= r; ++k) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return inv_count;
    }

    int reversePairs(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};


int main(int argc, const char * argv[]) {
    
//    Solution s;
//    vector<int> nums = {7,5,6,4};
//    cout << s.reversePairs(nums) << endl;
    
    Solution1 s1;
    vector<int> nums = {7,5,6,4};
//    vector<int> nums = {7,5,6,4,1,12,15,16,9,8};
    cout << s1.reversePairs(nums) << endl;
    
//    Solution2 s2;
//    vector<int> nums = {7,5,6,4};
////    vector<int> nums = {7,5,6,4,1,12,15,16,9,8};
//    cout << s2.reversePairs(nums) << endl;
    
    return 0;
}
