//
//  main.c
//  threeSum
//
//  Created by Gguomingyue on 2019/7/5.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

/*
 Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 
 Note:
 
 The solution set must not contain duplicate triplets.
 
 Example:
 
 Given array nums = [-1, 0, 1, 2, -1, -4],
 
 A solution set is:
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include "ThreeSum.h"

int main(int argc, const char * argv[]) {
    
    int test[6] = {-1, 0, 1, 2, -1, -4};
    int returnSize = 0;
    int * result = threeSum(test, 6, &returnSize, NULL);
    for (int i = 0; i < returnSize; i++) {
        printf(" %d ", result[i]);
        if (i != 0 && (i + 1) % 3 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    free(result);
    
    return 0;
}
