//
//  main.c
//  LongestSubstringWithoutRepeating
//
//  Created by Gguomingyue on 2017/11/27.
//  Copyright © 2017年 guomingyue. All rights reserved.
//

#include <stdio.h>
#include "LongestSubstringWithoutRepeating.h"

int main(int argc, const char * argv[]) {
    
    char *s = "abcabcbb";
    //char *s = "bbbbb";
    //char *s = "pwwkew";
    //int length = lengthOfLongestSubstring(s);
    int length = lengthOfLongestSubstring1(s);
    printf("length = %d\n",length);
    
    return 0;
}
