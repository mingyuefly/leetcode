//
//  main.cpp
//  pow
//
//  Created by mingyue on 2020/9/8.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        unsigned int m = (unsigned int)n;//处理溢出问题
        if (n < 0) {
            x = 1 / x;
            m = -m;
        }
        if (m % 2 == 0) {
            return myPow(x * x, m / 2);
        } else {
            return myPow(x * x, (m - 1) / 2) * x;
        }
    }
};

class Solution1 {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        unsigned int m = (unsigned int)n;//处理溢出问题
        if (n < 0) {
            x = 1 / x;
            m = -m;
        }
        double pow = 1;
        while (m) {
            if (m & 1) { // 相当于对2取余计算结果非0
                // 这一步很巧妙，当m为偶数时不用管pow，当m为奇数时将pow *= x，即便之前都是偶数，最后一步m为1时也会将结果赋值给pow
                pow *= x;
            }
            x *= x;
            m >>= 1; // 相当于除以2
        }
        return pow;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    Solution1 solution1 = Solution1();
    //double x = 2.0, n = 10;
    double x = 2.0, n = -2;
    double powResult = solution.myPow(x, n);
    cout << powResult << endl;
    cout << solution1.myPow(2, 10) << endl;
    cout << solution1.myPow(2, 8) << endl;
    return 0;
}
