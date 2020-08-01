//
//  reverseLinkedList.h
//  reverse-linked-list
//
//  Created by mingyue on 2020/7/30.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#ifndef reverseLinkedList_h
#define reverseLinkedList_h

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);

#endif /* reverseLinkedList_h */
