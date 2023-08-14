    void sort012(int a[], int n)
    {
         int high=n-1 , low = 0,mid = 0;
        for(int i =0 ; i<n;i++){
            while(mid<=high){
                if(a[mid] == 1){
                    mid++;
                }else if(a[mid] == 0){
                    swap(a[mid] , a[low]);
                    mid++;
                    low++;
                }else{
                    swap(a[mid] , a[high]);
                    
                    high--;
                }
            }
        }
        return;
    }
