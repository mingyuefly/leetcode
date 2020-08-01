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
#include <stdbool.h>

struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *first = head;
    struct ListNode *second = head->next;
    head = head->next;
    while (true) {
        if (second->next == NULL || second->next->next == NULL) {
            first->next = second->next;
            second->next = first;
            break;
        }
        first->next = second->next->next;
        struct ListNode *tmp = second->next;
        second->next = first;
        first = tmp;
        second = second->next->next;
    }
    return head;
}
