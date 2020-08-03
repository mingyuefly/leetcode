//
//  linkedListCycle.h
//  linkedListCycle
//
//  Created by mingyue on 2020/8/3.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#ifndef linkedListCycle_h
#define linkedListCycle_h

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool linkedListCycle(struct ListNode *head);

#endif /* linkedListCycle_h */
