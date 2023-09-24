class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int n){
        long sum=0, max_sum=0;
        for(int i=0; i<k; i++) sum+=arr[i];
        max_sum=sum;
        for(int i=k; i<n ;i++){
            sum+=arr[i]-arr[i-k];
            max_sum = max(max_sum,sum);
        }
        return max_sum;
    }
};
