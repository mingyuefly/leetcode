//
//  main.cpp
//  reverseStringTwo
//
/** 541
 Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

 If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

  

 Example 1:

 Input: s = "abcdefg", k = 2
 Output: "bacdfeg"
 Example 2:

 Input: s = "abcd", k = 2
 Output: "bacd"
  

 Constraints:

 1 <= s.length <= 104
 s consists of only lowercase English letters.
 1 <= k <= 104
 */
//  Created by gmy on 2023/5/27.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        
        string s2 = s;
        int size = int(s.size());
        int step = size / (2 * k);
        int r = size % (2 * k);
        if (r == 0) {
            for (int i = 0; i < step; i++) {
                reverseStrFunc(s, s2, i * 2 * k, (i * 2 + 1) * k - 1);
            }
        } else if (r <= k) {
            int i;
            for (i = 0; i < step; i++) {
                reverseStrFunc(s, s2, i * 2 * k, (i * 2 + 1) * k - 1);
            }
            reverseStrFunc(s, s2, i * 2 * k, size - 1);
        } else {
            int i = 0;
            for (i = 0; i < step; i++) {
                reverseStrFunc(s, s2, i * 2 * k, (i * 2 + 1) * k - 1);
            }
            reverseStrFunc(s, s2, i * 2 * k, (i * 2 + 1) * k - 1);
        }
        
        
        return s2;
    }
    
    string reverseStrFunc(string & s, string & s2, int start, int end) {
        int i = start, j = end;
        while (i <= end && j >= start) {
            s2.at(j) = s.at(i);
            i++;
            j--;
        }
        return s2;
    }
};

//class Solution1 {
//public:
//    string reverseStr(string s, int k) {
//        int size = int(s.size());
//        int step = size / (2 * k);
//        int r = size % (2 * k);
//        if (r == 0) {
//            for (int i = 0; i < step; i++) {
//                reverseStrFunc(s, i * 2 * k, (i * 2 + 1) * k - 1);
//            }
//        } else if (r <= k) {
//            int i;
//            for (i = 0; i < step; i++) {
//                reverseStrFunc(s, i * 2 * k, (i * 2 + 1) * k - 1);
//            }
//            reverseStrFunc(s, i * 2 * k, size - 1);
//        } else {
//            int i = 0;
//            for (i = 0; i < step; i++) {
//                reverseStrFunc(s, i * 2 * k, (i * 2 + 1) * k - 1);
//            }
//            reverseStrFunc(s, i * 2 * k, (i * 2 + 1) * k - 1);
//        }
//        return s;
//    }
//
//    void reverseStrFunc(string & s, int start, int end) {
//        int i = start, j = end;
//        int tmp;
//        while (i <= end && j >= start) {
//            tmp = s.at(i);
//            s.at(i) = s.at(j);
//            s.at(j) = tmp;
//            i++;
//            j--;
//        }
//    }
//};

int main(int argc, const char * argv[]) {
    
    Solution solution;

    string s = "abcdefghijklmnopqrstuvwxyz";
    cout << s << endl;
    cout << solution.reverseStr(s, 2) << endl;
    cout << s << endl;
    cout << solution.reverseStr(s, 3) << endl;

    string s1 = "abcdef";
    cout << s1 << endl;
    cout << solution.reverseStr(s1, 2) << endl;

    string s2 = "abcdefgh";
    cout << s2 << endl;
    cout << solution.reverseStr(s2, 3) << endl;

    string s3 = "abcdefg";
    cout << s3 << endl;
    cout << solution.reverseStr(s3, 2) << endl;

    string s4 = "abcd";
    cout << s4 << endl;
    cout << solution.reverseStr(s4, 2) << endl;
    
//    Solution1 solution1;
//    
//    string s = "abcdefghijklmnopqrstuvwxyz";
//    cout << s << endl;
//    cout << solution1.reverseStr(s, 2) << endl;
//    cout << s << endl;
//    cout << solution1.reverseStr(s, 3) << endl;
//    
//    string s1 = "abcdef";
//    cout << s1 << endl;
//    cout << solution1.reverseStr(s1, 2) << endl;
//    
//    string s2 = "abcdefgh";
//    cout << s2 << endl;
//    cout << solution1.reverseStr(s2, 3) << endl;
//    
//    string s3 = "abcdefg";
//    cout << s3 << endl;
//    cout << solution1.reverseStr(s3, 2) << endl;
//    
//    string s4 = "abcd";
//    cout << s4 << endl;
//    cout << solution1.reverseStr(s4, 2) << endl;
//    
    return 0;
}
