//
//  MedianOfTwoSortedArrays.c
//  MedianOfTwoSortedArrays
//
//  Created by Gguomingyue on 2017/11/28.
//  Copyright © 2017年 guomingyue. All rights reserved.
//

#include "MedianOfTwoSortedArrays.h"
#include <string.h>

double findMedianSortedArraysFunction(int* nums1, int nums1Size, int* nums2, int nums2Size, int k);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int k = nums1Size + nums2Size;
    if (k % 2 != 0) {//奇数
        return findMedianSortedArraysFunction(nums1, nums1Size, nums2, nums2Size, k/2 + 1);
    } else {//偶数
        return (findMedianSortedArraysFunction(nums1, nums1Size, nums2, nums2Size, k/2) + findMedianSortedArraysFunction(nums1, nums1Size, nums2, nums2Size, k/2 + 1))/2;
    }
}

double findMedianSortedArraysFunction(int* nums1, int nums1Size, int* nums2, int nums2Size, int k)
{
    if (nums1Size > nums2Size) {
        return findMedianSortedArraysFunction(nums2, nums2Size, nums1, nums1Size, k);
    }
    if (nums1Size == 0) {
        return nums2[k - 1];
    }
    if (k == 1) {// nums1Size == nums2Size == 1;
        if (nums1[0] < nums2[0]) {
            return nums1[0];
        } else {
            return nums2[0];
        }
    }
    
    // 以下nums1Size 均小于 nums2Size
    int pa;
    if (k/2 < nums1Size) {//
        pa = k/2;
    } else {
        pa = nums1Size;
    }
    int pb = k - pa;
    
    if (nums1[pa - 1] < nums2[pb - 1]) {
        return findMedianSortedArraysFunction(nums1 + pa, nums1Size - pa, nums2, nums2Size, k-pa);
    } else if (nums1[pa - 1] > nums2[pb - 1]) {
        return findMedianSortedArraysFunction(nums1, nums1Size, nums2 + pb, nums2Size - pb, k - pb);
    } else {
        return nums1[pa - 1];
    }
}

