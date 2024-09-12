/*
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        vector<int> letters(26,0);
        for(auto i: allowed)letters[i-'a']++;
        int ans=0;
        bool flag = true;
        for(auto word: words){
            flag = true;
            for(auto ch : word){
                if(letters[ch-'a']==0){
                    flag = false;
                    break;
                }
            }
            if(flag)ans++;
        }
        return ans;
    }
};
