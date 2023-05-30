//
//  main.c
//  palindRomeNumber
//
//  Created by Gguomingyue on 2018/5/23.
//  Copyright © 2018年 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "PalindromeNumber.h"

int main(int argc, const char * argv[]) {
    
    int x = 121;
    //int x = 231;
    //int x = 10;
    //int x = -121;
    bool isPalindromeNum = isPalindrome(x);
    printf("%d\n",isPalindromeNum);
    
    return 0;
}
