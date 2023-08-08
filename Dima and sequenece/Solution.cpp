#include <bits/stdc++.h>
using namespace std;
int n, a;
int cnt[32];
int main(){
cin>>n;

// f(1)=1,f(2)=1,f(3)=2,f(4)=1,f(5)=2,f(6)=2,f(7)=3,f(8)=1,f(9)=2,....

long long ans=0;
while(n--){
cin>>a;
a=__builtin_popcount(a);
ans+=cnt[a];
cnt[a]++;
}
cout<<ans<<'\n';
}
