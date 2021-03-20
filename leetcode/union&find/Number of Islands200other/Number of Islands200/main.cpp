//
//  main.cpp
//  Number of Islands200
//
/**
 Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

 An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

  

 Example 1:

 Input: grid = [
   ["1","1","1","1","0"],
   ["1","1","0","1","0"],
   ["1","1","0","0","0"],
   ["0","0","0","0","0"]
 ]
 Output: 1
 Example 2:

 Input: grid = [
   ["1","1","0","0","0"],
   ["1","1","0","0","0"],
   ["0","0","1","0","0"],
   ["0","0","0","1","1"]
 ]
 Output: 3
  

 Constraints:

 m == grid.length
 n == grid[i].length
 1 <= m, n <= 300
 grid[i][j] is '0' or '1'.
 */
//  Created by mingyue on 2021/3/14.
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
    int numIslands(vector<vector<char>>& grid) {
        int N = grid.size() * grid[0].size();
        int nSmall = grid[0].size();
        DSU dsu = DSU(N);

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    if (i + 1 < grid.size() && grid[i + 1][j] == '1') {
                        dsu.beginUnion((nSmall * i + j), (nSmall * (i + 1) + j));
                    }
                    if (j + 1 < grid[i].size() && grid[i][j + 1] == '1') {
                        dsu.beginUnion((nSmall * i + j), (nSmall * i + j + 1));
                    }
                } else {
                    dsu.parent[nSmall * i + j] = -1;
                }
            }
        }

        set<int> countSet;
        for (int i = 0; i < dsu.parent.size(); i++) {
            if (dsu.parent[i] != -1) {
                countSet.insert(dsu.root(i));
            }
        }

        return countSet.size();
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'},
    };
    
    Solution solution = Solution();
    int result = solution.numIslands(grid);
    cout << result << endl;
    
    return 0;
}
