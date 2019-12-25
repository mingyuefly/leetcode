//
//  RomanToInteger.c
//  RomanToInteger
//
//  Created by Gguomingyue on 2019/7/4.
//  Copyright © 2019 Gmingyue. All rights reserved.
//


#include "RomanToInteger.h"

int romanToInt(char * s){
    
    int num = 0;
    int temp = 0;
    while (*s) {
        switch (*s) {
            case 'I':
            {
                num += 1;
                temp = 1;
            }
                break;
            case 'V':
            {
                num += temp == 1?3:5;
            }
                break;
            case 'X':
            {
                num += temp == 1?8:10;
                temp = 10;
            }
                break;
            case 'L':
            {
                num += temp == 10?30:50;
            }
                break;
            case 'C':
            {
                num += temp == 10?80:100;
                temp = 100;
            }
                break;
            case 'D':
            {
                num += temp == 100?300:500;
            }
                break;
            case 'M':
            {
                num += temp == 100?800:1000;
            }
                break;
            default:
                break;
        }
        s++;
    }
    
    return num;
}



