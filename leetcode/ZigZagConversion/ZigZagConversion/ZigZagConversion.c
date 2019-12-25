//
//  ZigZagConversion.c
//  ZigZagConversion
//
//  Created by Gguomingyue on 2018/1/2.
//  Copyright © 2018年 Gguomingyue. All rights reserved.
//

#include "ZigZagConversion.h"

char* convert(char* s, int numRows)
{
    // the length of s: sLength
    // total ranks: sLength/(2 * numRows - 2) = n
    // if sLength/(2 * numRows - 2) == 0:n
    // else:n+1
    // the number of every line
    // first line: n or n + 1
    // end line: n or n + 1
    // others: (2 * n) or (2 * n + 1)
    // the index:
    // first line
    // original:0 + n * (2 * numRows - 2)
    // goal:    index <= n - 1 or index <= n
    // end line
    // original:numRows - 1 + n * (2 * numRows - 2)
    // goal:    n - 1 +
    // others:  n - 1 + (line - 2 - 1) * (2 * n + 1) +
    //
    //
    if (NULL == s || numRows < 1) {
        return NULL;
    }
    
    //char *s1 = NULL;
    //s1 = strcpy(s1, s);
    const size_t sLength = strlen(s);
    char* output = (char*) malloc(sizeof(char) * ( sLength + 1));
    char* head = output;
    output[sLength] = '\0';
    
    if (numRows == 1) {
        return s;
    }
    
//    for (int i = 0; s[i]; i++) {
//        if (i % (2 * numRows - 2) == 0) {
//            s1[i/(2 * numRows - 2)] = s[i];
//        } else if (i % (2 * numRows - 2) == (numRows - 1)) {
//            s1[(i/(2 * numRows - 2)) + (numRows - 1)] = s[i];
//        } else {
//            s1[]
//        }
//    }
    // 这个算法的妙处是将斜边赋值和直边分开，内层循环中步长只卡直边，但将斜边加入其中赋值，而且斜边上的值在每次内循环也只加一个
    for (int row = 0; row < numRows; row++) {
        for (int index = row; index < sLength; index += (2 * numRows - 2)) {
            // if it is the first row or the last row, then this is all
            *output++ = s[index];
            // otherwise, there are middle values, using (2nRows-2-2*row) rule
            // notice that nRows-1 is the last row
            if ( (row>0)&(row<numRows-1) & ((index+2*numRows - 2 - 2*row) < sLength))
            {
                *output++ = s[index+2*numRows - 2 - 2*row];
            }
        }
    }
    
    // the process of rule:(2nRows-2-2*row)
    // 2 * (nRows - row) - 1 - 1
    
    return head;
}
