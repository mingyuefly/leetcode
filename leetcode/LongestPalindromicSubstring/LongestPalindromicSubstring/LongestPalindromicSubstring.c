//
//  LongestPalindromicSubstring.c
//  LongestPalindromicSubstring
//
//  Created by Gguomingyue on 2017/12/28.
//  Copyright © 2017年 Gguomingyue. All rights reserved.
//

#include "LongestPalindromicSubstring.h"
#include "stdlib.h"
#include "string.h"


char * longestPalindrome(char* s)
{
    if (s[1] == '\0') {
        return s;
    }

    char *longestPalindrom;
    char *tempLongestPalindrom;
    longestPalindrom = (char *)malloc(1000 * sizeof(char));
    tempLongestPalindrom = (char *)malloc(1000 * sizeof(char));
    int max = 0;
    int tempMax = 0;
    int i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        memset(tempLongestPalindrom, 0, sizeof(char) * (tempMax + 1));
        tempMax = 0;
        char first = s[i];
        tempLongestPalindrom[0] = first;
        for (int j = i + 1; s[j] != '\0'; j++) {
            tempMax++;
            char temp = s[j];
            tempLongestPalindrom[j-i] = temp;
            if (s[j] == first) {
                if (max < tempMax) {
                    max = tempMax;
                    memcpy(longestPalindrom, tempLongestPalindrom, sizeof(char) * (tempMax + 1));
                    if (s[j+1] != first) {
                        memset(tempLongestPalindrom, 0, sizeof(char) * (tempMax + 1));
                        tempMax = 0;
                        break;
                    }
                } else {
                    break;
                }
            }
        }
    }
//    if ((max + 1) == i) {
//        memset(longestPalindrom, 0, sizeof(char) * (max + 1));
//        longestPalindrom[0] = s[0];
//    }
    return longestPalindrom;
}

char * longestPalindromeRightAnswer(char* s)
{
    if (s[1] == '\0') {
        return s;
    }
    
    char *longestPalindrom;
    char *tempLongestPalindrom;
    char *reversLongestPalindrom;
    longestPalindrom = (char *)malloc(1000 * sizeof(char));
    tempLongestPalindrom = (char *)malloc(1000 * sizeof(char));
    reversLongestPalindrom = (char *)malloc(1000 * sizeof(char));
    int max = 0;
    int tempMax = 0;
    int i = 0;
    for (i = 0; s[i] != '\0'; i++) {
        // 清空tempLongestPalindrom，重置tempMax
        memset(tempLongestPalindrom, 0, sizeof(char) * (tempMax + 1));
        tempMax = 0;
        char first = s[i];
        tempLongestPalindrom[0] = first;
        for (int j = i + 1; s[j] != '\0'; j++) {
            tempMax++;
            char temp = s[j];
            tempLongestPalindrom[j-i] = temp;
            if (s[j] == first) {
                if (max < tempMax) {
                    // 判断是否回文
                    memset(reversLongestPalindrom, 0, sizeof(char) * (tempMax + 1));
                    int tempk = 0;
                    for (int k = tempMax; k >= 0; k--) {
                        reversLongestPalindrom[tempk] = tempLongestPalindrom[k];
                        tempk++;
                    }
                    bool isPalindrom = true;
                    for (int l = 0; l < tempMax + 1; l++) {
                        if (reversLongestPalindrom[l] != tempLongestPalindrom[l]) {
                            isPalindrom = false;
                            break;
                        }
                    }
                    if (isPalindrom == true) {
                        max = tempMax;
                        memset(longestPalindrom, 0, sizeof(char) * (tempMax + 1));
                        memcpy(longestPalindrom, tempLongestPalindrom, sizeof(char) * (tempMax + 1));
                    } else {
                        
                    }
                } else {
                    //break;
                }
            }
        }
    }
    
    free(tempLongestPalindrom);
    free(reversLongestPalindrom);
    
    if (longestPalindrom[0] == '\0') {
        longestPalindrom[0] = s[0];
    } else {
        char *endString = (char *)malloc((max + 1) * sizeof(char));
        memset(endString, 0, (max + 1) * sizeof(char));
        int i = 0;
        for (i = 0; i < max + 1; i++) {
            endString[i] = longestPalindrom[i];
        }
        endString[i + 1] = '\0';
        free(longestPalindrom);
        return endString;
    }
    return longestPalindrom;
}

bool isPalindrom(char * testPalindrom, int max)
{
    char * reversLongestPalindrom = (char *)malloc(1000 * sizeof(char));
    memset(reversLongestPalindrom, 0, sizeof(char) * (max + 1));
    int tempk = 0;
    for (int k = max; k >= 0; k--) {
        reversLongestPalindrom[tempk] = testPalindrom[k];
        tempk++;
    }
    bool isPalindrom = true;
    for (int l = 0; l < max + 1; l++) {
        if (reversLongestPalindrom[l] != testPalindrom[l]) {
            isPalindrom = false;
            break;
        }
    }
    return isPalindrom;
}

char* longestPalindromeFromWeb(char *s)
{
    char *d = NULL;
    char *rsl = NULL;
    int *p = NULL;
    int length = 0;
    int newLen = 0;
    int i = 0;
    int j = 0;
    int C = 0;
    int R = 0;
    int im = 0;
    int maxLen = 0;
    int center = 0;
    int start = 0;
    
    length = strlen(s);
    newLen = 2 * length + 2;
    d = (char *)malloc(sizeof(char) * newLen);
    if(d == NULL)
    {
        printf("d is NULL...");
        return NULL;
    }
    for(i = 0; i < length; i++)
    {
        d[j++] = '#';
        d[j++] = s[i];
    }
    d[j++] = '#';
    d[j] = '\0';
    
    p = (int *)malloc(sizeof(int) * newLen);
    if(p == NULL)
    {
        printf("The p is NULL!\n");
        return NULL;
    }
    
    for(i = 1; i < newLen - 1; i++)
    {
        im = 2 * C - i;
        if(im > 0 && i + p[im] <= R)
            p[i] = p[im];
        else
            p[i] = 0;
        
        while(d[i + 1 + p[i]] == d[i - 1 - p[i]] && i - 1 - p[i] >= 0)
            p[i]++;
        
        if(i + p[i] > R)
        {
            C = i;
            R = i + p[i];
        }
    }
    
    free(d);
    
    for(i = 1; i < newLen - 1;i++)
    {
        if(p[i] > maxLen)
        {
            maxLen = p[i];
            center = i;
        }
    }
    
    free(p);
    
    start = center - maxLen > 0 ? (center - maxLen) / 2 : (maxLen - center) / 2;
    rsl = (char *)malloc(sizeof(char) * maxLen);
    if(rsl == NULL)
    {
        printf("rsl is NULL......\n");
        return NULL;
    }
    for(i = 0; i < maxLen; i++)
    {
        rsl[i] = s[i + start];
    }
    rsl[maxLen] = '\0';
    return rsl;
}

int findOdd(char* s,int center){
    int i=center-1,j=center+1;
    while(i>=0 && s[j]){
        if(s[i]!=s[j])return j-1;
        i--;j++;
    }
    return j-1;
}
int findEven(char* s,int center){
    int i=center,j=center+1;
    while(i>=0 && s[j]){
        if(s[i]!=s[j]){
            return j-1;
        }
        i--;j++;
    }
    return j-1;
}

char* longestPalindromeFromWebSecond(char *s)
{
    int i=0,end,Max=1,Maxf=0,Maxe=0;
    // end 为目标字符串部分最后一位下标
    // Max 为目标字符串长度
    // Maxf 为目标字符串起始位置
    // Maxe 为目标字符串部分最后一位下标
    for(i=0;s[i];i++){
        end=findOdd(s,i);
        if(Max<(end-i)*2+1){
            Max=(end-i)*2+1;
            //Maxf=i+i-end;Maxe=end;
            Maxf = i-(end-i);Maxe=end;
        }
        end=findEven(s,i);
        if(Max<(end-i)*2){
            Max=(end-i)*2;
            //Maxf=i+i+1-end;Maxe=end;
            Maxf = i-(end-i)+1;Maxe=end;
        }
    }
    s[Maxe+1]='\0';
    return s+Maxf;//asbeffebda//asbefhfebda
}

char* longestPalindromeFromWebSecondToMatchOSX(char *s)
{
    int i=0,end,Max=1,Maxf=0,Maxe=0;
    for(i=0;s[i];i++){
        end=findOdd(s,i);
        if(Max<(end-i)*2+1){
            Max=(end-i)*2+1;
            Maxf=i+i-end;Maxe=end;
        }
        end=findEven(s,i);
        if(Max<(end-i)*2){
            Max=(end-i)*2;
            Maxf=i+i+1-end;Maxe=end;
        }
    }
    // Xcode下不能通过下标改字面量的某个值
    //s[Maxe+1]='\0';
    char *palindrom = (char *)malloc(sizeof(char) * (Maxe - Maxf + 1));
    int j = 0;
    for (j = 0; j < Maxe - Maxf + 1; j++) {
        palindrom[j] = s[Maxf + j];
    }
    palindrom[j+1] = '\0';
    //free(palindrom);
    return palindrom;
}

