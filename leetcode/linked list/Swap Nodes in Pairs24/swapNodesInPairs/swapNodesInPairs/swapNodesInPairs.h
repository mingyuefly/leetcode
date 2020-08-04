//
//  swapNodesInPairs.h
//  swapNodesInPairs
//
//  Created by mingyue on 2020/7/30.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#ifndef swapNodesInPairs_h
#define swapNodesInPairs_h

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head);

#endif /* swapNodesInPairs_h */
