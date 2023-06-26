//
//  main.cpp
//  singleNumbers
//
/**
 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

  

 示例 1：

 输入：nums = [4,1,4,6]
 输出：[1,6] 或 [6,1]
 示例 2：

 输入：nums = [1,2,10,4,1,4,3,3]
 输出：[2,10] 或 [10,2]
  

 限制：

 2 <= nums.length <= 10000
  
 */

/**
 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

  

 示例 1：

 输入：nums = [3,4,3,3]
 输出：4
 示例 2：

 输入：nums = [9,1,7,9,7,9,7]
 输出：1
  

 限制：

 1 <= nums.length <= 10000
 1 <= nums[i] < 2^31
  
 */

//  Created by gmy on 2023/6/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> singles;
        
        // a和b异或结果
        int x = 0;
        for(int a : nums) {
            x ^= a;
        }
        
        // 找到二进制中a和b不同的位
        int div = 1;
        // 找到最右边不同的位
        while ((div & x) == 0) {
            div <<= 1;
        }
        // 使用左边不同的位也可
//        int div = 8;
        // 重要的是把a和b分开(以上一步a和b不同的位进行划分)
        int a = 0, b = 0;
        for(int n : nums) {
            if (n & div) {
                a ^= n;
            } else {
                b ^= n;
            }
        }
        singles.push_back(a);
        singles.push_back(b);
        return singles;
    }
};

class Solution2 {
public:
    int singleNumbers(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int num : nums) {
            ones = ones ^ (num & ~twos);
            twos = twos ^ (num & ~ones);
        }
        return ones;
    }
    int singleNumbers1(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> sums(32, 0);
        for(int num : nums) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < 32; j++) {
                    sums[j] += nums[i] & 1;// 更新第 j 位
                    nums[i] >>= 1; // 右移一位
                }
            }
        }
        
        int res = 0, m = 3;
        for (int i = 0; i < 32; i++) {
            res <<= 1;
            res |= sums[31 - i] % m;
        }
        
        return res;
    }
    int singleNumbers2(vector<int>& nums) {
        int size = (int)nums.size();
        vector<int> sums(32, 0);
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            int tmpIndex = 31;
            while (num > 0) {
                if (num % 2 == 1) {
                    sums[tmpIndex]++;
                }
                tmpIndex--;
                num /= 2;
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++) {
            sums[i] %= 3;
            if (sums[i] == 1) {
                res += (1 << (32 - i - 1));
            }
        }
        
        return res;
    }
    int singleNumbers3(vector<int>& nums) {
        int size = (int)nums.size();
        vector<vector<int>> numsCounts(size, vector<int>(32, 0));
        for (int i = 0; i < size; i++) {
            int num = nums[i];
            int tmpIndex = 31;
            while (num > 0) {
                numsCounts[i][tmpIndex--] = num % 2;
                num /= 2;
            }
        }
        vector<int> sums(32, 0);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 32; j++) {
                if (numsCounts[i][j] == 1) {
                    sums[j]++;
                }
            }
        }
        for (int i = 0; i < 32; i++) {
            sums[i] %= 3;
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (sums[i] == 1) {
                int a = 1 << (32 - i - 1);
                res += a;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
//    Solution s;
////    vector<int> nums = {4, 1, 4, 6};
//    vector<int> nums = {1, 6, 10, 4, 1, 4, 3, 3};
//    vector<int> singles = s.singleNumbers(nums);
//    cout << singles[0] << endl;
//    cout << singles[1] << endl;
    
    
    Solution2 s2;
    vector<int> nums = {3,4,3,3};
//    vector<int> nums = {9,1,7,9,7,9,7};
    cout << s2.singleNumbers(nums) << endl;
    
    
    return 0;
}
