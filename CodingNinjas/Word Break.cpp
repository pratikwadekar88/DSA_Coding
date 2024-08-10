#include <bits/stdc++.h>

// Function to check if a given substring is present in the dictionary
bool isPresent(string s, vector<string> &dict) {
    for (auto &i : dict) { // Iterate through each word in the dictionary
        if (i == s) // If the substring matches a word in the dictionary
            return true; // Return true if found
    }
    return false; // Return false if not found
}

// Recursive function to build possible sentences
void solve(vector<string> &ans, string sen, vector<string> &dict, string &s, int ind, int n) {
    // Base case: if the index reaches the end of the string
    if (ind == n) {
        ans.push_back(sen); // Add the constructed sentence to the result list
        return; // End the recursion
    }
    
    // Iterate over the string starting from the current index
    for (int i = ind; i < n; i++) {
        string word = s.substr(ind, i - ind + 1); // Extract the substring from ind to i
        if (isPresent(word, dict)) { // Check if the substring is a valid word in the dictionary
            // If sen is empty, add the word; otherwise, add a space before adding the word
            string new_sen = sen.empty() ? word : sen + " " + word;
            // Recursively build the sentence with the next part of the string
            solve(ans, new_sen, dict, s, i + 1, n);
        }
    }
}

// Main function to find all possible sentences by breaking the string using the dictionary
vector<string> wordBreak(string &s, vector<string> &dictionary) {
    vector<string> ans; // Vector to store the resulting sentences
    solve(ans, "", dictionary, s, 0, s.size()); // Start the recursive process
    return ans; // Return the list of constructed sentences
}
