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
            if (m & 1) {
                pow *= x;
            }
            x *= x;
            m >>= 1;
        }
        return pow;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    Solution1 solution1 = Solution1();
    //double x = 2.0, n = 10;
    double x = 2.0, n = -2;
    double powResult = solution1.myPow(x, n);
    cout << powResult << endl;
    cout << solution.myPow(2, 10) << endl;
    
    return 0;
}
