//
//  ReverseIntege.c
//  ReverseIntege
//
//  Created by Gguomingyue on 2018/1/16.
//  Copyright © 2018年 Gguomingyue. All rights reserved.
//

#include "ReverseIntege.h"

int reverse(int x)
{
    char *reverseArray = (char *)malloc(12 * sizeof(char));//int num = 1534236469;
    
    int division = x;
    int index = 0;
    while (division != 0) {
        int delivery = division % 10;
        reverseArray[index] = delivery + 48;
        index++;
        division = division/10;
    }
    reverseArray[index + 1] = '\0';
    
    int reverse = 0;
    int index0 = index;
    for (int i = 0; i < index0; i++) {
        int digit = reverseArray[i] - 48;
        int index1 = index - 1;
        for (int i = index1; i > 0; i--) {
            digit *= 10;
        }
        reverse += digit;
        index--;
    }
    free(reverseArray);
    
    return reverse;
}

// reverse1能通过LeetCode检测，而reverse不能(主要原因是判断值超出区域是个问题)
int reverse1(int x) {
    int flag=x>0?1:-1,res=0;
    x=x>0?x:-x;
    while(x>0){
        if((2147483647.0-x%10)/10<res) {
            return 0;
        }
        res=res*10+x%10;
        x=x/10;
    }
    return res*flag;
}

