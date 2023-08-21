class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
      // based upon the rotation https://leetcode.com/problems/repeated-substring-pattern/editorial/
        if (t.substr(1, t.size() - 2).find(s) != -1) return true;
        return false;
    }
};
