//
//  AddTwoNumbers.h
//  AddTwoNumbers
//
//  Created by Gguomingyue on 2017/11/15.
//  Copyright © 2017年 guomingyue. All rights reserved.
//

#ifndef AddTwoNumbers_h
#define AddTwoNumbers_h

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode * createListNode(int num);
void push(int num, struct ListNode *listNode);
void pop(struct ListNode *listNode);
void delete(struct ListNode *listNode);
struct ListNode * reverse(struct ListNode *listNode);
struct ListNode * reverse1(struct ListNode *listNode);
struct ListNode * reverse2(struct ListNode *listNode);
struct ListNode * reverse3(struct ListNode *listNode);
void traverse(struct ListNode *listNode);

struct ListNode * addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

#endif /* AddTwoNumbers_h */
