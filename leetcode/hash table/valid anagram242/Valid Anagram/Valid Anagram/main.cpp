//
//  main.cpp
//  Valid Anagram
//
/**
 Given two strings s and t , write a function to determine if t is an anagram of s.

 Example 1:

 Input: s = "anagram", t = "nagaram"
 Output: true
 Example 2:

 Input: s = "rat", t = "car"
 Output: false
 Note:
 You may assume the string contains only lowercase alphabets.
 */
//  Created by mingyue on 2020/8/18.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> sMap;
        map<char, int> tMap;
        unsigned long sLength = s.length();
        unsigned long tLength = t.length();
        if (s.length() == 0 && t.length() == 0) {
            return true;
        }
        if (sLength != tLength) {
            return false;
        }
        for (int i = 0; i < sLength; i++) {
            char sa = s[i];
            if (!sMap.count(sa)) {
                sMap[sa] = 1;
            } else {
                int num = sMap[sa];
                num++;
                sMap[sa] = num;
            }
        }
        for (int i = 0; i < t.length(); i++) {
            char ta = t[i];
            if (!tMap.count(ta)) {
                tMap[ta] = 1;
            } else {
                int num = tMap[ta];
                num++;
                tMap[ta] = num;
            }
        }
        return sMap == tMap;
    }
};

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return (s==t);
    }
};

int main(int argc, const char * argv[]) {
    //string s = "anagram";
    //string t = "nagaram";
    string s = "aacc";
    string t = "ccac";
    //Solution solution = Solution();
    Solution1 solution = Solution1();
    bool valid = solution.isAnagram(s, t);
    if (valid) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }
    return 0;
}
