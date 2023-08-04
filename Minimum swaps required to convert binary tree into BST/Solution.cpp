class Solution{
  public:
  
    vector <int> in;
    void inorder(vector <int> &a,int i){
        if(i >= a.size()) return;
        inorder(a,2*i+1);
        in.push_back(a[i]);
        inorder(a,2*i+2);
    }
    int minSwaps(vector<int>&a, int n){
        inorder(a,0);
        vector <pair<int,int>> v;
        for(int i = 0;i < n;i++) v.push_back({in[i],i});
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(i != v[i].second){
                swap(v[i],v[v[i].second]);
                i--; ans++;
            }
        }
        return ans;
    }
};
