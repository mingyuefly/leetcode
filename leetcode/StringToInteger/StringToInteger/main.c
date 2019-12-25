//
//  main.c
//  StringToInteger
//
//  Created by Gguomingyue on 2018/4/18.
//  Copyright © 2018年 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "StringToInteger.h"

int main(int argc, const char * argv[]) {
    
    char *input0 = "42";
    char *input1 = "   -42";
    char *input2 = "4193 with words";
    char *input3 = "words and 987";
    char *input4 = "-91283472332";
    char *input5 = "  -0012a42";
    int output = stringToInteger(input5);
    printf("output = %d\n",output);
    
    return 0;
}
