/*You are given an integer n indicating there are n specialty retail stores. There are m product types of varying amounts, which are given as a 0-indexed integer array quantities, where quantities[i] represents the number of products of the ith product type.

You need to distribute all products to the retail stores following these rules:

A store can only be given at most one product type but can be given any amount of it.
After distribution, each store will have been given some number of products (possibly 0). Let x represent the maximum number of products given to any store. You want x to be as small as possible, i.e., you want to minimize the maximum number of products that are given to any store.
Return the minimum possible x.*/


//This question similar to Aggressive cows

class Solution {
public:

    // Helper function to calculate how many stores are required if no store gets more than 'q' items.
    int isPossible(vector<int> &arr, int q, int n) {
        int count = 0;
        
        // Loop through each quantity in the array and calculate how many stores are needed
        // to accommodate all items with a maximum of 'q' items per store.
        for (int i = 0; i < arr.size(); i++) {
            // For each quantity, calculate how many stores are needed (using ceiling division).
            count += (ceil((double)arr[i] / (double)q));
        }

        // Return the total number of stores required.
        return count;
    }

    // Main function to minimize the maximum number of items any store can receive.
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        // Initialize the search range for binary search.
        int low = 1, high = INT_MIN;

        // Set 'high' to the maximum quantity in the 'quantities' array, as the upper limit.
        for (int i = 0; i < quantities.size(); i++) {
            high = max(high, quantities[i]);
        }
    
        // Perform binary search to find the minimized maximum.
        while (low <= high) {
            // Calculate the mid-point of the current search range.
            int mid = (high - low) / 2 + low;

            // Check how many stores would be needed if no store received more than 'mid' items.
            int cnt = isPossible(quantities, mid, n);

            // If more stores are needed than available ('n'), increase the minimum possible max value.
            if (cnt > n) {
                low = mid + 1;
            }
            // Otherwise, try a smaller max value.
            else {
                high = mid - 1;
            }
        }

        // Return the minimized maximum number of items any store can receive.
        return low;
    }
};
