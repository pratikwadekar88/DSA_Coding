#include<bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int m, int n, int k){
    // Base case: If the first array is larger than the second, swap them to ensure
    // that we are always binary searching on the smaller array.
    if(m > n) return kthElement(arr2, arr1, n, m, k);

    // Define the search space for binary search.
    // 'low' is the minimum number of elements we can take from 'arr1', 
    // and 'high' is the maximum number of elements we can take from 'arr1'.
    int low = max(0, k - n);  // Ensures we don't take more elements than available in arr2.
    int high = min(k, m);     // Ensures we don't take more elements than available in arr1.
    int left = k;             // Total number of elements we need in the left half of the merged array.

    // Start binary search
    while(low <= high){
        // Divide the current search range in 'arr1' and calculate how many elements
        // from 'arr2' we need to make the left partition size equal to 'k'.
        int mid1 = (low + high) >> 1;  // Midpoint of 'arr1'
        int mid2 = left - mid1;        // Remaining elements taken from 'arr2'

        // Set boundary values for left and right elements.
        // For the left side, we use INT_MIN for out-of-bounds values.
        // For the right side, we use INT_MAX for out-of-bounds values.
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        // Set valid values for the right and left side elements in both arrays.
        if(mid1 < m) r1 = arr1[mid1];   // Right element in 'arr1'
        if(mid2 < n) r2 = arr2[mid2];   // Right element in 'arr2'
        if(mid1 > 0) l1 = arr1[mid1-1]; // Left element in 'arr1'
        if(mid2 > 0) l2 = arr2[mid2-1]; // Left element in 'arr2'

        // Check if we have a valid partition:
        // 1. The largest left element in both partitions is less than or equal to
        //    the smallest right element.
        // 2. If true, we return the largest left element since we are at the k-th element.
        if(l1 <= r2 && l2 <= r1)
            return max(l1, l2);

        // If left side in 'arr1' is too large, reduce 'high' to move left in 'arr1'.
        else if(l1 > r2)
            high = mid1 - 1;

        // If left side in 'arr2' is too large, increase 'low' to move right in 'arr1'.
        else
            low = mid1 + 1;
    }

    // If no valid partition is found, return 0 (this should not occur for valid inputs).
    return 0;
}
