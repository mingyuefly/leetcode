//
//  main.cpp
//  Sqrt(x)
//
/**
 Implement int sqrt(int x).

 Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

 Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

 Example 1:

 Input: 4
 Output: 2
 Example 2:

 Input: 8
 Output: 2
 Explanation: The square root of 8 is 2.82842..., and since
              the decimal part is truncated, 2 is returned.
 */
//  Created by mingyue on 2020/10/8.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 0, right = x;
        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid - 1;
            } else if (mid < x / mid) {
                left = mid + 1;
                result = mid;
            } else {
                return mid;
            }
        }
        return result;
    }
};

class Solution1 {
public:
    double mySqrt(int x, int accuracy) {
        if (x == 0 || x == 1) {
            return x;
        }
        double left = 0;
        double right = x;
        //double result = 0.0;
        while (left <= right) {
            double mid = left + (right - left) / 2;
            if (mid > x / mid) {
                right = mid;
            } else if (mid < x / mid) {
                left = mid;
            } else {
                return mid;
            }
            if (abs(left - right) < pow(10, -accuracy)) {
                return left;
            }
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    int input = 8;
    cout << solution.mySqrt(input) << endl;
    Solution1 solution1 = Solution1();
    cout << solution1.mySqrt(input, 8) << endl;
    cout << sqrt(input) << endl;
    return 0;
}
