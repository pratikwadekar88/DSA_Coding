int findPlatform(vector<int>& arr, vector<int>& dep) {
    // Get the number of trains
    int n = arr.size();
    
    // Sort the arrival and departure times
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    
    // Initialize pointers for arrival (i) and departure (j) times
    int i = 1, j = 0;
    
    // Initialize variables to track the platform count and maximum platforms needed
    int count = 1; // At least one platform is needed for the first train
    int ans = 1;   // Store the maximum number of platforms needed
    
    // Traverse through both arrays until all trains have been processed
    while (i < n && j < n) {
        // If the next train is arriving before or at the same time the previous train departs
        if (arr[i] <= dep[j]) {
            count++;  // Increase the count of platforms needed
            i++;      // Move to the next arriving train
        } else {
            // If the next train departs before the next arrival, free a platform
            count--;  // Decrease the platform count
            j++;      // Move to the next departing train
        }
        
        // Update the maximum number of platforms needed so far
        ans = max(count, ans);
    }
    
    // Return the maximum number of platforms needed
    return ans;
}
