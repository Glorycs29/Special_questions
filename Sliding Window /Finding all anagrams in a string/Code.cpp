class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int s_len=s.length();
        int p_len=p.length();

        vector<int> freq(26,0);
        vector<int> window(26,0);

        //base case
        if(p_len>s_len)return ans;

        for(int i=0;i<p_len;i++){
            freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        //first window
        if(freq==window)ans.push_back(0);

        for(int i=p_len; i<s_len;i++){
            window[s[i-p_len]-'a']--;
            window[s[i]-'a']++;
            if(freq==window) ans.push_back(i-p_len+1);
        }


        return ans;
    }
};
