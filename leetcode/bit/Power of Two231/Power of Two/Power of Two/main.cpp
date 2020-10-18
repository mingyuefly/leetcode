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
        if ((n & (n - 1)) == 0) {
            return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    int input = 16;
    Solution solution = Solution();
    cout << solution.isPowerOfTwo(input) << endl;
    return 0;
}
