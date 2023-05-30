//
//  main.cpp
//  Palindrome_Number_cpp
//
//  Created by gmy on 2023/5/30.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x >= 0 && x <= 9) {
            return true;
        }
        if (x < 0 || (x % 10 == 0)) {
            return false;
        }
        int tmpX = x;
        int tmpY = 0;
        while (true) {
            if (tmpY >= tmpX) {
                break;
            }
            int a = tmpX % 10;
            tmpY = tmpY * 10 + a;
            if (tmpY >= tmpX) {
                break;
            }
            tmpX /= 10;
        }
        if (tmpX == tmpY) {
            return true;
        }
        return false;
    }
};

class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x >= 0 && x <= 9) {
            return true;
        }
        if (x < 0 || (x % 10 == 0)) {
            return false;
        }
        int revertedNum = 0;
        while (x > revertedNum) {
            revertedNum = revertedNum * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNum || x == revertedNum / 10;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isPalindrome(121) << endl;
    cout << solution.isPalindrome(231) << endl;
    cout << solution.isPalindrome(12321) << endl;
    cout << solution.isPalindrome(123321) << endl;
    cout << solution.isPalindrome(10) << endl;
    
    Solution1 solution1;
    cout << solution1.isPalindrome(121) << endl;
    cout << solution1.isPalindrome(231) << endl;
    cout << solution1.isPalindrome(12321) << endl;
    cout << solution1.isPalindrome(123321) << endl;
    cout << solution1.isPalindrome(10) << endl;
    
    return 0;
}
