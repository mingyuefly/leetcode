//
//  main.cpp
//  Best Time to Buy and Sell Stock III
//
/**
 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most two transactions.

 Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

  

 Example 1:

 Input: prices = [3,3,5,0,0,3,1,4]
 Output: 6
 Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
 Example 2:

 Input: prices = [1,2,3,4,5]
 Output: 4
 Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
 Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
 Example 3:

 Input: prices = [7,6,4,3,1]
 Output: 0
 Explanation: In this case, no transaction is done, i.e. max profit = 0.
 Example 4:

 Input: prices = [1]
 Output: 0
  

 Constraints:

 1 <= prices.length <= 100000
 0 <= prices[i] <= 100000
 */
//  Created by mingyue on 2021/2/16.
//  Copyright © 2021 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int days = prices.size();
        int K = 2;
        vector<vector<vector<int>>> profit;
        profit.resize(days);
        for (int i = 0; i < days; i++) {
            profit[i].resize(K + 1);
            for (int k = 0; k < K + 1; k++) {
                profit[i][k].resize(2);
                for (int j = 0; j < 2; j++) {
                    profit[i][k][j] = 0;
                }
            }
        }
        
        profit[0][0][0] = 0;
        profit[0][0][1] = 0 - prices[0];
        profit[0][1][0] = -100001;//最大股票价格
        profit[0][1][1] = -100001;
        profit[0][2][0] = -100001;
        profit[0][2][1] = -100001;
        
        for (int i = 1; i < days; i++) {
            // 之前经历0次，现在不持有
            profit[i][0][0] = profit[i - 1][0][0];
            // 之前经历0次，现在持有
            profit[i][0][1] = max(profit[i - 1][0][1], profit[i - 1][0][0] - prices[i]);
            
            // 之前经历1次，现在不持有
            profit[i][1][0] = max(profit[i - 1][1][0], profit[i - 1][0][1] + prices[i]);
            // 之前经历1次，现在持有
            profit[i][1][1] = max(profit[i - 1][1][1], profit[i - 1][1][0] - prices[i]);
            
            // 最后一次交易不持有
            profit[i][2][0] = max(profit[i - 1][2][0], profit[i - 1][1][1] + prices[i]);
        }
        
        int maxProfit = 0;
        for (int k = 0; k < K + 1; k++) {
            if (profit[days - 1][k][0] > maxProfit) {
                maxProfit = profit[days - 1][k][0];
            }
        }
        
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution = Solution();
    vector<int> prices = {3,3,5,0,0,3,1,4};
    int maxProfit = solution.maxProfit(prices);
    cout << maxProfit << endl;
    return 0;
}
