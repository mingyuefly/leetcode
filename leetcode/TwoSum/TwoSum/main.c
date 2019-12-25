//
//  main.c
//  TwoSum
//
//  Created by Gguomingyue on 2017/11/14.
//  Copyright © 2017年 Gguomingyue. All rights reserved.
//

#include <stdio.h>
#include "twoSum.h"

int main(int argc, const char * argv[]) {
    
    int nums[5] = {3, 9, 4, 5, 1};
    int numSize = sizeof(nums)/sizeof(int);
    int target = 6;
    
    //int* indexs = twoSumSecond(nums, target);
    int* indexs = twoSum(nums, numSize, target);
    for (int i = 0; i < 2; i++) {
        printf("%d\n",indexs[i]);
    }
    
    return 0;
}
