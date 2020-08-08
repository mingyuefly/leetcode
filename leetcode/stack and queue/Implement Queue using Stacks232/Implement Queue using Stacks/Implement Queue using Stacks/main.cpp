//
//  main.cpp
//  Implement Queue using Stacks
//
/**
 Implement the following operations of a queue using stacks.

 push(x) -- Push element x to the back of queue.
 pop() -- Removes the element from in front of queue.
 peek() -- Get the front element.
 empty() -- Return whether the queue is empty.
 Example:

 MyQueue queue = new MyQueue();

 queue.push(1);
 queue.push(2);
 queue.peek();  // returns 1
 queue.pop();   // returns 1
 queue.empty(); // returns false
 Notes:

 You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 */
//  Created by mingyue on 2020/8/8.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stackOne;
    stack<int> stackTwo;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stackOne.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = peek();
        stackTwo.pop();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        if (stackTwo.empty()) {
            unsigned long size = stackOne.size();
            for (int i = 0; i < size; i++) {
                stackTwo.push(stackOne.top());
                stackOne.pop();
            }
        }
        return stackTwo.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stackOne.empty() && stackTwo.empty();
    }
};


int main(int argc, const char * argv[]) {
    
    MyQueue queue = MyQueue();

    queue.push(1);
    queue.push(2);
    int peek = queue.peek();  // returns 1
    cout << peek << endl;
    int pop = queue.pop();   // returns 1
    cout << pop << endl;
    int empty = queue.empty(); // returns false
    if (empty == true) {
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }
    queue.push(3);
    int peek1 = queue.peek();  // returns 1
    cout << peek1 << endl;
    int pop1 = queue.pop();   // returns 1
    cout << pop1 << endl;
    int empty1 = queue.empty(); // returns false
    if (empty1 == true) {
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }
    
    return 0;
}
