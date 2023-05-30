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

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << solution.isPalindrome("race a car") << endl;
    return 0;
}
