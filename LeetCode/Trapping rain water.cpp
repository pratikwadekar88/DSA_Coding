class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> leftmax(height.size(),height[0]);
        vector<int> rightmax(height.size(),height[height.size()-1]);
        int mx = INT_MIN;
        for(int i=1;i<height.size();i++) {
            leftmax[i] = max(height[i],leftmax[i-1]);
            }
        mx = INT_MIN;
        for(int i=height.size()-2;i>=0;i--) {
            rightmax[i] = max(height[i],rightmax[i+1]);
            }

        int ans=0;
        for(int i=0;i<height.size();i++) {
            ans+= min(leftmax[i],rightmax[i])-height[i];
        }

        return ans;

        
    }
};
