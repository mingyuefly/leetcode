//
//  main.cpp
//  647_Palindromic_Substrings_cpp
//
/**
 Given a string s, return the number of palindromic substrings in it.
 
 A string is a palindrome when it reads the same backward as forward.
 
 A substring is a contiguous sequence of characters within the string.
 
 
 
 Example 1:
 
 Input: s = "abc"
 Output: 3
 Explanation: Three palindromic strings: "a", "b", "c".
 Example 2:
 
 Input: s = "aaa"
 Output: 6
 Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
 
 Constraints:
 
 1 <= s.length <= 1000
 s consists of lowercase English letters.
 */
//  Created by gmy on 2023/5/30.
//



#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        
        int left = 0;
        int right = (int)s.size();
        int count = 0;
        // 枚举所有子串
        for (left = 0; left < right; left++) {
            for(int i = left; i < right; i++) {
                string s1 = s.substr(left, i - left + 1);
                // 判断子串是否为回文
                if (isPalindrome(s1)) {
                    count++;
                }
            }
        }
        
        return count;
    }
    
    bool isPalindrome(string s) {
        int n = (int)s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
};

//枚举每一个可能的回文中心，然后用两个指针分别向左右两边拓展，当两个指针指向的元素相同的时候就拓展，否则停止拓展。
class Solution1 {
public:
    int countSubstrings(string s) {
        int n = (int)s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;//判断i是奇数还是偶数
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};

// Manacher 算法
class Solution2 {
public:
    int countSubstrings(string s) {
        int n = (int)s.size();
        string t = "$#";
        for (const char &c: s) {
            t += c;
            t += '#';
        }
        n = (int)t.size();
        t += '!';
        
        auto f = vector <int> (n);
        int iMax = 0, rMax = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            // 初始化 f[i]
            f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - i]) : 1;
            // 中心拓展
            while (t[i + f[i]] == t[i - f[i]]) ++f[i];
            // 动态维护 iMax 和 rMax
            if (i + f[i] - 1 > rMax) {
                iMax = i;
                rMax = i + f[i] - 1;
            }
            // 统计答案, 当前贡献为 (f[i] - 1) / 2 上取整
            ans += (f[i] / 2);
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.countSubstrings("abc") << endl;
    cout << solution.countSubstrings("aaa") << endl;
    
    Solution1 solution1;
    cout << solution1.countSubstrings("abc") << endl;
    cout << solution1.countSubstrings("aaa") << endl;
    
    Solution2 solution2;
    cout << solution2.countSubstrings("abc") << endl;
    cout << solution2.countSubstrings("aaa") << endl;
    
    return 0;
}
