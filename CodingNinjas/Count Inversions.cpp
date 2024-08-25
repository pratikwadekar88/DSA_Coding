#include <bits/stdc++.h> 
/*  
    For a given integer array/list 'ARR' of size 'N' containing all distinct values, find the total number of 'Inversions' that may exist.

    An inversion is defined for a pair of integers in the array/list when the following two conditions are met.

    A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

    1. 'ARR[i] > 'ARR[j]' 
    2. 'i' < 'j'

    Where 'i' and 'j' denote the indices ranging from [0, 'N').

*/



// Function to merge two sorted halves of the array and count inversions
long long merge(long long *arr, long long low, long long mid, long long high) {

    // Temporary vector to store the merged elements
    vector<long long> temp;
    
    // Variable to store the count of inversions
    long long count = 0;

    // Pointers to track the current index of the left and right subarrays
    long long left = low, right = mid + 1;

    // Merge the two halves while counting inversions
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            // No inversion; take element from the left subarray
            temp.push_back(arr[left]);
            left++;
        } else {
            // Inversion found; take element from the right subarray
            temp.push_back(arr[right]);
            // Count inversions: number of elements remaining in the left subarray
            count += (mid - left + 1);
            right++;
        }
    }

    // Add remaining elements from the left subarray, if any
    while (left <= mid) temp.push_back(arr[left++]);

    // Add remaining elements from the right subarray, if any
    while (right <= high) temp.push_back(arr[right++]);

    // Copy the merged elements back into the original array
    for (long long j = low; j <= high; j++) {
        arr[j] = temp[j - low];
    }

    return count; // Return the count of inversions
}

// Recursive function to perform merge sort and count inversions
long long mergeSort(long long *arr, long long low, long long high) {
    long long count = 0;

    // Base case: if the subarray has one or no elements, no inversions
    if (low >= high) return count;

    // Find the middle point to divide the array into two halves
    long long mid = (low + high) / 2;

    // Recursively sort the first half and count inversions
    count += mergeSort(arr, low, mid);

    // Recursively sort the second half and count inversions
    count += mergeSort(arr, mid + 1, high);

    // Merge the two sorted halves and count any inversions during merging
    count += merge(arr, low, mid, high);

    return count; // Return the total count of inversions
}

// Function to count the number of inversions in the array
long long getInversions(long long *arr, int n) {
    // Call mergeSort to count inversions and return the result
    long long ans = mergeSort(arr, 0, n - 1);
    return ans;
}
