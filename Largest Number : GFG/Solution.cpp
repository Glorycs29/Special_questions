class Solution{
public:
    string findLargest(int N, int S){
        if((S==0 && N>1) || (S > 9*N)){
            return "-1";
        }
        
        string Num="";
        
        for(int i=N-1; i>=0; i--){
            int largestDig = 9;
            if(S>=9){
                largestDig = 9;
            }else{
                largestDig = S;
            }
            
            Num += to_string(largestDig);
            S -= largestDig;
        }
        return Num;
    }
};
