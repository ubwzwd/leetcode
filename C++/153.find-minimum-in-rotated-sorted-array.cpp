/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.57%)
 * Likes:    1219
 * Dislikes: 179
 * Total Accepted:    321.4K
 * Total Submissions: 737.6K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
#include <vector>
#include <climits>
using namespace std;
// using binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0, end = nums.size()-1;
        int mid = 0;
        while(begin < end){
            // if(nums[begin] < nums[end]) return nums[begin];
            mid = ((end-begin)>>1) + begin;
            // rotation is in [mid, end]
            if(nums[mid] > nums[end]){
                begin = mid+1;
            }
            else{
                end = mid;
            }
        }
        return nums[begin];
    }
};

// // using divide and conquer
// class Solution {
//     // find the minimun number in [left, right)
//     int findMinRec(vector<int>& nums, int left, int right){
//         if(right-left == 1) return nums[left];
//         int mid = (right-left)/2+left;
//         int leftRes = findMinRec(nums, left, mid);
//         int rightRes = findMinRec(nums, mid, right);
//         return leftRes<rightRes? leftRes : rightRes;
//     }
// public:
//     int findMin(vector<int>& nums) {
//         return findMinRec(nums, 0, nums.size());
//     }
// };

