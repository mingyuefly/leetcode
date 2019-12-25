//
//  main.c
//  ZigZagConversion
//
//  Created by Gguomingyue on 2018/1/2.
//  Copyright © 2018年 Gguomingyue. All rights reserved.
//

#include <stdio.h>
#include "ZigZagConversion.h"

int main(int argc, const char * argv[]) {
    
    char *input = "PAYPALISHIRING";
    char* output = convert(input, 3);
    if (NULL != output)
    {
        printf("input: %s;  output: %s\n", input, output);
        free(output);
    }else
    {
        printf("empty\n");
    }
    return 0;
}
