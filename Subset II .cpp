class Solution {
public:
/* 
Subset II Leetcode #90
    Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
 */
    //This function is written for recursion
    void generate(vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans,int ind){
        // At each function call we are adding subarray ro our answer
        //because ans is generated at each level
        //first level -> 0 length subarr
        //second level -> 1 length & so on
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            //At first we take element
            //after that if there is duplicate element we skip it
            //This is important point here
            if(i!=ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            generate(nums,temp,ans,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //First we need to sort array to identify duplicates
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        generate(nums,temp,ans,0);
        return ans;

    }
};
