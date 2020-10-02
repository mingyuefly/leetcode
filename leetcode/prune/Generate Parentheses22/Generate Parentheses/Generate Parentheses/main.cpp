//
//  main.cpp
//  Generate Parentheses
//
/**
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 For example, given n = 3, a solution set is:

 [
   "((()))",
   "(()())",
   "(())()",
   "()(())",
   "()()()"
 ]
 */
//  Created by mingyue on 2020/10/2.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    void generatOneByOne(string subString, vector<string> &strings, int left, int right) {
        if (left == 0 && right == 0) {
            strings.push_back(subString);
            return;
        }
        if (left > 0) {
            // 字符串拼接使用+，append用于追加字符
            //generatOneByOne(subString.append("("), strings, left - 1, right);
            generatOneByOne(subString +"(", strings, left - 1, right);
        }
        if (right > left) {
            generatOneByOne(subString + ")", strings, left, right - 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> strings;
        //string s = "";
        generatOneByOne("", strings, n, n);
        return strings;
    }
};

int main(int argc, const char * argv[]) {
    int n = 3;
    Solution solution = Solution();
    vector<string> strings = solution.generateParenthesis(n);
    for (int i = 0; i < strings.size(); i++) {
        cout << strings[i] << endl;
    }
    cout << endl;
    return 0;
}
