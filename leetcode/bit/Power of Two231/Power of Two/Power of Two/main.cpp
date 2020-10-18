//
//  main.cpp
//  Power of Two
//
//  Created by mingyue on 2020/10/18.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        int count = 0;
        while (n) {
            count++;
            n = n & (n - 1);
        }
        return count == 1;
    }
};

int main(int argc, const char * argv[]) {
    int input = 12;
    Solution solution = Solution();
    cout << solution.isPowerOfTwo(input) << endl;
    return 0;
}
