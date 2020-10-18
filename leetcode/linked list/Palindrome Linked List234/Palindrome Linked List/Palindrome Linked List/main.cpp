//
//  main.cpp
//  Palindrome Linked List
//
/**
 Given a singly linked list, determine if it is a palindrome.
 
 Example 1:
 
 Input: 1->2
 Output: false
 Example 2:
 
 Input: 1->2->2->1
 Output: true
 Follow up:
 Could you do it in O(n) time and O(1) space?
 */
//  Created by mingyue on 2020/10/18.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseLinkedList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *middle = nullptr;
        // while条件可以保证退出条件以及指针合法性（不会调用nullptr的next）
        // 如果链表节点是奇数的话，fast刚好走到最后一个有效节点，如果是偶数的话，fast刚好走到最后一个有效节点指向的空节点，slow始终走到第length/2+1个节点（length为链表长度）。slow刚好记住后半部分的第一个节点。
        while (fast && slow && fast->next) {
            middle = slow;//middle记住slow前边的节点
            fast = fast->next->next;
            slow = slow->next;
        }
        middle->next = nullptr;
        ListNode *backHead = reverseLinkedList(slow);
        bool isPalindrome = true;
        while (head && backHead) {
            if (head->val != backHead->val) {
                isPalindrome = false;
                break;
            }
            head = head->next;
            backHead = backHead->next;
        }
        return isPalindrome;
    }
};

int main(int argc, const char * argv[]) {
    
    ListNode *head = new ListNode();
    head->val = 1;
    ListNode *node1 = new ListNode();
    node1->val = 2;
    ListNode *node2 = new ListNode();
    node2->val = 0;
    ListNode *node3 = new ListNode();
    node3->val = 1;
    ListNode *node4 = new ListNode();
    node4->val = 1;
    head->next = node1;
    node1->next = nullptr;
    //node1->next = node2;
    //node2->next = nullptr;
    //node2->next = node3;
    //node3->next = nullptr;
    //node3->next = node4;
    //node4->next = nullptr;
    Solution solution = Solution();
    cout << solution.isPalindrome(head) << endl;
    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    
    return 0;
}
