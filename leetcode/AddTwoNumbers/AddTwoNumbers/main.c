//
//  main.c
//  AddTwoNumbers
//
//  Created by Gguomingyue on 2017/11/15.
//  Copyright © 2017年 guomingyue. All rights reserved.
//

#include <stdio.h>
#include "AddTwoNumbers.h"

int main(int argc, const char * argv[]) {
    
    struct ListNode *list1 = createListNode(2);
    push(4, list1);
    push(3, list1);
    //traverse(list1);
    //pop(list1);
    //pop(list);
    //pop(list);
    //traverse(list);
    
    struct ListNode *list2 = createListNode(5);
    push(6, list2);
    push(4, list2);
    //traverse(list2);
    
    struct ListNode * addTwoList = addTwoNumbers(list1, list2);
    traverse(addTwoList);
    
    push(10, list1);
    push(15, list1);
    push(9, list1);
    push(12, list1);
    traverse(list1);
    
    //struct ListNode *reverseList = reverse(list1);
    //struct ListNode *reverseList = reverse1(list1);
    struct ListNode *reverseList = reverse2(list1);
    //struct ListNode *reverseList = reverse3(list1);
    traverse(reverseList);
    
    /*
    delete(list1);
    delete(list2);
    delete(addTwoList);
    delete(reverseList);
     */
    
    return 0;
}
