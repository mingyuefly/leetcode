//
//  main.cpp
//  longest_Common_Prefix_cpp
//
/**
 Write a function to find the longest common prefix string amongst an array of strings.

 If there is no common prefix, return an empty string "".

  

 Example 1:

 Input: strs = ["flower","flow","flight"]
 Output: "fl"
 Example 2:

 Input: strs = ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
  

 Constraints:

 1 <= strs.length <= 200
 0 <= strs[i].length <= 200
 strs[i] consists of only lowercase English letters.
 */
//  Created by gmy on 2023/7/18.
//

#include <iostream>

using namespace std;

//纵向扫描， 基本思路：先取所有字符串中最短字符串的长度，再依次从前到后对比，如果全部相等加入到公共子串中，如果有不相等则中断。事件复杂度（O(m * n)）(m为最短字符串长度，n为数组长度），空间复杂度（O(0)）。
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {
            return strs[0];
        }
        int min = (int)strs[0].length();
        for(string& str: strs) {
            if (str.length() < min) {
                min = (int)str.length();
            }
        }
        string commonString = "";
        for(int i = 0; i < min; i++) {
            char first = strs[0][i];
            bool quit = false;
            for(string& str: strs) {
                if (str[i] != first) {
                    quit = true;
                    break;
                }
            }
            if (quit) {
                break;
            }
            commonString += first;
        }
        
        return commonString;
    }
};

// 横向扫描，基本思路：遍历数组，依次获取相邻两个字符串的最大公共子串，并不断更新，当最新子串为空时中断。事件复杂度（O(m * n)）(m为最短字符串长度，n为数组长度），空间复杂度（O(0)）。
class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return strs[0];
        }
        string prefix = strs[0];
        int count = (int)strs.size();
        for(int i = 1; i < count; i++) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if (prefix.empty()) {
                break;
            }
        }
        return prefix;
    }
    string longestCommonPrefix(const string& str1, const string& str2) {
        int minLength = (int)min(str1.length(), str2.length());
        int index = 0;
        while (index < minLength && str1[index] == str2[index]) {
            ++index;
        }
        return str1.substr(0, index);
    }
};

// 还可使用分治法、二分查找等，但并不能有效降低时间复杂度和空间复杂度。

int main(int argc, const char * argv[]) {
//    Solution s;
    Solution1 s;
    vector<string> strs = {"flower","flow","flight"};
    vector<string> strs1 = {"dog","racecar","car"};
    cout << s.longestCommonPrefix(strs) << endl;
    cout << s.longestCommonPrefix(strs1) << endl;
    return 0;
}
