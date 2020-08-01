//
//  swapNodesInPairs.c
//  swapNodesInPairs

/**
 Given a linked list, swap every two adjacent nodes and return its head.

 You may not modify the values in the list's nodes, only nodes itself may be changed.

  

 Example:

 Given 1->2->3->4, you should return the list as 2->1->4->3.
 */
//
//  Created by mingyue on 2020/7/30.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include "swapNodesInPairs.h"

struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *node1 = head;
    struct ListNode *node2 = head->next;
    struct ListNode *node3 = head->next->next;
    struct ListNode *pre = NULL;
    head = node2;
    //struct ListNode *returnHead = head->next;
    while (node1 != NULL && node2 != NULL) {
        node1->next = node3;
        node2->next = node1;
        if (pre != NULL) {
            pre->next = node2;
        }
        pre = node1;
        node1 = node3;
        if (node3 == NULL || node3->next == NULL) {
            break;
        }
        node2 = node1->next;
        node3 = node1->next->next;
    }
    return head;
}
