//
//  main.cpp
//  Implement Stack using Queues
//
/**
 Implement the following operations of a stack using queues.

 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 empty() -- Return whether the stack is empty.
 Example:

 MyStack stack = new MyStack();

 stack.push(1);
 stack.push(2);
 stack.top();   // returns 2
 stack.pop();   // returns 2
 stack.empty(); // returns false
 Notes:

 You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */
//  Created by mingyue on 2020/8/8.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> queueOne;
    queue<int> queueTwo;
    //queue<int> queueThree;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queueOne.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int result = queueOne.back();
        while (queueOne.size() != 1) {
            queueTwo.push(queueOne.front());
            queueOne.pop();
        }
        queueOne.pop();
        swap(queueOne, queueTwo);
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return queueOne.back();;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queueOne.empty();
    }
};

int main(int argc, const char * argv[]) {
    MyStack stack = MyStack();

    stack.push(1);
    stack.push(2);
    int top = stack.top();   // returns 2
    cout << top << endl;
    int pop = stack.pop();   // returns 2
    cout << pop << endl;
    bool empty = stack.empty(); // returns false
    if (empty) {
        cout << "empty" << endl;
    } else {
        cout << "not empty" << endl;
    }
    return 0;
}
