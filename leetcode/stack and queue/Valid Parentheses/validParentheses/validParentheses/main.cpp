//
//  main.cpp
//  validParentheses
//

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
 */

//  Created by mingyue on 2020/8/5.
//  Copyright © 2020 Gmingyue. All rights reserved.
//


#include <iostream>
#include <stack>
#include <string>
//#include <>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmpStack;
        unsigned long size = s.length();
        bool isValid = false;
        for (int i = 0; i < size; i++) {
            char a = s[i];
            if (a == '(' || a == '[' || a == '{') {
                tmpStack.push(a);
            } else {
                if (tmpStack.size() == 0) {
                    isValid = false;
                    return isValid;
                }
                if (a == ')') {
                    if (tmpStack.top() == '(') {
                        tmpStack.pop();
                    } else {
                        isValid = false;
                        break;
                    }
                } else if (a == ']') {
                    if (tmpStack.top() == '[') {
                        tmpStack.pop();
                    } else {
                        isValid = false;
                        break;
                    }
                } else if (a == '}') {
                    if (tmpStack.top() == '{') {
                        tmpStack.pop();
                    } else {
                        isValid = false;
                        break;
                    }
                }
            }
        }
        
        if (tmpStack.size() == 0) {
            isValid = true;
        }
        return isValid;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    string inputString = "()";
    string inputString1 = "()[]{}";
    string inputString2 = "(]";
    string inputString3 = "([)]";
    string inputString4 = "{[]}";
    string inputString5 = "]";
    
    bool isValid = solution.isValid(inputString5);
    if (isValid == true) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }
    //std::cout << "Hello, World!\n";
    return 0;
}
