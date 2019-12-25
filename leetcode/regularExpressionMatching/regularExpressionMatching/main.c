//
//  main.c
//  regularExpressionMatching
//
//  Created by Gguomingyue on 2018/5/23.
//  Copyright © 2018年 Gmingyue. All rights reserved.
//

#include <stdio.h>
#include "IsMatching.h"

int main(int argc, const char * argv[]) {
    
    //char *s = "aa", *p = "a";
    //char *s = "aa", *p = "a*";
    //char *s = "ab", *p = ".*";
    //char *s = "aab", *p = "c*a*b";
    char *s = "mississippi", *p = "mis*is*p*.";
    
    bool match = isMatch(s, p);
    printf("match = %d\n",match);
    
    return 0;
}
