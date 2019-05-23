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

LL a[22],d[22][2];
LL dp(int pos, int if4, bool limit)
{
    if (pos==-1) return 1;
    LL& r=d[pos][if4];
    if (!limit && ~r) return r;
    LL ans=0;
    int up=limit?a[pos]:9;
    FOR(i,0,up) {
        if (if4 && i==9) continue;
        ans+=dp(pos-1,i==4,limit&&i==up);
    }
    if (!limit) r=ans;
    return ans;
}
LL solve(LL x)
{
    LL y=x;
    int cnt=0;
    while (x) {
        a[cnt++]=x%10;
        x/=10;
    }
    return y-dp(cnt-1,false,true);
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
        LL L=1, R; scanf("%lld", &R);
        printf("%lld\n", solve(R)-solve(L-1));
    }

    return 0;
}









































