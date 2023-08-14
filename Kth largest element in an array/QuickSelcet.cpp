class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums,k);
    }

    int quickSelect(vector<int>& nums, int k){
        int pivot = nums[rand()%nums.size()];
        vector<int> left, right, mid;

         for (int num: nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        
        if(k <= left.size()){
            return quickSelect(left,k);
        }
        if(k > left.size() + mid.size()){
            return quickSelect(right, k-left.size()-mid.size());
        }
        return pivot;
    }
};
