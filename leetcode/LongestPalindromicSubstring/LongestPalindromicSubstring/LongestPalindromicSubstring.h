//
//  LongestPalindromicSubstring.h
//  LongestPalindromicSubstring
//
//  Created by Gguomingyue on 2017/12/28.
//  Copyright © 2017年 Gguomingyue. All rights reserved.
//

#ifndef LongestPalindromicSubstring_h
#define LongestPalindromicSubstring_h

#include <stdio.h>
#include "stdbool.h"

// 这个方法我审题错误，搞错了回文的定义
char * longestPalindrome(char* s);

// 在我机器上成功，但提交到leetcode错误
char * longestPalindromeRightAnswer(char* s);

// 鉴别是否回文
bool isPalindrom(char * testPalindrom, int max);

// 网络答案1
char* longestPalindromeFromWeb(char *s);

// 网络答案2
char* longestPalindromeFromWebSecond(char *s);
char* longestPalindromeFromWebSecondToMatchOSX(char *s);


#endif /* LongestPalindromicSubstring_h */
