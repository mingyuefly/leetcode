//
//  main.c
//  linkedListCycle
//
//  Created by mingyue on 2020/8/3.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedListCycle.h"

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
    //node3->next = NULL;
    //node4->next = node2;
    node4->next = NULL;
    
    bool hasCycle = linkedListCycle(head);
    if (hasCycle == true) {
        printf("has cycle");
    } else {
        printf("has no cycle");
    }
    printf("\n");
    
    free(head);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    
    return 0;
}
