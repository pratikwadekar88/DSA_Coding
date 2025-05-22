


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int totalSum= 0;
	for(int it: arr) totalSum+= it;
	int k = totalSum/2;
	vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++) dp[i][0] = true;
    if(arr[0]<=k) dp[0][arr[0]] = true;

    for(int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool skip = dp[ind-1][target];
            bool take = false;
            if(target>=arr[ind]) take = dp[ind-1][target-arr[ind]];
            dp[ind][target] = (skip || take);
        }
    }
	int mn = INT_MAX;
	for(int i=1;i<=k;i++){
		if(dp[n-1][i]) mn = min(mn,abs(i-(totalSum-i)));
	}
	return mn!=INT_MAX?mn:totalSum;
}
