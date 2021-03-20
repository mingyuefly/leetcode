//
//  main.cpp
//  Number of Provinces
//
/**
 There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

 A province is a group of directly or indirectly connected cities and no other cities outside of the group.

 You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

 Return the total number of provinces.

  

 Example 1:


 Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 Output: 2
 Example 2:


 Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 Output: 3
  

 Constraints:

 1 <= n <= 200
 n == isConnected.length
 n == isConnected[i].length
 isConnected[i][j] is 1 or 0.
 isConnected[i][i] == 1
 isConnected[i][j] == isConnected[j][i]
 */
//  Created by mingyue on 2021/3/20.
//  Copyright © 2021 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class DSU {
private:
    //set<int> groupset;

public:
    vector<int> parent;
    DSU(int N) {
        vector<int> tmp(N, 0);
        parent = tmp;
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    void beginUnion(int i, int j) {
        if (!isConnected(i, j)) {
            int rootI = root(i);
            int rootJ = root(j);
            parent[rootJ] = rootI;

//            if (parent[rootJ] != -1){
//                groupset.insert(parent[rootJ]);
//            }
        }

    }

    bool isConnected(int i, int j) {
        return root(i) == root(j);
    }

    int root(int i) {
        while (i != parent[i]) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        DSU dsu = DSU(N);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (isConnected[i][j] == 1) {
                    dsu.beginUnion(i, j);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (dsu.parent[i] == i) {
                sum++;
            }
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
//    vector<vector<int>> isConnected = {
//        {1,1,0},
//        {1,1,0},
//        {0,0,1},
//    };
    
    vector<vector<int>> isConnected = {
        {1,0,0,1},
        {0,1,1,0},
        {0,1,1,1},
        {1,0,1,1},
    };
    
    Solution solution = Solution();
    int result = solution.findCircleNum(isConnected);
    cout << result << endl;
    return 0;
}
