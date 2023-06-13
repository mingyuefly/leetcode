//
//  main.cpp
//  Unique_Binary_Search_Trees
//
/**
 Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
 
 
 
 Example 1:
 
 
 Input: n = 3
 Output: 5
 Example 2:
 
 Input: n = 1
 Output: 1
 
 
 Constraints:
 
 1 <= n <= 19
 */
//  Created by gmy on 2023/6/10.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    
public:
    int numTrees(int n) {
        vector<int> trees(n + 1, 0);
        trees[0] = 1;
        trees[1] = 1;
        for (int i = 2; i <= n ; i++) {
            for (int j = 1; j <= i; j++) {
                trees[i] += trees[j - 1] * trees[i - j];
            }
            
        }
        return trees[n];
    }
};

class Solution1 {
    
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};

int main(int argc, const char * argv[]) {
    
//    Solution solution;
    Solution1 solution;
    cout << solution.numTrees(1) << endl;
    cout << solution.numTrees(2) << endl;
    cout << solution.numTrees(3) << endl;
    cout << solution.numTrees(4) << endl;
    cout << solution.numTrees(5) << endl;
    cout << solution.numTrees(6) << endl;
    cout << solution.numTrees(7) << endl;
    cout << solution.numTrees(8) << endl;
    cout << solution.numTrees(9) << endl;
    cout << solution.numTrees(10) << endl;
    cout << solution.numTrees(11) << endl;
    cout << solution.numTrees(12) << endl;
    cout << solution.numTrees(13) << endl;
    cout << solution.numTrees(14) << endl;
    cout << solution.numTrees(15) << endl;
    cout << solution.numTrees(16) << endl;
    cout << solution.numTrees(17) << endl;
    cout << solution.numTrees(18) << endl;
    cout << solution.numTrees(19) << endl;
    
    return 0;
}
