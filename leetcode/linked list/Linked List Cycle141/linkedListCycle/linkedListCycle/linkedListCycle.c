//
//  linkedListCycle.c
//  linkedListCycle
//
//  Created by mingyue on 2020/8/3.
//  Copyright © 2020 Gmingyue. All rights reserved.
//

#include "linkedListCycle.h"

bool linkedListCycle(struct ListNode *head)
{
    bool hasCycle = false;
    if (head == NULL || head->next == NULL) {
        return hasCycle;
    }
    struct ListNode *quickNode = head->next->next;
    struct ListNode *slowNode = head->next;
    while (true) {
        if (quickNode == NULL || slowNode == NULL) {
            break;
        }
        if (quickNode == slowNode) {
            hasCycle = true;
            break;
        }
        if (quickNode->next == NULL || quickNode->next->next == NULL) {
            break;
        }
        quickNode = quickNode->next->next;
        slowNode = slowNode->next;
    }
    return hasCycle;
}
