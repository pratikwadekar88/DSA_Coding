class Solution {
public:
    /*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]*/
    void generate(vector<int> &candidates,vector<vector<int>> &ans ,int target,vector<int> &ds,int ind){
        //We are subtracting element as recursive calls get execute
        //When target becomes zero we call add subarray into answer
        if(target==0){
            ans.push_back(ds);
            return;
        }
        //If target goes below 0 then we will return from there
        if(target<0)
            return;
        //We are not adding element if it is duplicate
        //We take the element which is first on all funtion calls
        for(int i=ind;i<candidates.size();i++){
            //if i!=ind i.e if it is starting element we are adding it to ds
            if(i!=ind && candidates[i]==candidates[i-1]) continue;
            ds.push_back(candidates[i]);
            generate(candidates,ans,target-candidates[i],ds,i+1);
            //As we are backtracking , we are removing the element while returning from the function call
            ds.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans ;
        //We are sorting the array so that we can avoid duplicate ssubsets
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        generate(candidates,ans,target,ds,0);
        return ans;
    }
};
