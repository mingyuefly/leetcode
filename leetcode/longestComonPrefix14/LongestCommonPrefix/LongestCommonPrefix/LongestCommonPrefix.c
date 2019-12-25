
//
//  LongestCommonPrefix.c
//  LongestCommonPrefix
//
//  Created by Gguomingyue on 2019/7/4.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "LongestCommonPrefix.h"
#include <stdlib.h>

/*
char * longestCommonPrefix(char ** strs, int strsSize){

    int minLength = 0;
    char * commonPrefix = (char *)malloc(sizeof(char) * 16);
    char * first = strs[0];
    while (*first) {
        char match = *first;
        for (int i = 1; i < strsSize; i++) {
            char * str = strs[i];
            char target = str[minLength];
            if (target) {
                if (target != match) {
                    return commonPrefix;
                    break;
                }
            } else {
                return commonPrefix;
            }
        }
        commonPrefix[minLength] = match;
        minLength++;
        first++;
    }
    return commonPrefix;
}
 */


/*
char * longestCommonPrefix(char ** strs, int strsSize){
    char * str = strs[0];
    int i, j;
    if(strsSize == 0)return "";
    for(i = 1; i < strsSize; i++){
        j = 0;
        while(str[j] && strs[i][j] && str[j] == strs[i][j])j++;
        str[j] = '0';
    }
    return str;
}
 */


char* longestCommonPrefix(char** strs, int strsSize) {
    char * str=strs[0];
    int i,j;
    if(strsSize==0)return "";
    for(i=1;i<strsSize;i++){
        j=0;
        while(str[j] && strs[i][j] && str[j]==strs[i][j])j++;
        str[j]='\0';
    }
    return str;
}

