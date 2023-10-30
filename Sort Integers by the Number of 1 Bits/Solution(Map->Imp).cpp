class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        //__builtin_popcount(num);
        
        map<int,vector<int>> ff;
        for(auto &it : arr){
           int x = __builtin_popcount(it);
           ff[x].push_back(it);
        }
        
        vector<int> ans;
        for(auto &it : ff){
            vector<int> temp;
            for(auto &val : it.second){
               temp.push_back(val);
            }
            sort(temp.begin(),temp.end());
            for(auto &e : temp){
                ans.push_back(e);
            }
        }
        return ans;

    }
};
