//
//  main.cpp
//  reverseLinkedListCPP
//
//  Created by gmy on 2023/5/27.
//

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    ListNode *head = new ListNode(0);
    ListNode *node1 = new ListNode(1);
    head->next = node1;
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    ListNode *node3 = new ListNode(3);
    node2->next = node3;
    ListNode *node4 = new ListNode(4);
    node3->next = node4;
    node4->next = nullptr;
    
    ListNode *tmpHead = head;
    while (head) {
        cout << head->val << ' ';
        head = head->next;
    }
    
    cout << endl;
    head = tmpHead;
    ListNode *head1 = solution.reverseList(head);
    while (head1) {
        cout << head1->val << ' ';
        head1 = head1->next;
    }
    cout << endl;
    
    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    
    return 0;
}


//typedef struct Node{
//    int data;
//    Node * next;
//    Node(int data) {
//        this->data = data;
//    }
//}Node;
//
//Node * inverseLinkedList(Node * head) {
//    Node *pre = nullptr;
//    Node *next = nullptr;
//    while (head) {
//        next = head->next;
//        head->next = pre;
//        pre = head;
//        head = next;
//    }
//    return pre;
//}
//
//int main(int argc, const char * argv[]) {
//
//    Node *head = new Node(0);
//    Node *node1 = new Node(1);
//    head->next = node1;
//    Node *node2 = new Node(2);
//    node1->next = node2;
//    Node *node3 = new Node(3);
//    node2->next = node3;
//    Node *node4 = new Node(4);
//    node3->next = node4;
//    node4->next = nullptr;
//
//    Node *tmpHead = head;
//    while (head) {
//        cout << head->data << ' ';
//        head = head->next;
//    }
//
//    cout << endl;
//    head = tmpHead;
//    Node *head1 = inverseLinkedList(head);
//    while (head1) {
//        cout << head1->data << ' ';
//        head1 = head1->next;
//    }
//    cout << endl;
//
//    delete head;
//    delete node1;
//    delete node2;
//    delete node3;
//    delete node4;
//
//    return 0;
//}
