//
//  twoSum.c
//  TwoSum
//
//  Created by Gguomingyue on 2017/11/14.
//  Copyright © 2017年 Gguomingyue. All rights reserved.
//

#include "twoSum.h"
#include "stdlib.h"

int* twoSum(int* nums, int numSize, int target)
{
    int* indexs;
    indexs = (int *)malloc(2 * sizeof(int));
    if (indexs) {
        printf("Memory Allocated at: %p\n",indexs);
    } else {
        printf("Not Enough Memory!/n");
    }
    for (int i = 0; i < numSize - 1; i++) {
        for (int j = i + 1; j < numSize; j++) {
            //printf("num i = %d\n",nums[i]);
            //printf("num j = %d\n",nums[j]);
            int tempTarget = nums[i] + nums[j];
            if (tempTarget == target) {
                indexs[0] = i;
                indexs[1] = j;
                break;
            }
        }
    }
    free(indexs);
    
    return indexs;
}

int* twoSumSecond(int* nums, int target)
{
    int* indexs;
    int numSize = 100;
    indexs = (int *)malloc(2 * sizeof(int));
    if (indexs) {
        printf("Memory Allocated at: %p\n",indexs);
    } else {
        printf("Not Enough Memory!/n");
    }
    for (int i = 0; i < numSize - 1; i++) {
        for (int j = i + 1; j < numSize; j++) {
            //printf("num i = %d\n",nums[i]);
            //printf("num j = %d\n",nums[j]);
            int tempTarget = nums[i] + nums[j];
            if (tempTarget == target) {
                indexs[0] = i;
                indexs[1] = j;
                break;
            }
        }
    }
    free(indexs);
    
    return indexs;
}
