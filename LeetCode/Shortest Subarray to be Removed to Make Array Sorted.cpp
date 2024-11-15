class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int prefix = 0, suffix = n - 1;
        
        // Find the length of the non-decreasing prefix
        while (prefix < n - 1 && arr[prefix] <= arr[prefix + 1]) 
            prefix++;
        
        // Find the length of the non-decreasing suffix
        while (suffix > 0 && arr[suffix - 1] <= arr[suffix]) 
            suffix--;
        
        // If the entire array is already non-decreasing
        if (prefix == n - 1) 
            return 0;
        
        int ans = INT_MAX;

        // Binary search based approach (commented out in your code):
        // for (int i = prefix; i >= 0; i--) {
        //     int idx = lower_bound(arr.begin() + suffix, arr.end(), arr[i]) - arr.begin();
        //     ans = min(ans, idx - i - 1);
        // }

        // Linear time complexity solution (O(n))
        int i = prefix, j = n - 1;
        while (i >= 0 && j >= suffix) {
            if (arr[i] <= arr[j]) {
                ans = min(ans, j - i - 1);
                i--;  // Move left pointer
            } else {
                j--;  // Move right pointer only if we can't satisfy arr[i] <= arr[j]
            }
        }
        
        // Evaluate subarray lengths based on prefix and suffix
        ans = min({ans, suffix, n - prefix - 1});
        return ans;
    }
};
