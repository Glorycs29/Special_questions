class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> indices;
        vector<int> ans;
        int i,j;
        for(i=0;i<nums.size();i++){
            if(nums[i]==key){
                indices.push_back(i);
            }
        }
        for(i=0;i<nums.size();i++){
            for(j=0;j<indices.size();j++){
                if(abs(i-indices[j]) <= k){
                    ans.push_back(i);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
