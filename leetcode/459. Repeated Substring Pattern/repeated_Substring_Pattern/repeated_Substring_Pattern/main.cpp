//
//  main.cpp
//  repeated_Substring_Pattern
//
/**
 Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

  

 Example 1:

 Input: s = "abab"
 Output: true
 Explanation: It is the substring "ab" twice.
 Example 2:

 Input: s = "aba"
 Output: false
 Example 3:

 Input: s = "abcabcabcabc"
 Output: true
 Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
  

 Constraints:

 1 <= s.length <= 104
 s consists of lowercase English letters.
 */
//  Created by gmy on 2023/8/4.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        size_t length = s.length();
        for (int i = 1; 2 * i <= length; i++) {
            if (length % i == 0) {
                bool match = true;
                for (int j = i; j < length; j++) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
//                for (int j = 0; j < length - i; j += i) {
//                    if (s.substr(j, i) != s.substr(j + i, i)) {
//                        match = false;
//                        break;
//                    }
//                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution1 {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) != s.size();
    }
};


int main(int argc, const char * argv[]) {
    string s1 = "abab";
    string s2 = "aba";
    string s3 = "abcabcabcabc";
//    Solution s = Solution();
    Solution1 s = Solution1();
    cout << s.repeatedSubstringPattern(s1) << endl;
    cout << s.repeatedSubstringPattern(s2) << endl;
    cout << s.repeatedSubstringPattern(s3) << endl;
    return 0;
}
