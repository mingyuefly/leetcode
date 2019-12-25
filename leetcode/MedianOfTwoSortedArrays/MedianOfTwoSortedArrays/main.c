//
//  main.c
//  MedianOfTwoSortedArrays
//
//  Created by Gguomingyue on 2017/11/28.
//  Copyright © 2017年 guomingyue. All rights reserved.
//

#include <stdio.h>
#include "MedianOfTwoSortedArrays.h"

int main(int argc, const char * argv[]) {
    
    
    int nums1Size = 0;
    int nums2Size = 2;
    int nums1[0] = {};
    int nums2[2] = {2, 3};
    
    double median = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
    printf("median = %.02f\n", median);
    
    return 0;
}
