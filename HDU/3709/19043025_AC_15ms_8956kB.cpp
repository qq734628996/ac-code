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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

LL a[22],d[22][22][2000];
LL dp(int pos, int mi, int sum, bool limit)
{
    if (pos==-1) return !sum;
    if (sum<0) return 0;
    LL& r=d[pos][mi][sum];
    if (!limit && ~r) return r;
    LL ans=0;
    int up=limit?a[pos]:9;
    FOR(i,0,up) {
        ans+=dp(pos-1,mi,sum+i*(pos-mi),limit&&i==up);
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
    LL ans=0;
    REP(i,cnt) ans+=dp(cnt-1,i,0,true);
    return ans-(cnt-1);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    memset(d,-1,sizeof(d));
    int T; scanf("%d", &T);
    while (T--) {
        LL L,R; scanf("%lld%lld", &L,&R);
        printf("%lld\n", solve(R)-solve(L-1));
    }

    return 0;
}









































