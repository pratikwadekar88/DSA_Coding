class Solution {
public:
    // Merge function to combine two sorted halves of the array
    void merge(vector<int> & nums, int low, int mid, int high){
        int left = low;        // Starting index for the left subarray
        int right = mid+1;     // Starting index for the right subarray
        vector<int> temp;      // Temporary array to store the merged result

        // Merging the two halves into temp
        while(left <= mid && right <= high) {
            if(nums[left] < nums[right])   // If element in left subarray is smaller
                temp.push_back(nums[left++]);  // Add it to temp and move left pointer
            else
                temp.push_back(nums[right++]); // Otherwise, add element from right subarray
        }   

        // Add any remaining elements from the left subarray
        while(left <= mid) {
            temp.push_back(nums[left++]);
        }
        
        // Add any remaining elements from the right subarray
        while(right <= high) {
            temp.push_back(nums[right++]);
        }
        
        // Copy the merged elements back into the original array
        for(int i = low; i <= high; i++) {
            nums[i] = temp[i-low];
        }
    }

    // Function to count reverse pairs within the current subarray
    int countPairs(vector<int> &nums, int low, int mid, int high) {
        int right = mid+1;   // Start of the right subarray
        int left = low;      // Start of the left subarray
        int cnt = 0;         // Initialize reverse pairs count

        // Iterate through the left subarray
        for(int i = left; i <= mid; i++) {
            // Find the first element in the right subarray where the reverse pair condition is violated
            while (right <= high && (long long)nums[i] >  (2*(long long)nums[right])) right++;
            // Count valid pairs
            cnt += right - (mid + 1);
        }
        return cnt;
    }

    // Recursive merge sort function that also counts reverse pairs
    int mergeSort(vector<int> & nums, int low, int high) {
        int cnt = 0;   // Initialize reverse pairs count
        if(low >= high) return cnt;  // Base case: only one element

        int mid = (low + high) / 2;  // Calculate the middle index
        cnt += mergeSort(nums, low, mid);    // Sort and count in the left half
        cnt += mergeSort(nums, mid + 1, high); // Sort and count in the right half
        cnt += countPairs(nums, low, mid, high); // Count reverse pairs across the halves
        merge(nums, low, mid, high); // Merge the sorted halves

        return cnt;  // Return the total count of reverse pairs
    }

    // Main function to return the number of reverse pairs in the array
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);  // Call the merge sort and count function
    }
};
