/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (43.37%)
 * Likes:    2149
 * Dislikes: 181
 * Total Accepted:    376.8K
 * Total Submissions: 861K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
    void swap(int& a, int& b){
        int c = a;
        a = b;
        b = c;
    }
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(!len) return;
        // these three index are the heads of each color
        int red = 0, blue = len-1, white = 0;
        // the order of sorted colors should be red, white, blue
        while(white <= blue){
            if(nums[white] == 0){
                swap(nums[white], nums[red]);
                white++;
                red++;
            }
            else if(nums[white] == 2){
                swap(nums[white], nums[blue]);
                blue--;
            }
            else white++;
        }
    }
};
// @lc code=end

