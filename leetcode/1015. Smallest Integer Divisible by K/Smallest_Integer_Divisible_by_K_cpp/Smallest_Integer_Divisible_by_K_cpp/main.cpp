//
//  main.cpp
//  Smallest_Integer_Divisible_by_K_cpp
//
/**
 1015. Smallest Integer Divisible by K
 Medium
 1.1K
 843
 Companies
 Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

 Return the length of n. If there is no such n, return -1.

 Note: n may not fit in a 64-bit signed integer.

  

 Example 1:

 Input: k = 1
 Output: 1
 Explanation: The smallest answer is n = 1, which has length 1.
 Example 2:

 Input: k = 2
 Output: -1
 Explanation: There is no such positive integer n divisible by 2.
 Example 3:

 Input: k = 3
 Output: 3
 Explanation: The smallest answer is n = 111, which has length 3.
  

 Constraints:

 1 <= k <= 105
 */
//  Created by gmy on 2023/5/30.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int resid = 1 % k;
        int n = 1;
        unordered_set<int> st;
        st.insert(resid);
        while (resid != 0) {
            resid = (resid * 10 + 1) % k;
            n++;
            if (st.find(resid) != st.end()) {
                return -1;
            }
            st.insert(resid);
        }
        
        
//        long num = 1;
//        int n = 1;
//        while (true) {
//            if (num % k == 0) {
//                break;
//            }
//            if (n > 20) {
//                n = -1;
//                break;
//            }
//            num = num * 10 + 1;
//            n++;
//        }
        return n;
    }
};

class Solution1 {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)  {
            return -1;
        }
        
        int resid = 1 % k;
        int n = 1;
        while (resid != 0) {
            resid = (resid * 10 + 1) % k;
            n++;
        }
        return n;
    }
};




int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.smallestRepunitDivByK(1) << endl;
    cout << solution.smallestRepunitDivByK(3) << endl;
    cout << solution.smallestRepunitDivByK(9) << endl;
    cout << solution.smallestRepunitDivByK(11) << endl;
    cout << solution.smallestRepunitDivByK(2) << endl;
    cout << solution.smallestRepunitDivByK(17) << endl;
    
    Solution1 solution1;
    cout << solution1.smallestRepunitDivByK(1) << endl;
    cout << solution1.smallestRepunitDivByK(3) << endl;
    cout << solution1.smallestRepunitDivByK(9) << endl;
    cout << solution1.smallestRepunitDivByK(11) << endl;
    cout << solution1.smallestRepunitDivByK(2) << endl;
    cout << solution1.smallestRepunitDivByK(17) << endl;
    
    return 0;
}
