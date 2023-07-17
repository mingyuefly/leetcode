//
//  main.cpp
//  Climbing Stairs
//
//  Created by mingyue on 2020/11/29.
/**
 You are climbing a staircase. It takes n steps to reach the top.
 
 Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 
 
 
 Example 1:
 
 Input: n = 2
 Output: 2
 Explanation: There are two ways to climb to the top.
 1. 1 step + 1 step
 2. 2 steps
 Example 2:
 
 Input: n = 3
 Output: 3
 Explanation: There are three ways to climb to the top.
 1. 1 step + 1 step + 1 step
 2. 1 step + 2 steps
 3. 2 steps + 1 step
 
 
 Constraints:
 
 1 <= n <= 45
 */
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// 普通递归 时间复杂度（O(2^n） 空间复杂度（O(n)）
class Solution1 {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return n;
        }
        
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// 递归优化，剪枝 时间复杂度（O(n） 空间复杂度（O(n)）
class Solution2 {
public:
    int climbStairs(int n) {
        vector<int> mem = vector<int>(n + 1, 0);
        mem[1] = 1;
        mem[2] = 2;
        
        return climbStairsFunc(n, mem);
    }
    
    int climbStairsFunc(int n, vector<int> & mem) {
        if (mem[n] > 0) {
            return mem[n];
        }
        if (n == 1) {
            mem[1] = 1;
        } else if (n == 2) {
            mem[2] = 2;
        } else {
            mem[n] = climbStairsFunc(n - 1, mem) + climbStairsFunc(n - 2, mem);
        }
        return mem[n];
    }
};

// 动态规划，记录每一步状态 时间复杂度（O(n） 空间复杂度（O(n)）
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2) {
            return n;
        }
        vector<int> mem(n + 1);
        mem[0] = 1;
        mem[1] = 2;
        for (int i = 2; i < n; i++) {
            mem[i] = mem[i - 1] + mem[i - 2];
        }
        return mem[n - 1];
    }
};

// 斐波那契数列，时间复杂度（O(n） 空间复杂度（O(1)）
class Solution3 {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        int first = 1, second = 2, third = 0;
        for (int i = 3; i <= n; i++) {
            third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

// 通项公式矩阵形式，时间复杂度（O(log(n)） 空间复杂度（O(1)），基本思路：通过矩阵构建一个递推关系，最终将其归为一个基础矩阵的n次幂，通过位运算将n次幂的求解的时间复杂度优化至O(log(n)。

class Solution4 {
public:
    int climbStairs(int n) {
        
        vector<vector<long>> m = {{0, 1}, {1, 1}};
        vector<vector<long>> res = pow(m, n);
        
        return res.at(1).at(1);
    }
    
    vector<vector<long>> pow(vector<vector<long>> a, long n) {
        vector<vector<long>> res = {{1, 0}, {0, 1}};
        while (n > 0) {
            if ((n & 1) == 1) {
                res = multiply(res, a);
            }
            n >>= 1;
            a = multiply(a, a);
        }
        return res;
    }
    
    vector<vector<long>> multiply(vector<vector<long>> & a, vector<vector<long>> & b) {
        vector<vector<long>> c = {{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        
        
        return c;
    }
};

// Benet's Formula，时间复杂度（O(log(n)） 空间复杂度（O(1)），基本思路：直接获取其通项公式。
class Solution5 {
public:
    int climbStairs(int n) {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return (int)round(fibn / sqrt5);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    Solution1 solution1;
    Solution2 solution2;
    Solution3 solution3;
    Solution4 solution4;
    Solution5 solution5;
    
    int n = 35;
    int result = solution.climbStairs(n);
    cout << result << endl;
    int result1 = solution1.climbStairs(n);
    cout << result1 << endl;
    int result2 = solution2.climbStairs(n);
    cout << result2 << endl;
    int result3 = solution3.climbStairs(n);
    cout << result3 << endl;
    int result4 = solution4.climbStairs(n);
    cout << result4 << endl;
    int result5 = solution5.climbStairs(n);
    cout << result5 << endl;
    
    
    return 0;
}
