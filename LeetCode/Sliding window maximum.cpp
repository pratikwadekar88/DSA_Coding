class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq; // A deque to store indices of elements in the current window
        int n = nums.size(); // Size of the input array
        vector<int> ans; // Vector to store the result

        // Loop through the array
        for (int i = 0; i < n; i++) {
            
            // Remove indices of elements that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front(); // Remove elements that are out of the current window
            }

            // Remove indices of elements that are smaller than the current element
            // because they will never be the maximum in this window or future windows
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back(); // Pop the smaller elements as they are no longer useful
            }

            // Push the current element index at the back of the deque
            dq.push_back(i);

            // When we have processed at least 'k' elements, the front of the deque
            // is the index of the largest element for the current window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]); // Add the maximum of the current window to the result
            }
        }

        // Return the result array containing maximums of each sliding window
        return ans;
    }
};
