//
//  main.cpp
//  LRU Cache
//
/**
 Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

 Implement the LRUCache class:

 LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 int get(int key) Return the value of the key if the key exists, otherwise return -1.
 void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 Follow up:
 Could you do get and put in O(1) time complexity?

  

 Example 1:

 Input
 ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 Output
 [null, null, null, 1, null, -1, null, -1, 3, 4]

 Explanation
 LRUCache lRUCache = new LRUCache(2);
 lRUCache.put(1, 1); // cache is {1=1}
 lRUCache.put(2, 2); // cache is {1=1, 2=2}
 lRUCache.get(1);    // return 1
 lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 lRUCache.get(2);    // returns -1 (not found)
 lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 lRUCache.get(1);    // return -1 (not found)
 lRUCache.get(3);    // return 3
 lRUCache.get(4);    // return 4
  

 Constraints:

 1 <= capacity <= 3000
 0 <= key <= 3000
 0 <= value <= 104
 At most 3 * 104 calls will be made to get and put.

 */
//  Created by mingyue on 2021/3/21.
//  Copyright © 2021 Gmingyue. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

/*
class LRUCache {
public:
    list<int> lru_key;
    unordered_map<int, int> lru;
    int capacity;
//public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        lru.clear();
    }
    
    int get(int key) {
        if (lru.count(key) > 0) {
            lru_key.remove(key);
            lru_key.push_front(key);
            return lru[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (lru.count(key) > 0) {
            lru[key] = value;
            lru_key.remove(key);
            lru_key.push_front(key);
        } else if (lru.size() >= capacity) {
            lru.erase(lru_key.back());
            lru_key.pop_back();
            lru[key] = value;
            lru_key.push_front(key);
        } else {
            lru[key] = value;
            lru_key.push_front(key);
        }
    }
};
 */

class LRUCache {
public:
    
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int capacity;
        
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    
    int get(int key)
    {
        int value = -1;
        
        if(map.count(key) > 0)
        {
            list<pair<int, int>>::iterator itr = map[key];
            if(itr != cache.end())
            {
                value = itr->second;
                
                cache.push_front(*itr);
                cache.erase(itr);
                
                map[key] = cache.begin();
            }
        }
        
        return value;
    }
    
    void put(int key, int value)
    {
        if(map.count(key) > 0 && map[key] != cache.end())
        {
            list<pair<int, int>>::iterator itr = map[key];
            itr->second = value;
            
            cache.push_front(*itr);
            cache.erase(itr);

            map[key] = cache.begin();
            
            return;
        }
        
        if(cache.size() == capacity)
        {
            list<pair<int, int>>::iterator last = cache.end();
            
            last--;
                
            if(last != cache.end())
            {
                map[last->first] = cache.end();
            }
            
            cache.pop_back();
        }
        
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }
};


int main(int argc, const char * argv[]) {
    LRUCache lruCache = LRUCache(2);
    lruCache.put(1, 1); // cache is {1=1}
    lruCache.put(2, 2); // cache is {1=1, 2=2}
    int result1 = -1;
    result1 = lruCache.get(1);    // return 1
    cout << result1 << endl;
    lruCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    int result2 = -1;
    result2 = lruCache.get(2);    // returns -1 (not found)
    cout << result2 << endl;
    lruCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    int result3 = -1;
    result3 = lruCache.get(1);    // return -1 (not found)
    cout << result3 << endl;
    int result4 = -1;
    result4 = lruCache.get(3);    // return 3
    cout << result4 << endl;
    int result5 = -1;
    result5 = lruCache.get(4);    // return 4
    cout << result5 << endl;
    return 0;
}
