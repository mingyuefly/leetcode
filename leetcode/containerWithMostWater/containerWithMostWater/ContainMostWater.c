//
//  ContainMostWater.c
//  containerWithMostWater
//
//  Created by Gguomingyue on 2019/6/12.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "ContainMostWater.h"

int maxArea(int* height, int heightSize){
    /*
    if (heightSize < 2) {
        return 0;
    }
    // 思路为每个柱子查遍所有可能，有很多重复情况计算
    int max = 0;
    for (int i = 0; i < heightSize; i++) {
        int tempHeight = height[i];
        int tempMax = 0;
        int j = i;
        while (j < heightSize) {
            if (height[j] >= tempHeight && j > i) {
                tempMax = tempHeight * (j - i);
            }
            if (tempMax > max) {
                max = tempMax;
            }
            j++;
        }
        while (j >= 0) {
            if (height[j] >= tempHeight && j < i) {
                tempMax = tempHeight * (i - j);
            }
            if (tempMax > max) {
                max = tempMax;
            }
            j--;
        }
    }
    return max;
     */
    
     // 改进思路，从两边向中间逼近，如果靠中间的小于等于靠边的则无需计算
    int Max = -1, area, l = 0, r = heightSize - 1, k;
    while(l < r){
        area = (height[l] < height[r]?height[l]:height[r]) * (r - l);
        Max = Max < area?area:Max;
        if (height[l] < height[r]) {
            k = l;
            while(l < r && height[l] <= height[k]) l++;
        } else {
            k = r;
            while(l < r && height[r] <= height[k]) r--;
        }
    }
    return Max;
}


