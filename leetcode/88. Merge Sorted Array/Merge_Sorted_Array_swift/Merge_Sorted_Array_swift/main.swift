//
//  main.swift
//  Merge_Sorted_Array_swift
//
//  Created by gmy on 2023/6/1.
//

import Foundation

//print("Hello, World!")

class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var i = m - 1, j = n - 1, k = m + n - 1
        while i >= 0 && j >= 0 {
            if nums1[i] >= nums2[j] {
                nums1[k] = nums1[i]
                i -= 1
                k -= 1
            } else {
                nums1[k] = nums2[j]
                j -= 1
                k -= 1
            }
        }
        while i >= 0 {
            nums1[k] = nums1[i]
            i -= 1
            k -= 1
        }
        while j >= 0 {
            nums1[k] = nums2[j]
            j -= 1
            k -= 1
        }
    }
}

class Solution1 {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        for i in m..<m + n {
            nums1[i] = nums2[i - m]
        }
        nums1 = nums1.sorted()
    }
}

var nums1: [Int] = [1, 5, 8, 15, 22, 49, 0, 0, 0, 0, 0, 0, 0]
let nums2: [Int] = [2, 7, 9, 10 ,11, 28, 55]

//Solution().merge(&nums1, nums1.count - nums2.count, nums2, nums2.count)
//print(nums1)

Solution1().merge(&nums1, nums1.count - nums2.count, nums2, nums2.count)
print(nums1)

