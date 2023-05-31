//
//  main.cpp
//  125_Valid_Palindrome
//
/**
 A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

 Given a string s, return true if it is a palindrome, or false otherwise.

  

 Example 1:

 Input: s = "A man, a plan, a canal: Panama"
 Output: true
 Explanation: "amanaplanacanalpanama" is a palindrome.
 Example 2:

 Input: s = "race a car"
 Output: false
 Explanation: "raceacar" is not a palindrome.
 Example 3:

 Input: s = " "
 Output: true
 Explanation: s is an empty string "" after removing non-alphanumeric characters.
 Since an empty string reads the same forward and backward, it is a palindrome.
  

 Constraints:

 1 <= s.length <= 2 * 105
 s consists only of printable ASCII characters.
 */
//  Created by gmy on 2023/5/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // 去除其他字符，并将大写字母改为小写
        vector<char> tmpS;
        for (char c : s) {
            if ((c <= 57 && c >= 48) || (c <= 122 && c >= 97)) {
                tmpS.push_back(c);
            } else if (c <= 90 && c>= 65) {
                tmpS.push_back(c+=32);
            }
        }
        
        if (s.size() == 1) {
            return true;
        }
        
        // 反转
        vector<char> tmpS1;
        for (char c : tmpS) {
            tmpS1.insert(tmpS1.begin(), c);
        }
        
        // 比较
        if (tmpS == tmpS1) {
            return true;
        }
        
        return false;
    }
};

class Solution1 {
public:
    bool isPalindrome(string s) {
        // 去除其他字符，并将大写字母改为小写
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        // 反转
        string sgood_rev(sgood.rbegin(), sgood.rend());
        // 比较
        return sgood == sgood_rev;
    }
};

class Solution2 {
public:
    bool isPalindrome(string s) {
        // 去除其他字符，并将大写字母改为小写
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        
        // 左右双指针运动比较
        int n = (int)sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
            if (sgood[left] != sgood[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};

class Solution3 {
public:
    bool isPalindrome(string s) {
        // 原字符串左右双指针比较 
        int n = (int)s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            // 去除其他字符，并将大写字母改为小写
            while (left < right && !isalnum(s[left])) {
                ++left;
            }
            while (left < right && !isalnum(s[right])) {
                --right;
            }
            
            // 左右双指针运动比较
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
        
        
        
        //        int n = (int)s.size();
        //        int left = 0, right = n - 1;
        //        while (left < right) {
        //            if (!isalnum(s[left])) {
        //                left++;
        //                continue;;
        //            }
        //            if (!isalnum(s[right])) {
        //                right--;
        //                continue;
        //            }
        //            if ((tolower(s[left]) != (tolower(s[right])))) {
        //                return false;
        //            }
        //            left++;
        //            right--;
        //        }
        //
        //        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    
    Solution1 solution1;
    cout << solution1.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution1.isPalindrome("race a car") << endl;
    
    Solution2 solution2;
    cout << solution2.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution2.isPalindrome("race a car") << endl;
    
    Solution3 solution3;
    cout << solution3.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution3.isPalindrome("race a car") << endl;
    
    return 0;
}
