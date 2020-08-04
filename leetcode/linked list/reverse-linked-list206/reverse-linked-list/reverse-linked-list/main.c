//
//  main.c
//  reverse-linked-list
/**
 Reverse a singly linked list.

 Example:

 Input: 1->2->3->4->5->NULL
 Output: 5->4->3->2->1->NULL

 */


//
//  Created by mingyue on 2020/7/29.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "reverseLinkedList.h"


int main(int argc, const char * argv[]) {
    
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 5;
    struct ListNode *node1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node1->val = 4;
    struct ListNode *node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node2->val = 3;
    struct ListNode *node3 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node3->val = 2;
    struct ListNode *node4 = (struct ListNode *)malloc(sizeof(struct ListNode));
    node4->val = 1;
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    
    struct ListNode * tmpHead = head;
    while (tmpHead) {
        printf("%d ", tmpHead->val);
        tmpHead = tmpHead->next;
    }
    printf("\n");
    
    struct ListNode * headR = reverseList(head);
    while (headR) {
        printf("%d ", headR->val);
        headR = headR->next;
    }
    printf("\n");
    
    
    free(head);
    head = NULL;
    free(node4);
    node4 = NULL;
    free(node3);
    node3 = NULL;
    free(node2);
    node2 = NULL;
    free(node1);
    node1 = NULL;
    
    return 0;
}
