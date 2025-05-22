

int LCSubStr(string &s1, string &s2)
{

    // Write your code here
    // int len1 = s1.length(), len2= s2.length();
    // int ans =0;
    // vector<vector<int>> dp(len1+1,vector<int> (len2+1,0));
    // for(int i=0;i<len1;i++)dp[i][0] = 0;
    // for(int i=0;i<len2;i++) dp[0][i]= 0;
    // for(int i=1;i<=len1;i++){
    //     for(int j=1;j<=len2;j++){
    //         if(s1[i-1]==s2[j-1]) {
    //             dp[i][j] = 1 + dp[i-1][j-1];
    //             ans = max(ans,dp[i][j]);
    //         }
    //         else dp[i][j] = 0;
    //     }
    // }
    // return ans;

    int len1 = s1.length(), len2= s2.length();
    int ans =0;
    vector<int> prev(len2+1,0),curr(len2+1,0);

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]) {
                curr[j] = 1 + prev[j-1];
                ans = max(ans,curr[j]);
            }
            else curr[j] = 0;
        }
        prev = curr;
    }
    return ans;

}

