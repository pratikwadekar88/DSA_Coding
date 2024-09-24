/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.*/


class Solution {
public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    
        // Approach 3: Optimal approach using binary search
        
        int n1 = a.size(); // Size of first array
        int n2 = b.size(); // Size of second array
        
        // Ensure the first array is smaller to minimize the binary search space
        if(n1 > n2) return findMedianSortedArrays(b, a);

        int low = 0, high = n1; // Set binary search range for the smaller array
        int left = (n1 + n2 + 1) / 2; // Calculate half of the total elements
        int n = n1 + n2; // Total size of both arrays combined
        
        // Binary search loop
        while(low <= high) {
            int mid1 = (low + high) >> 1; // Mid-point of the first array
            int mid2 = left - mid1; // Corresponding point in the second array

            // Initialize left and right partition elements to handle out-of-bound cases
            int l1 = INT_MIN; int l2 = INT_MIN;
            int r1 = INT_MAX; int r2 = INT_MAX;
            
            // Set partition boundaries for the first array
            if(mid1 < n1) r1 = a[mid1]; // Right partition element in the first array
            if(mid2 < n2) r2 = b[mid2]; // Right partition element in the second array
            if(mid1 - 1 >= 0) l1 = a[mid1 - 1]; // Left partition element in the first array
            if(mid2 - 1 >= 0) l2 = b[mid2 - 1]; // Left partition element in the second array
            
            // Check if valid partitioning is found
            if(l1 <= r2 && l2 <= r1) {
                // If total size is odd, return the maximum element from the left partitions
                if(n % 2 == 1) return max(l1, l2);
                // If total size is even, return the average of the maximum left and minimum right partition elements
                return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
            }
            // If left partition of first array is too large, move search space to the left
            else if(l1 > r2)
                high = mid1 - 1;
            // Otherwise, move search space to the right
            else 
                low = mid1 + 1;
        }

        return 0; // Return 0 if no median is found (shouldn't happen with valid input)



        // Approach 1: Brute force approach
        // First merge both arrays and then return the median from the merged array.

        // Approach 2: Better approach (O(n)) - Commented out
        /*
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2; // Total size
        // Required indices:
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int cnt = 0;
        int ind1el = -1, ind2el = -1;

        // Apply the merge step:
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                if (cnt == ind1) ind1el = a[i];
                if (cnt == ind2) ind2el = a[i];
                cnt++;
                i++;
            } else {
                if (cnt == ind1) ind1el = b[j];
                if (cnt == ind2) ind2el = b[j];
                cnt++;
                j++;
            }
        }

        // Copy the left-out elements:
        while (i < n1) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }

        // Find the median:
        if (n % 2 == 1) {
            return (double)ind2el;
        }

        return (double)((double)(ind1el + ind2el)) / 2.0;
        */
    }
};
