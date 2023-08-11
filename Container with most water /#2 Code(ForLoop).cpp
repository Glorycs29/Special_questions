const int _ = [](){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();

class Solution {
public:
  int maxArea(vector<int>& height) {
    int result = 0;
    for(int i = 0, j = height.size() - 1; i < j; ) {
      result = max(result, min(height[i], height[j]) * (j - i));
      if(height[i] > height[j]) j--;
      else i++;
    }
    return result;
  }
  
};
