#include <bits/stdc++.h> 
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.

    int totalSum=0;
	int MOD = 1e9+7;
    for(int it: arr) totalSum+=it;
	if(totalSum-d <0 || (totalSum-d)%2) return 0;
	int k= (totalSum-d)/2;
	vector<vector<int>> dp(n,vector<int> (k+1,0));
	
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
    int ans =0;
    for(int i=0;i<=k;i++){
        if(((totalSum-i)-i)==d) ans = (ans+dp[n-1][i])%MOD;
    }
    return ans;
}


