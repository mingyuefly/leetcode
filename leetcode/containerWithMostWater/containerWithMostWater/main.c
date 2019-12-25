//
//  main.c
//  containerWithMostWater
//
//  Created by Gguomingyue on 2019/6/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//  leetcode:https://leetcode.com/problems/container-with-most-water/
/*
 question:
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 
 Note: You may not slant the container and n is at least 2.
 **/


#include <stdio.h>
#include "ContainMostWater.h"

int main(int argc, const char * argv[]) {
    
    int lines[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int contain = maxArea(lines, 9);
    printf("%d\n", contain);
    
    return 0;
}
