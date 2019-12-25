//
//  IsMatching.c
//  regularExpressionMatching
//
//  Created by Gguomingyue on 2018/5/23.
//  Copyright © 2018年 Gmingyue. All rights reserved.
//

#include "IsMatching.h"
#include <assert.h>

bool isMatch(char* s, char* p){
    
    // 判断参数合法，以及程序正常结束
    assert(s && p);
    if (*p == '\0') {
        return *s == '\0';
    }
    
    // next char is not '*' ; must match current character
    if (*(p+1) != '*') {
        assert(*p != '*');
        return ((*p == *s) || (*p == '.' && *s != '\0')) && isMatch(s+1, p+1);
    }
    
    // next char is '*' 继续递归匹配，不能写成*(p+1) == '*' 考虑情况isMatch('ab','.*c')
    while ((*p == *s) || (*p == '.' && *s != '\0')) {
        if (isMatch(s, p+2)) {
            return true;
        }
        s++;
    }
    
    return isMatch(s, p+2);
}
