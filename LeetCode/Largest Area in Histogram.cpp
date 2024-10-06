class Solution {
public:

    // Function to find the next smaller element for each element in the array
    // vector<int> nextSmallerElement(vector<int>& arr){
    //     int n = arr.size();  // Get the size of the array
    //     vector<int> nse(n);  // Vector to store the next smaller elements
    //     stack<int> st;       // Stack to keep track of elements' indices
    //     
    //     // Traverse the array from right to left
    //     for(int i=n-1;i>=0;i--){
    //         if(st.empty()){  // If stack is empty, no smaller element exists
    //             nse[i] = n;
    //         }else{
    //             // Pop elements from stack until a smaller element is found
    //             while(!st.empty() && arr[st.top()]>arr[i]){
    //                 st.pop();
    //             }
    //             // If stack is empty, no smaller element; otherwise, take the top of stack
    //             if(st.empty())
    //                 nse[i] = n;
    //             else
    //                 nse[i] = st.top();
    //         }
    //         st.push(i);  // Push the current index onto the stack
    //     }
    //
    //     return nse;  // Return the next smaller elements
    // }

    // Function to find the previous smaller element for each element in the array
    // vector<int> prevSmallerElement(vector<int>& arr){
    //     int n = arr.size();  // Get the size of the array
    //     vector<int> pse(n);  // Vector to store the previous smaller elements
    //     stack<int> st;       // Stack to keep track of elements' indices
    //     
    //     // Traverse the array from left to right
    //     for(int i=0;i<n;i++){
    //         if(st.empty()){  // If stack is empty, no smaller element exists
    //             pse[i] = -1;
    //         }else{
    //             // Pop elements from stack until a smaller element is found
    //             while(!st.empty() && arr[st.top()]>=arr[i]){
    //                 st.pop();
    //             }
    //             // If stack is empty, no smaller element; otherwise, take the top of stack
    //             if(st.empty())
    //                 pse[i] = -1;
    //             else
    //                 pse[i] = st.top();
    //         }
    //         st.push(i);  // Push the current index onto the stack
    //     }
    //
    //     return pse;  // Return the previous smaller elements
    // }

    int largestRectangleArea(vector<int>& heights) {
        
        // Approach 2: Single pass to calculate the largest rectangle area
        stack<int> st;  // Stack to store indices of elements in 'heights'
        int ans = 0 ;   // Variable to store the maximum rectangle area
        int n= heights.size();  // Get the size of the 'heights' array

        // Traverse the heights array and also handle the case when i == n
        // We are checking for i == n condition because if there are some untouched nodes
        // then we will include them as well in stack
        for(int i = 0;i<=n;i++){
                // Calculate the area for every element that is greater than the current element or if we are at the end
                while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                    int element = heights[st.top()];  // Get the height of the top element in stack
                    st.pop();  // Pop the top element as it's now processed
                    // If stack is empty, calculate area considering the full width (from index 0 to i)
                    if(st.empty())
                        ans = max(ans,element*i);
                    else
                        // If stack is not empty, calculate area considering the width between current element and the one in the stack
                        ans = max(ans,element*(i-st.top()-1));
                }
                st.push(i);  // Push current index onto the stack
        }

        return ans;  // Return the maximum area found
        
        // Optimal Approach 1: Using Next Smaller Element (nse) & Previous Smaller Element (pse) calculation

        // vector<int> nse = nextSmallerElement(heights);  // Get next smaller elements
        // vector<int> pse = prevSmallerElement(heights);  // Get previous smaller elements

        // int ans = INT_MIN;  // Initialize the answer with minimum value
        // for(int i= 0 ;i<heights.size();i++){
        //     // Calculate the maximum area using heights and the difference between nse and pse
        //     ans = max(ans,heights[i]*(nse[i]-pse[i]-1));
        // }
        // return ans;  // Return the maximum area
    }
};
