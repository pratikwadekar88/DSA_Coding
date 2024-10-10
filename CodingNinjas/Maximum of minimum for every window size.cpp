#include <bits/stdc++.h> 

// Function to find the index of the next smaller element for each element in the array
vector<int> nextSmaller(vector<int> &arr) {
    stack<int> st;  // Stack to store indices of elements
    int n = arr.size();
    vector<int> nse(n);  // Array to store the indices of the next smaller elements
    
    // Traverse the array from right to left
    for(int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack until the top of the stack is greater than arr[i]
        while(!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        // If the stack is empty, there is no smaller element to the right
        if(st.empty())
            nse[i] = n;  // No smaller element, so store n (out of bounds index)
        else
            nse[i] = st.top();  // Store the index of the next smaller element
        
        st.push(i);  // Push the current element index onto the stack
    }
    return nse;  // Return the array of next smaller element indices
}

// Function to find the index of the previous smaller element for each element in the array
vector<int> prevSmaller(vector<int> &arr) {
    stack<int> st;  // Stack to store indices of elements
    int n = arr.size();
    vector<int> pse(n);  // Array to store the indices of the previous smaller elements
    
    // Traverse the array from left to right
    for(int i = 0; i < n; i++) {
        // Pop elements from the stack until the top of the stack is greater than arr[i]
        while(!st.empty() && arr[i] <= arr[st.top()]) {
            st.pop();
        }
        // If the stack is empty, there is no smaller element to the left
        if(st.empty())
            pse[i] = -1;  // No smaller element, so store -1 (out of bounds index)
        else
            pse[i] = st.top();  // Store the index of the previous smaller element
        
        st.push(i);  // Push the current element index onto the stack
    }
    return pse;  // Return the array of previous smaller element indices
}

// Main function to calculate the maximum of the minimum element for each window size
vector<int> maxMinWindow(vector<int> a, int n) {
    vector<int> nse = nextSmaller(a);  // Find the next smaller element for each index
    vector<int> pse = prevSmaller(a);  // Find the previous smaller element for each index

    vector<int> ans(n, INT_MIN);  // Array to store the maximum of minimums for each window size

    // For each element, calculate the length of the window where it is the minimum
    for(int i = 0; i < n; i++) {
        int len = nse[i] - pse[i] - 1;  // Length of the window where a[i] is the minimum
        if(ans[len - 1] < a[i])
            ans[len - 1] = a[i];  // Update the maximum minimum for this window size
    }

    // Fill in the remaining values for smaller window sizes
    int i = n - 2;  // Start from the second last element
    int j = n - 1;  // Start from the last element
    while(i >= 0) {
        if(ans[i] < ans[j]) {  // Propagate the maximum value to smaller window sizes
            ans[i] = ans[j];
            i--;
        } else {
            j = i;
            i--;
        }
    }

    return ans;  // Return the result array
}
