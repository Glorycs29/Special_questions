class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int up=0,left=0,right=m-1,down=n-1;
 		int i, count=1;
 		while(left<=right && up<=down){
            for(i=left;i<=right;i++){
                if(count==k){
                    return a[up][i];
                }
                count++;
            }
            up++;
            for(i=up;i<=down;i++){
                if(count==k){
                    return a[i][right];
                }
                count++;
            }
            right--;
            if(up<=down){
                for(i=right;i>=left;i--){
                    if(count==k){
                        return a[down][i];
                    }
                    count++;
                }
                down--;
            }
            if(left<=right){
                for(i=down;i>=up;i--){
                    if(count==k){
                        return a[i][left];
                    }
                    count++;
                }
                left++;
            }
        }
    }
};

