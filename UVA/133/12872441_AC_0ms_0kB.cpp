#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(typeof(x.begin()) e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define MAXN 1024
typedef long long LL;
const int INF = ~0U>>1, MOD = ~0U>>1;

void go(int *a,int& id,int n,int len,int dir)
{
    while(len--)while(a[(id=(id+dir+n)%n)]);
}

int main()
{
    int N,k,m,a[20];
    while (cin>>N>>k>>m,N){
        memset(a,0,sizeof(a));
        int id1=-1,id2=N,left=0;
        while (left<N) {
            go(a,id1,N,k, 1);
            go(a,id2,N,m,-1);
            printf("%3d",id1+1);left++;
            if (id1!=id2) {printf("%3d",id2+1);left++;}
            if (left < N) printf(",");
            a[id1]=a[id2]=1;
        }
        puts("");
    }
}