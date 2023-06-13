//
//  main.cpp
//  coin_Change_II
//
/**
 You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

 Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

 You may assume that you have an infinite number of each kind of coin.

 The answer is guaranteed to fit into a signed 32-bit integer.

  

 Example 1:

 Input: amount = 5, coins = [1,2,5]
 Output: 4
 Explanation: there are four ways to make up the amount:
 5=5
 5=2+2+1
 5=2+1+1+1
 5=1+1+1+1+1
 Example 2:

 Input: amount = 3, coins = [2]
 Output: 0
 Explanation: the amount of 3 cannot be made up just with coins of 2.
 Example 3:

 Input: amount = 10, coins = [10]
 Output: 1
  

 Constraints:

 1 <= coins.length <= 300
 1 <= coins[i] <= 5000
 All the values of coins are unique.
 0 <= amount <= 5000
 */
//  Created by gmy on 2023/6/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0) {
            return 1;
        }
        if (coins.empty()) {
            return 0;
        }
        vector<int> sum(amount + 1);
        sum[0] = 1;
        for (int j = 0; j < coins.size(); j++) {
            for (int i = 1; i <= amount; i++) {
                if (coins[j] <= i) {
                    sum[i] += sum[i - coins[j]];
                }
            }
        }
        
        return sum[amount];
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int> coins = {1,2,5};
    int amount = 11;
    
    Solution solution;
    cout << solution.change(amount, coins) << endl;
    
    return 0;
}
