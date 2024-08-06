class Solution {
public:
/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

*/
    //
    void generate(vector<int> &arr,int ind,vector<int> ds,int sum,vector<vector<int>> & ans,int target){
        
        //This is the base condition if ind reaches to zero recursion will end and
        //if sum will be 0 then we will store the answer
        if(ind==arr.size()){
            if(sum==0){
                ans.push_back(ds);
            }
            return ;
        }
        //If we keep adding same ind element multiple times we will add it until it reaches to sum
        //we will add that element in ds and call generate function
        if(arr[ind]<=sum){
            ds.push_back(arr[ind]);
            generate(arr,ind,ds,sum-arr[ind],ans,target);
            //As recursion call overs, we have to pop that element
            ds.pop_back();
        }
        //If we done with same element we will move to next element in the array
        //we will call function for ind+1

        generate(arr,ind+1,ds,sum,ans,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        generate(candidates,0,ds,target,ans,target);
        return ans;
    }
};
