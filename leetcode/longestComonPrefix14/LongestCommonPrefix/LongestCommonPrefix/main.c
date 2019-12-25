//
//  main.c
//  LongestCommonPrefix
//
//  Created by Gguomingyue on 2019/7/4.
//  Copyright © 2019 Gmingyue. All rights reserved.
//
/*
 Write a function to find the longest common prefix string amongst an array of strings.
 
 If there is no common prefix, return an empty string "".
 
 Example 1:
 
 Input: ["flower","flow","flight"]
 Output: "fl"
 Example 2:
 
 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:
 
 All given inputs are in lowercase letters a-z.
 */

#include <stdio.h>
#include "LongestCommonPrefix.h"

int main(int argc, const char * argv[]) {
    char * strs[] = {"flower","flow","flight"};
    //char * strs[] = {"flhower","flhow","flhight"};
    //char * strs[] = {"dog","racecar","car"};
    char * commonPrefix = longestCommonPrefix(strs, 3);
    printf("commonPrefix = %s\n", commonPrefix);
    return 0;
}
