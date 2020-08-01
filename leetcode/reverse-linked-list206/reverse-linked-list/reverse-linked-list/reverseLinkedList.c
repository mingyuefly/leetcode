//
//  reverseLinkedList.c
//  reverse-linked-list
//
//  Created by mingyue on 2020/7/30.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include "reverseLinkedList.h"

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *pre = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    while (current) {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    return pre;
}
