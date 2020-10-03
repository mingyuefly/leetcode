//
//  main.cpp
//  N-Queens II
//
/**
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



 Given an integer n, return the number of distinct solutions to the n-queens puzzle.

 Example:

 Input: 4
 Output: 2
 Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
 [
  [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],

  ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
 ]
 */
//  Created by mingyue on 2020/10/3.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0) {
            return 0;
        }
        
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
