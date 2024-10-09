#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' returns "true" if the person having
	id 'A' knows the person having id 'B' in the party, and "false" otherwise.
*/

// Helper function to check if 'p' is a celebrity.
bool checkifcelebrity(int p, int n) {
    for (int i = 0; i < n; i++) {
        if (p == i) 
            continue; // Skip if the person is themselves.
        
        // If 'p' knows 'i', then 'p' cannot be a celebrity.
        if (knows(p, i)) 
            return false;
        
        // If 'i' does not know 'p', then 'p' cannot be a celebrity.
        if (!knows(i, p)) 
            return false;
    }
    // If both conditions are satisfied, 'p' is a celebrity.
    return true;
}

int findCelebrity(int n) {
    int top = 0, down = n - 1;

    // Reduce the candidate pool using two pointers.
    while (top < down) {
        if (knows(top, down)) {
            // If 'top' knows 'down', 'top' can't be a celebrity.
            top++; 
        } else if (knows(down, top)) {
            // If 'down' knows 'top', 'down' can't be a celebrity.
            down--;
        } else {
            // In case neither knows the other, check both.
            // If 'top' is a celebrity, return 'top'.
            if (checkifcelebrity(top, n)) 
                return top;
            // If 'down' is a celebrity, return 'down'.
            if (checkifcelebrity(down, n)) 
                return down;
            
            // Otherwise, continue reducing the range.
            top++;
            down--;
        }
    }

    // After narrowing down, check the remaining candidate ('top') for celebrity.
    if (checkifcelebrity(top, n)) 
        return top;

    // If no celebrity is found, return -1.
    return -1;
}
