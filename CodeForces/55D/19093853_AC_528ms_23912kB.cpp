//#include <bits/stdc++.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 2520;

LL a[22],d[22][MOD][55],id[MOD+5];
void init()
{
    int cnt=0;
    FOR(i,1,MOD) if (MOD%i==0) id[i]=cnt++;
    memset(d,-1,sizeof(d));
}
int gcd(int m, int n) { return n==0?m:gcd(n,m%n); }
int lcm(int m, int n) { return m/gcd(m,n)*n; }
LL dp(int pos, int psum, int plcm, bool limit)
{
    if (pos==-1) return psum%plcm==0;
    LL& r=d[pos][psum][id[plcm]];
    if (!limit && ~r) return r;
    LL ans=0;
    int up=limit?a[pos]:9;
    FOR(i,0,up) {
        int nsum=(psum*10+i)%MOD;
        int nlcm=plcm;
        if (i) nlcm=lcm(plcm,i);
        ans+=dp(pos-1,nsum,nlcm,limit&&i==up);
    }
    if (!limit) r=ans;
    return ans;
}
LL solve(LL x)
{
    int cnt=0;
    while (x) {
        a[cnt++]=x%10;
        x/=10;
    }
    return dp(cnt-1,0,1,true);
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    init();
    int T; cin>>T;
    while (T--) {
        LL L,R; cin>>L>>R;
        cout<<solve(R)-solve(L-1)<<endl;
    }

    return 0;
}









































