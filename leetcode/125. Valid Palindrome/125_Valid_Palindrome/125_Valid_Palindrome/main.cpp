//
//  main.cpp
//  125_Valid_Palindrome
//
//  Created by gmy on 2023/5/30.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
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
        
        vector<char> tmpS1;
        for (char c : tmpS) {
            tmpS1.insert(tmpS1.begin(), c);
        }
        
        if (tmpS == tmpS1) {
            return true;
        }
        
        return false;
    }
};

class Solution1 {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};

class Solution2 {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        
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
