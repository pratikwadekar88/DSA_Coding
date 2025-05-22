
int helper(int ind,int target,vector<int>&arr,vector<vector<int>> &dp,int &MOD){
	if(ind==-1) return target==0;
	if(dp[ind][target]!= -1) return dp[ind][target];
	int take=0,skip  = helper(ind-1,target,arr,dp,MOD);
	if(arr[ind]<=target) take = helper(ind-1,target-arr[ind],arr,dp,MOD);

	return dp[ind][target] = (take + skip)%MOD;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	int MOD = 1e9+7;
	vector<vector<int>> dp(n,vector<int> (k+1,0));
	// return helper(n-1,k,arr,dp,MOD);
	
	if(arr[0] <= k) dp[0][arr[0]] = 1;
	if (arr[0] == 0)dp[0][0] = 2;
    else dp[0][0] = 1;

	for(int ind=1;ind<n;ind++){
		for(int target=0;target<=k;target++){
			int skip = dp[ind-1][target];
			int take = arr[ind]<=target ?dp[ind-1][target-arr[ind]]:0;
			dp[ind][target] = (take+ skip)%MOD;
		}
	}
	return dp[n-1][k];
}
