#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    // Get the size of the input array
    int n = arr.size();

    // Initialize variables:
    // 'xr' will store the XOR of elements from the start to the current position
    // 'mpp' is a map to store the frequency of different XOR values
    // 'cnt' counts the number of subarrays whose XOR equals 'x'
    int xr = 0;
    map<int, int> mpp;
    int cnt = 0;

    // Iterate over each element in the array
    for (int i = 0; i < n; i++) {
        // Update the cumulative XOR 'xr' by XORing it with the current element
        xr ^= arr[i];

        // If 'xr' equals 'x', increment the count of valid subarrays
        if (xr == x) {
            cnt++;
        }

        // Compute the XOR value that we need to find in the map
        int diff = xr ^ x;

        // If this 'diff' value exists in the map, it means there are subarrays
        // ending at the current index whose XOR equals 'x'
        if (mpp.find(diff) != mpp.end()) {
            cnt += mpp[diff];
        }

        // Update the map with the current XOR value 'xr':
        // If 'xr' is already in the map, increment its count
        // Otherwise, initialize its count to 1
        if (mpp.find(xr) != mpp.end()) {
            mpp[xr]++;
        } else {
            mpp[xr] = 1;
        }
    }

    // Return the total count of subarrays whose XOR equals 'x'
    return cnt;
}
