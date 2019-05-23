#include <bits/stdc++.h>
int main(){
    long long n,k,ans,p;
    while(~scanf("%lld%lld",&n,&k)){
        ans=0;
        for(int i=1,j;i<=n;i=j+1){
            p=k/i;
            j=p?std::min(k/p,n):n;
            ans+=(k%i+k%j)*(j-i+1)/2;
        }
        printf("%lld\n",ans);
    }
}