//
//  LongestSubstringWithoutRepeating.c
//  LongestSubstringWithoutRepeating
//
//  Created by Gguomingyue on 2017/11/27.
//  Copyright © 2017年 guomingyue. All rights reserved.
//

#include "LongestSubstringWithoutRepeating.h"
//#include <string.h>

int lengthOfLongestSubstring(char* s) {
    
    int length = 0;
    int otherLength = 0;
    char temp[100] = {};
    //printf("length = %d\n",length);
    //printf("length1 = %d\n",otherLength);
    int sLength = 0;
    while (*s) {
        sLength++;
        *s++;
    }
    //size_t sLength = strlen(s);
    printf("sLength = %d\n",sLength);
    char sArray[sLength];
    *s--;
    for (int k = sLength - 1; k >= 0; k--) {
        sArray[k] = *s;
        *s--;
    }
    //    for (int i = 0; i < sLength; i++) {
    //        printf("sArray[k] = %c\n",sArray[i]);
    //    }
    
    for (int i = 0; i < sLength; i++) {
        length = 0;
        for (int m = i; m < sLength; m++) {
            printf("sArray[k] = %c\n",sArray[m]);
            char charactor = sArray[m];
            temp[length] = charactor;
            length++;
            if (length - 1 == 0) {
                
            } else {
                for (int j = 0; j < length - 1; j++) {
                    char tempCharctor = temp[j];
                    if (charactor == tempCharctor) {
                        if (length > otherLength) {
                            otherLength = length - 1;
                            length = 0;
                        } else {
                            length = 0;
                        }
                        //printf("length1 = %d\n",otherLength);
                        break;
                    }
                }
            }
        }
    }
    
    return otherLength;
}

int lengthOfLongestSubstring1(char* s)
{
    int maxlen = 0,currlen = 0;
    int table[128], i, j, start = 0;
    memset(table, 0, sizeof(table));
    for (i = 0; s[i] != '\0'; ++i){
        if( (++table[s[i]]) == 2 ){
            if (currlen > maxlen){
                maxlen = currlen;
            }
            for(j = start; j < i; ++j){ //start记录重复的字符后一个位置
                if (s[j] == s[i]){
                    table[s[j]] = 1;
                    start = j+1;
                    break;
                }else{
                    --currlen;
                    table[s[j]] = 0;
                }
            }
        }else{
            ++currlen;
        }
    }
    if (currlen > maxlen){
        maxlen = currlen;
    }
    return maxlen;
}
