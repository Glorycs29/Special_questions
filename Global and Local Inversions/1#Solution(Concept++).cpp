class Solution {
public:
    bool isIdealPermutation(vector<int>& v) {
        int i;
        for(i=0; i<v.size(); i++)
        {
            if(v[i]==i)     
                continue;
            else if(v[i] == i-1)
                    continue;
            else if(v[i] == i+1)
                    continue;
                else
                    return false;
        }
       return true;       
    }
};
