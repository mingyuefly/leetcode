//
//  main.cpp
//  Kth Largest Element in a Stream
//
//  Created by mingyue on 2020/8/9.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int __ =[]() // improve input read speed.
{
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    return 0;
}();

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq; //min-heap;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (auto &num : nums) {
            if (pq.size() < size) {
                pq.push(num);
            } else if (pq.top() < num) {
                pq.pop();
                pq.push(num);
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < size) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};


int main(int argc, const char * argv[]) {
    int k = 3;
    vector<int> arr = {4, 5, 8, 2};
    KthLargest kthLargest = KthLargest(k, arr);
    kthLargest.add(3);   // returns 4
    kthLargest.add(5);   // returns 5
    kthLargest.add(10);  // returns 5
    kthLargest.add(9);   // returns 8
    kthLargest.add(4);   // returns 8
    
    return 0;
}
