//
//  AddTwoNumbers.c
//  AddTwoNumbers
//
//  Created by Gguomingyue on 2017/11/15.
//  Copyright © 2017年 guomingyue. All rights reserved.
//

#include "AddTwoNumbers.h"
#include <stdlib.h>

struct ListNode * createListNode(int num)
{
    struct ListNode *listNode = malloc(sizeof(listNode));
    listNode->val = num;
    listNode->next = NULL;
    return listNode;
}

void push(int num, struct ListNode *listNode)
{
    struct ListNode *list = malloc(sizeof(listNode));
    list->val = num;
    list->next = NULL;
    while (1) {
        if (listNode->next == NULL) {
            listNode->next = list;
            break;
        }
        listNode = listNode->next;
    }
}

void pop(struct ListNode *listNode)
{
    while (1) {
        struct ListNode *temp;
        if (listNode->next == NULL) {
            temp->next = NULL;
            break;
        }
        temp = listNode;
        listNode = listNode->next;
    }
}

void delete(struct ListNode *listNode)
{
    struct ListNode * pList = listNode;
    struct ListNode * pNext;
    while (pList != NULL) {
        pNext = pList->next;
        free(pList);
        pList = pNext;
    }
}

struct ListNode * reverse(struct ListNode *listNode)
{
    struct ListNode *list;
    int listArr[100];
    int i = 0;
    while (1) {
        printf("%d\n",listNode->val);
        listArr[i] = listNode->val;
        if (listNode->next == NULL) {
            printf("\n");
            break;
        }
        listNode = listNode->next;
        i++;
    }
    printf("i = %d\n\n",i);
    int j = i;
    for (j; j >= 0; j--) {
        if (j == i) {
            list = createListNode(listArr[j]);
        } else {
            push(listArr[j], list);
        }
    }
    return list;
}

struct ListNode * reverse1(struct ListNode *listNode)
{
    struct ListNode *pList = listNode;
    struct ListNode *paPre = NULL;
    struct ListNode *paNext = NULL;
    do {
        paNext = pList->next;
        pList->next = paPre;
        paPre = pList;
        pList = paNext;
    } while (pList != NULL);
    return paPre;
}

struct ListNode * reverse2(struct ListNode *listNode)
{
    struct ListNode *p1, *p2, *p3;
    if (listNode == NULL) {
        return listNode;
    }
    p1 = listNode;
    p2 = p1->next;
    while (p2) {
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
    }
    listNode->next = NULL;
    listNode = p1;
    return listNode;
}

struct ListNode * reverse3(struct ListNode *listNode)
{
    struct ListNode *p, *q;
    p = listNode->next;
    while (p->next != NULL) {
        q = p->next;
        p->next = q->next;
        q->next = listNode->next;
        listNode->next = q;
    }
    p->next = listNode;
    listNode = p->next->next;
    p->next->next = NULL;
    return listNode;
}

void traverse(struct ListNode *listNode)
{
    while (1) {
        printf("%d\n",listNode->val);
        if (listNode->next == NULL) {
            printf("\n");
            break;
        }
        listNode = listNode->next;
    }
}

void deeltail(struct ListNode * pre,struct ListNode * r,int carry);

struct ListNode * addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *head, *p, *q, *pre;
    int carry = 0;
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    
    head = l1;
    p = head;
    
    while (l1 && l2) {
        pre = p;
        p->val = l1->val + l2->val + carry;
        carry = 0;
        if (p->val > 9) {
            p->val -= 10;
            carry = 1;
        }
        l1 = l1->next;
        l2 = l2->next;
        p = p->next;
    }
    
    if (!l1 && !l2) {
        if (carry) {
            q= (struct ListNode *)malloc(sizeof(struct ListNode));
            q->val = carry;
            q->next = NULL;
            pre->next = q;
        }
    } else if (l2) {
        deeltail(pre, l2, carry);
    } else {
        deeltail(pre, l1, carry);
    }
    
    return head;
}

void deeltail(struct ListNode * pre,struct ListNode * r,int carry){
    struct ListNode * q;
    pre->next = r;
    q = pre->next;
    while(q){
        q->val +=carry;
        if(q->val>9){
            q->val -= 10;
            carry = 1;
        }else{
            carry =0;
            
        }
        pre = q;
        q = q->next;
    }
    if(carry){//最后一个节点加上进位大于10需处理多出来的节点，val=1
        q= (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = carry;
        q->next = NULL;
        pre->next = q;
    }
}


