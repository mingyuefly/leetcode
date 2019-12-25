//
//  PalindromeNumber.c
//  palindRomeNumber
//
//  Created by Gguomingyue on 2018/5/23.
//  Copyright © 2018年 Gmingyue. All rights reserved.
//

#include "PalindromeNumber.h"


bool isPalindrome(int x) {
    
    if (x == 0) {
        return true;
    }
    if (x < 0) {
        return false;
    }
    
    int temp = x;
    int y = 0;
    while (temp > 0) {
        int tempY = temp % 10;
        temp = temp/10;
        y = y * 10 + tempY;
    }
    
    if (x == y) {
        return true;
    }
    
    return false;
}

