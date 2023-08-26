class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ngl(n), ngr(n);

        ngl[0] = height[0];
        ngr[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            ngl[i] = max(height[i], ngl[i-1])+ 0ll;
        }

        for(int i=n-2; i>=0; i--){
            ngr[i] = max(height[i], ngr[i+1]) + 0ll;
        }
        int ans =0ll; 
        for(int i=0; i<n; i++){
            ans+= min(ngl[i],ngr[i]) - height[i];
        }
        return ans;
    }
};
