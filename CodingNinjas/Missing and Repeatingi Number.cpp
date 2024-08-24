#include <bits/stdc++.h>

// Function to find the missing and repeating numbers in the array
pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Optimal Approach 1: Bit Manipulation

    int xr = 0;

    // Step 1: XOR all array elements with all numbers from 1 to n
    // The result will be the XOR of the missing number and the repeating number
    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];   // XOR with the element in the array
        xr = xr ^ (i + 1);  // XOR with the number from 1 to n
    }

    // Step 2: Find the rightmost set bit in the XOR result
    // This bit will help us differentiate between the missing and repeating numbers
    int number = xr & ~(xr - 1);

    int zero = 0; // Will hold the XOR result of one group
    int one = 0;  // Will hold the XOR result of the other group

    // Step 3: Divide the numbers into two groups and XOR them separately
    for (int i = 0; i < n; i++) {
        if ((arr[i] & number) != 0) {
            one = one ^ arr[i];  // XOR the elements where the set bit is 1
        } else {
            zero = zero ^ arr[i];  // XOR the elements where the set bit is 0
        }
    }

    // XOR the numbers from 1 to n in the respective groups
    for (int i = 1; i <= n; i++) {
        if ((i & number) != 0) {
            one = one ^ i;  // XOR the numbers where the set bit is 1
        } else {
            zero = zero ^ i;  // XOR the numbers where the set bit is 0
        }
    }

    // Step 4: Determine which is the missing number and which is the repeating number
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == zero) cnt++;  // Count how many times 'zero' appears in the array
    }

    // If 'zero' appears twice, then it's the repeating number and 'one' is the missing number
    if (cnt == 2) return {one, zero};

    // Otherwise, 'zero' is the missing number and 'one' is the repeating number
    return {zero, one};



    // Optimal Approach 2: Mathematical Approach (Commented Out)

    // long long sn1 = (n * (n + 1)) / 2;
    // long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6;

    // long long sum1 = 0;
    // long long sum2 = 0;

    // for (int i = 0; i < n; i++) {
    //     sum1 += arr[i];  // Sum of elements in the array
    //     sum2 += (long long)arr[i] * (long long)arr[i];  // Sum of squares of elements in the array
    // }

    // long long val1 = sum1 - sn1;   // x - y
    // long long val2 = sum2 - sn2;

    // val2 = val2 / val1;  // x + y

    // long long x = (val1 + val2) / 2;
    // long long y = x - val1;

    // return {(int)y, (int)x};
}
