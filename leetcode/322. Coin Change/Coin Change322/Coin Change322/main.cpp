//
//  main.cpp
//  Coin Change322
//
/**
 You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

 You may assume that you have an infinite number of each kind of coin.

  

 Example 1:

 Input: coins = [1,2,5], amount = 11
 Output: 3
 Explanation: 11 = 5 + 5 + 1
 Example 2:

 Input: coins = [2], amount = 3
 Output: -1
 Example 3:

 Input: coins = [1], amount = 0
 Output: 0
 Example 4:

 Input: coins = [1], amount = 1
 Output: 1
 Example 5:

 Input: coins = [1], amount = 2
 Output: 2
  

 Constraints:

 1 <= coins.length <= 12
 1 <= coins[i] <= 231 - 1
 0 <= amount <= 104
 */
//  Created by mingyue on 2021/2/28.
//  Copyright © 2021 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SolutionR {
    void getMinCountsHelper(int rest, vector<int>& coins, vector<int> counts, vector<vector<int>> &combinations) {
        if (rest == 0) {
            combinations.push_back(counts);
        }
        int coinSize = (int)coins.size();
        for (int i = 0; i < coinSize; i++) {
            int coin = coins[i];
            if (coin > rest) {
                continue;
            }
            vector<int> newCounts = counts;
            newCounts[i]++;
            int restCount = rest - coin;
            getMinCountsHelper(restCount, coins, newCounts, combinations);
        }
    }
    int getMinimumHelper(const vector<vector<int>> &combinations) {
        if (combinations.size() == 0) {
            return -1;
        }
        int minCount = INT_MAX;
        for(const vector<int> &counts : combinations) {
            int sum = 0;
            for(int num : counts) {
                sum += num;
            }
            if (sum < minCount) {
                minCount = sum;
            }
        }
        return minCount;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }
        vector<int> intialCounts(coins.size(), 0);
        vector<vector<int>> combinations;
        getMinCountsHelper(amount, coins, intialCounts, combinations);
        return getMinimumHelper(combinations);
    }
};

class SolutionR1 {
    int getMinCountsHelper(int total, vector<int>& coins) {
        if (total == 0) {
            return 0;
        }
        int coinSize = (int)coins.size();
        int minCount = INT_MAX;
        for (int i = 0; i < coinSize; i++) {
            int coin = coins[i];
            if (coin > total) {
                continue;
            }
            int rest = total - coin;
            int restCount = getMinCountsHelper(rest, coins);
            if (restCount == -1) {// 组合不可信，跳过
                continue;
            }
            int totalCount = 1 + restCount;
            if (totalCount < minCount) {
                minCount = totalCount;
            }
        }
        // 如果没有组合，返回-1
        if (minCount == INT_MAX) {
            return -1;
        }
        return minCount;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }
        return getMinCountsHelper(amount, coins);
    }
};

class SolutionR2 {
    int getMinCountsHelper(int total, vector<int>& coins, vector<int> &memo) {
        auto savedMinCount = memo[total];
        if (savedMinCount != -2) {
            return savedMinCount;
        }
        int coinSize = (int)coins.size();
        int minCount = INT_MAX;
        for (int i = 0; i < coinSize; i++) {
            int coin = coins[i];
            if (coin > total) {
                continue;
            }
            int rest = total - coin;
            int restCount = getMinCountsHelper(rest, coins, memo);
            if (restCount == -1) {// 组合不可信，跳过
                continue;
            }
            int totalCount = 1 + restCount;
            if (totalCount < minCount) {
                minCount = totalCount;
            }
        }
        // 如果没有组合，返回-1
        if (minCount == INT_MAX) {
            memo[total] = -1;
            return -1;
        }
        memo[total] = minCount; // 记录到备忘录
        return minCount;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }
        vector<int> memo(amount + 1, -2);
        memo[0] = 0;
        return getMinCountsHelper(amount, coins, memo);
    }
};

class SolutionDP {
    int getMinCountsHelper(int k, const vector<int>& coins) {
        vector<int> memo(k + 1, -1); // 创建备忘录
        memo[0] = 0; // 初始化状态
        for (int v = 1; v <= k; v++) {
            int minCount = k + 1;
            for (int i = 0; i < coins.size(); i++) {
                int coin = coins[i];
                if (coin > v) {
                    continue;
                }
                // 使用当前面值，得到剩余硬币总额
                int rest = v - coin;
                int restCount = memo[rest];
                // 如果返回-1，说明组合不可信，跳过
                if (restCount == -1) {
                    continue;
                }
                // 保留最小总额
                int kCount = 1 + restCount;
                if (kCount < minCount) {
                    minCount = kCount;
                }
            }
            // 如果是可用组合，记录结果
            if (minCount != k + 1) {
                memo[v] = minCount;
            }
        }
        return memo[k];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }
        return getMinCountsHelper(amount, coins);
    }
};

class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }
        int Max = amount + 1; // 模拟一个无穷大
        vector<int> dp(amount + 1, Max);// i为币值，元素为在这个币值上需要的硬币数量
        int coinSize = (int)coins.size();
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coinSize; j++) {
                if (coins[j] <= i) { // 限制条件，过滤极端情况，即将要新加的币值大于i
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

class Solution2 {
    vector<int> count;
    int dp(vector<int>& coins, int rem) {
        if (rem < 0) {
            return -1;
        }
        if (rem == 0) {
            return 0;
        }
        if (count[rem - 1] != 0) {
            return count[rem - 1];
        }
        int Min = INT_MAX;
        for(int coin : coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }
        count[rem - 1] = Min == INT_MAX ? -1 : Min;
        return count[rem - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }
        count.resize(amount);
        return dp(coins, amount);
    }
};

class Solution3 {
    int dp(vector<int>& coins, int rem, vector<int> &count) {
        if (rem < 0) {
            return -1;
        }
        if (rem == 0) {
            return 0;
        }
        if (count[rem - 1] != 0) {
            return count[rem - 1];
        }
        int Min = INT_MAX;
        for(int coin : coins) {
            int res = dp(coins, rem - coin, count);
            if (res >= 0 && res < Min) {
                Min = res + 1;
            }
        }
        count[rem - 1] = Min == INT_MAX ? -1 : Min;
        return count[rem - 1];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.empty()) {
            return -1;
        }
        vector<int> count;
        count.resize(amount);
        return dp(coins, amount, count);
    }
};


int main(int argc, const char * argv[]) {
    vector<int> coins = {1,2,5};
    int amount = 11;
    
//    SolutionR solution = SolutionR();
//    int result = solution.coinChange(coins, amount);
//    cout << result << endl;
    
//    SolutionR1 solution = SolutionR1();
//    int result = solution.coinChange(coins, amount);
//    cout << result << endl;
    
//    SolutionR2 solution = SolutionR2();
//    int result = solution.coinChange(coins, amount);
//    cout << result << endl;
    
//    SolutionDP solution = SolutionDP();
//    int result = solution.coinChange(coins, amount);
//    cout << result << endl;
    
//    Solution1 solution1 = Solution1();
//    int result = solution1.coinChange(coins, amount);
//    cout << result << endl;
    
//    Solution2 solution2 = Solution2();
//    int result = solution2.coinChange(coins, amount);
//    cout << result << endl;
    
    Solution3 solution3 = Solution3();
    int result = solution3.coinChange(coins, amount);
    cout << result << endl;
    
    return 0;
}
