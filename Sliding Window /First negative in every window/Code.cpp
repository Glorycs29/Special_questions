#include<queue>

vector<int> firstNegative(vector<int> arr, int n, int k) {

    // Write your code here.

    queue<int> q;

    vector<int> ans;

    int start=0;

    int end=0;

    while(end<n){

        if(arr[end]<0) q.push(arr[end]);

        if(end-start+1<k){

            end++;

        }

        else if(end-start+1==k){

            if(q.empty()) ans.push_back(0);

            else{

                ans.push_back(q.front());

                if(arr[start]==q.front()) q.pop();

            }

            start++;

            end++;

        }

    }

    return ans;

}
