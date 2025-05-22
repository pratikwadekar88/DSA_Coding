class Solution {
public:
    // int helper(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp){
    //     if(ind1<0 || ind2<0) return 0;

    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    //     if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]= 1+helper(ind1-1,ind2-1,s1,s2,dp); 
    //     return dp[ind1][ind2]=max(helper(ind1-1,ind2,s1,s2,dp),helper(ind1,ind2-1,s1,s2,dp));

    // }
    // Shifting index by 1.
    int helper(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp){
        if(ind1==0 || ind2==0) return 0;

        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2]= 1+helper(ind1-1,ind2-1,s1,s2,dp); 
        return dp[ind1][ind2]=max(helper(ind1-1,ind2,s1,s2,dp),helper(ind1,ind2-1,s1,s2,dp));

    }
    int longestCommonSubsequence(string s1, string s2) {

        int len1 = s1.length(), len2= s2.length();

        // vector<vector<int>> dp(len1,vector<int> (len2,-1));
        // return helper(s1.length()-1,s2.length()-1,s1,s2,dp);

        // vector<vector<int>> dp(len1+1,vector<int> (len2+1,-1));
        // return helper(s1.length(),s2.length(),s1,s2,dp);

        // vector<vector<int>> dp(len1+1,vector<int> (len2+1,0));

        // for(int i=0;i<len1;i++)dp[i][0] = 0;
        // for(int i=0;i<len2;i++) dp[0][i]= 0;

        // for(int i=1;i<=len1;i++){
        //     for(int j=1;j<=len2;j++){
        //         if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        //     }
        // }
        // return dp[len1][len2];

        vector<int> prev(len2+1,0),curr(len2+1,0);

        for(int i=0;i<len2;i++) prev[i]= 0;

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[len2];

    }
};