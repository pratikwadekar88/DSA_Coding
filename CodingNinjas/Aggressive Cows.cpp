#include <vector>
#include <algorithm>

using namespace std;

// Helper function to check if we can place 'k' cows with at least 'minDis' distance between them
bool canWePlace(vector<int> &arr, int minDis, int k) {
    // Place the first cow in the first stall
    int last = arr[0];
    int cows = 1; // We have placed one cow

    // Try to place the rest of the cows
    for (int i = 1; i < arr.size(); i++) {
        // If the distance between the current stall and the last stall where a cow was placed is at least 'minDis'
        if (arr[i] - last >= minDis) {
            cows++; // Place another cow
            last = arr[i]; // Update the last stall where the cow was placed
        }

        // If we have placed 'k' cows, return true
        if (cows >= k)
            return true;
    }

    // If we couldn't place all cows with the required minimum distance, return false
    return false;
}

// Main function to find the largest minimum distance between cows
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();

    // Sort the stall positions to make the binary search possible
    sort(stalls.begin(), stalls.end());

    // The minimum possible distance is 1, and the maximum possible distance is the distance between the first and last stalls
    int low = 1;
    int high = stalls[n - 1] - stalls[0];

    // Perform binary search to find the maximum minimum distance
    while (low <= high) {
        // Try placing cows with a mid-point distance
        int minDis = (high - low) / 2 + low;

        // If it's possible to place cows with this minimum distance, try for a larger distance
        if (canWePlace(stalls, minDis, k)) {
            low = minDis + 1;
        } 
        // Otherwise, try for a smaller distance
        else {
            high = minDis - 1;
        }
    }

    // 'high' will contain the largest minimum distance where cows can still be placed
    return high;
}
