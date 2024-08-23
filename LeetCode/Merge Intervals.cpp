/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;  // This will store the merged intervals

        // Sort the intervals based on the starting time of each interval
        sort(intervals.begin(), intervals.end());

        // Iterate through the intervals
        for (int i = 0; i < intervals.size(); i++) {
            // If ans is empty or the current interval does not overlap with the last interval in ans
            if (ans.empty() || intervals[i][0] > ans.back()[1]) {
                ans.push_back(intervals[i]);  // Add the current interval to ans
            } 
            else {
                // If there is an overlap, merge the intervals by updating the end time of the last interval in ans
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;  // Return the merged intervals
    }
};
