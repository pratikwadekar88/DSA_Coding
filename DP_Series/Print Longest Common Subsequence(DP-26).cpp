#include<bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(string s1, string s2) {

        int len1 = s1.length(), len2= s2.length();

        vector<vector<int>> dp(len1+1,vector<int> (len2+1,0));

        for(int i=0;i<len1;i++)dp[i][0] = 0;
        for(int i=0;i<len2;i++) dp[0][i]= 0;

        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i=len1,j=len2;
        string ans = "";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]) {
                ans = s1[i-1]+ ans;
                i--;
                j--;
            }
            else {
                if(dp[i-1][j]==dp[i][j]) i--;
                else j--;
            }
        }
        cout<<ans<<endl;

    }


int main(){
   longestCommonSubsequence("abcde","ace");
    return 0;
}