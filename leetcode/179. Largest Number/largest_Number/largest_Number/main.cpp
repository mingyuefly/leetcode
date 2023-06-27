//
//  main.cpp
//  largest_Number
//
/**
 Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
 
 Since the result may be very large, so you need to return a string instead of an integer.
 
 
 
 Example 1:
 
 Input: nums = [10,2]
 Output: "210"
 Example 2:
 
 Input: nums = [3,30,34,5,9]
 Output: "9534330"
 
 
 Constraints:
 
 1 <= nums.length <= 100
 0 <= nums[i] <= 109
 */
//  Created by gmy on 2023/6/27.
//

#include <iostream>
#include <sstream>
#include <string>


using namespace std;

//AddressSanitizer: heap-buffer-overflow
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        mySort(nums);
        return numsToString(nums);
    }
    string numsToString(vector<int>& nums) {
        string tmpStr = "";
        for(int num : nums) {
            string a = to_string(num);
            tmpStr.append(a);
        }
        return tmpStr;
        
        //        string tmpStr = "";
        //        for(int num : nums) {
        //            stringstream ss;
        //            ss << num;
        //            string s1 = ss.str();
        //            tmpStr.append(s1);
        //        }
        //        return tmpStr;
    }
    void mySort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
    }
    /* 所有在类内定义的非static成员函数在经过编译后隐式的为他们添加了一个this指针参数！而标准库的sort()函数的第三个cmp函数指针参数中并没有这样this指针参数，因此会出现输入的cmp参数和sort()要求的参数不匹配，从而导致了：error: reference to non-static member function must be called，而static静态类成员函数是不需要this指针的。
     */
    static bool compare(int num1, int num2) {
        vector<int> num1Digitals, num2Digitals;
        while (num1 > 0) {
            num1Digitals.insert(num1Digitals.begin(), num1 % 10);
            num1 /= 10;
        }
        while (num2 > 0) {
            num2Digitals.insert(num2Digitals.begin(), num2 % 10);
            num2 /= 10;
        }
        long size1 = (int)num1Digitals.size();
        long size2 = (int)num2Digitals.size();
        long difference = size1 - size2;
        // 短的数字后边补上最后一位数字
        if (difference > 0) {
            while (difference > 0) {
                num2Digitals.push_back(num2Digitals[size2 - 1]);
                difference--;
            }
        } else if (difference < 0) {
            difference = abs(difference);
            while (difference > 0) {
                num1Digitals.push_back(num1Digitals[size2 - 1]);
                difference--;
            }
        } else {
            //
        }
        long size = (int)num1Digitals.size();
        for (long i = 0; i < size; i++) {
            if (num1Digitals[i] > num2Digitals[i]) {
                return true;
            } else if (num1Digitals[i] < num2Digitals[i]) {
                return false;
            } else {
                
            }
        }
        return true;
    }
};

// long overflow
class Solution1 {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) {
            return "0";
        }
        string tmpStr = "";
        for(int num : nums) {
            string a = to_string(num);
            tmpStr.append(a);
        }
        return tmpStr;
    }
    static bool compare(int x, int y) {
        long sx = 10, sy = 10;
        while (sx <= x) {
            sx *= 10;
        }
        while (sy <= y) {
            sy *= 10;
        }
        // 比较拼接后的两个数字
        return sy * x + y > sx * y + x;
    }
};

class Solution2 {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto i : nums) {
            str.push_back(to_string(i));
        }
        // 使用 lambda 比较 elements.
        auto cmp = [](string left, string right) {
            // 比较字符串大小
            return left + right > right + left;
        };
        sort(str.begin(),str.end(), cmp);
        stringstream ss;
        for(auto c : str) {
            ss << c;
        }
        string ans = ss.str();
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {
//    Solution s;
//    vector<int> nums = {3,30,34,5,9};
//    //    vector<int> nums = {10,2};
//    cout << s.largestNumber(nums) << endl;
    
    Solution1 s1;
//    vector<int> nums = {3,30,34,5,9};
    vector<int> nums = {431,43,34,5,9};
    //    vector<int> nums = {10,2};
    cout << s1.largestNumber(nums) << endl;
    
//    Solution2 s2;
//    vector<int> nums = {3,30,34,5,9};
//    //    vector<int> nums = {10,2};
//    cout << s2.largestNumber(nums) << endl;
    
    return 0;
}
