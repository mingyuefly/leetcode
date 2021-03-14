//
//  main.cpp
//  quicUnionUF
//
//  Created by mingyue on 2021/3/7.
//  Copyright © 2021 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class QuickUnionUF {
private:
    vector<int> roots;
    int findRoot(int i) {
        int root = i;
        // 找到root
        while (root != roots[root]) {
            root = roots[root];
        }
        // 压缩路径
        while (i != roots[i]) {
            int tmp = roots[i];
            roots[i] = root;
            i = tmp;
        }
        return root;
    }
public:
    QuickUnionUF(int n) {
        vector<int> tmp(n, 0);
        roots = tmp;
        for (int i = 0; i < n; i++) {
            roots[i] = i;
        }
    }
    
    bool connected(int p, int q) {
        return findRoot(p) == findRoot(q);
    }
    
    void beginUnion(int p, int q) {
        int pRoot = findRoot(p);
        int qRoot = findRoot(q);
        roots[pRoot] = qRoot;
    }
};


int main(int argc, const char * argv[]) {
    QuickUnionUF uf = QuickUnionUF(10);
    return 0;
}
