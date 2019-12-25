//
//  ThreeSum.c
//  threeSum
//
//  Created by Gguomingyue on 2019/7/5.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include "ThreeSum.h"

int * threeSum(int* nums, int numsSize, int* returnSize, int * returnColumnSizes){
    
    int count = 0;
    returnColumnSizes = (int *)malloc(sizeof(int*) * numsSize * (numsSize - 1) * (numsSize - 2));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if ((nums[i] + nums[j] + nums[k]) == 0) {
                    returnColumnSizes[3 * count + 0] = nums[i];
                    returnColumnSizes[3 * count + 1] = nums[j];
                    returnColumnSizes[3 * count + 2] = nums[k];
                    count++;
                }
            }
        }
    }
    *returnSize = count * 3;
    
    return returnColumnSizes;
}


