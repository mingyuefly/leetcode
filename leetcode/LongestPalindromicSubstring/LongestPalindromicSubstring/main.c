//
//  main.c
//  LongestPalindromicSubstring
//
//  Created by Gguomingyue on 2017/12/28.
//  Copyright © 2017年 Gguomingyue. All rights reserved.
//

#include <stdio.h>
#include "LongestPalindromicSubstring.h"

int main(int argc, const char * argv[]) {
    
    char *input = "babad";
    char *input1 = "a";
    char *input2 = "cbbd";
    char *input3 = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
    char *input4 = "cccc";
    char *input5 = "abcda";
    char *input6 = "bananas";
    char *input7 = "aaabaaaa";
    char *input8 = "vommleztyrbrnoij";
    char *input9 = "vommleztyrbaabrnoij";
    
    char inputx[1000];
    char *ptr;
    printf("Please input your name.\n");
    ptr = gets(inputx); //使用一个地址吧字符串赋值给name
    //gets()函数使用return关键字返回字符串的地址
    printf("name, %s\n", inputx);
    printf("ptr, %s\n", ptr);
    
    //char *output = longestPalindrome(input6);
    //char *output = longestPalindromeRightAnswer(input8);
    //char *output = longestPalindromeFromWeb(input8);
    char *output = longestPalindromeFromWebSecond(ptr);
    //char *output = longestPalindromeFromWebSecondToMatchOSX(input9);
    printf("%s\n", output);
//    while (*output) {
//        printf("%c", *output);
//        *output++;
//    }
//    printf("\n");
//    for (int i = 0; output[i] != '\0'; ++i)
//    {
//        printf("%c", output[i]);
//    }
//    printf("\n");
    
    
//    char *test = "aaabaaa";
//    char *test1 = "aabaaa";
//    if (isPalindrom(output, 2)) {
//        printf("是回文\n");
//    } else {
//        printf("不是回文\n");
//    }
    
    
    return 0;
}
