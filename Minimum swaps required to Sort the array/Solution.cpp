class Solution 
{
    public:
    
    int minSwaps(vector<int>&a)
	{
	    int n = a.size();
	    vector<pair<int, int>> p;
	    for(int i = 0; i < n; i++){
	        p.push_back({a[i], i});
	    }
	    sort(p.begin(), p.end());
	    int swaps = 0;
	    for(int i = 0; i < n ; i++){
	        if(p[i].second == i) continue;
	        else{
	            swaps++;
	            swap(p[i],p[p[i].second]);
	            i--;
	        }
	    }
	    return swaps;
	}
};
