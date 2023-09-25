class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        if(n1>n2)return false;

         sort(s1.begin(),s1.end());

         for(int i=0;i<n2-n1+1;i++){
        //     //take substring of size n1 from s2 string staring from i to n1 length
             string str=s2.substr(i,n1);
             //now sort the substring
             sort(str.begin(),str.end());

             if(str==s1){
                 return true;
             }
         }
         return false;
    }

};
