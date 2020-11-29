//
//  main.cpp
//  Climbing Stairs
//
//  Created by mingyue on 2020/11/29.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

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

int main(int argc, const char * argv[]) {
    
    Solution solution = Solution();
    int n = 3;
    int result = solution.climbStairs(n);
    cout << result << endl;
    
    return 0;
}
