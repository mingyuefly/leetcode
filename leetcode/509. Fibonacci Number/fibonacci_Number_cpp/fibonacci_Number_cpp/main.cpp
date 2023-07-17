//
//  main.cpp
//  fibonacci_Number_cpp
//
/**
 The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

 F(0) = 0, F(1) = 1
 F(n) = F(n - 1) + F(n - 2), for n > 1.
 Given n, calculate F(n).

 Example 1:

 Input: n = 2
 Output: 1
 Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
 Example 2:

 Input: n = 3
 Output: 2
 Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
 Example 3:

 Input: n = 4
 Output: 3
 Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
  

 Constraints:

 0 <= n <= 30
 */
//  Created by gmy on 2023/7/17.
//

#include <iostream>

using namespace std;

// recursion
class Solution {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        if (n == 2) {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

// recursion pruning // heap-buffer-overflow
class Solution3 {
public:
    int fib(int n) {
        vector<int> fibs = vector<int>(n + 1);
        fibs[0] = 0;
        fibs[1] = 1;
        fibs[2] = 1;
        return fib1(n, fibs);
    }
    
    int fib1(int n, vector<int> &fibs) {
        if (fibs[n] != 0) {
            return fibs[n];
        }
        return fib1(n - 1, fibs) + fib1(n - 2, fibs);
    }
};

// 尾递归优化，在函数返回的时候，调用自身本身，并且 return 语句不能包含表达式。这样，编译器或者解释器就可以把尾递归做优化，使递归本身无论调用多少次，都只占用一个栈帧，不会出现栈溢出的情况。 尾递归调用时，如果做了优化，栈不会增长，因此，无论多少次调用也不会导致栈溢出。在此题中还可以通过c剪枝。
class Solution4 {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        if (n == 2) {
            return 1;
        }
        return fib1(n);
    }
    int fib1(int n, int b1 = 1, int b2 = 1, int c = 3) {
        if (n < 3) {
            return 1;
        } else {
            if (n == c) {
                return b1 + b2;
            } else {
                return fib1(n, b2, b1 + b2, c + 1);
            }
        }
    }
};

// loop
class Solution1 {
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        if (n == 2) {
            return 1;
        }
        int a = 1, b = 1, c = 0;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// dynamic programing  // heap-buffer-overflow
class Solution2 {
public:
    int fib(int n) {
        vector<int> fibs = vector<int>(n + 1);
        fibs[0] = 0;
        fibs[1] = 1;
        fibs[2] = 1;
        for (int i = 3; i <= n; i++) {
            fibs[i] = fibs[i - 1] + fibs[i - 2];
        }
        return fibs[n];
    }
};

// 其他解法类似于70题的矩阵求解，时间复杂度（O(log(n)） 空间复杂度（O(1)）

int main(int argc, const char * argv[]) {
//    Solution s;
//    Solution1 s;
//    Solution2 s;
//    Solution3 s;
    Solution4 s;
    cout << s.fib(1) << endl;
    cout << s.fib(2) << endl;
    cout << s.fib(3) << endl;
    cout << s.fib(4) << endl;
    return 0;
}
