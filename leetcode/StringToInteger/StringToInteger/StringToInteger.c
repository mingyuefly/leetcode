//
//  StringToInteger.c
//  StringToInteger
//
//  Created by Gguomingyue on 2018/4/18.
//  Copyright © 2018年 Gmingyue. All rights reserved.
//

#include "StringToInteger.h"
#include <limits.h>

int stringToInteger(char *str)
{
    int flag = 1, result = 0, digital = 0;
    while (*str == ' ') str++;
    if (*str == '-') {
        flag = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str) {
        if (*str < '0' || *str > '9') {
            return flag * result;
        }
        digital = *str - '0';
        if (flag == 1 && result * 10.0 + digital > INT_MAX) {
            return INT_MAX;
        } else if (flag == -1 && -result * 10.0 - digital < INT_MIN) {
            return INT_MIN;
        }
        result = result * 10.0 + digital;
        str++;
    }
    
    return flag * result;
}
