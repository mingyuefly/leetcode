//
//  main.c
//  ReverseIntege
//
//  Created by Gguomingyue on 2018/1/16.
//  Copyright © 2018年 Gguomingyue. All rights reserved.
//

#include <stdio.h>
#include "ReverseIntege.h"

int main(int argc, const char * argv[]) {
    
    int num = 1534236469;
//    int num = 15342364;
//    int num = -2147483412;
    int reverseNum = reverse(num);
    printf("reverseNum = %d\n",reverseNum);
    
    reverseNum = reverse1(num);
    printf("reverseNum = %d\n",reverseNum);
    
    return 0;
}
