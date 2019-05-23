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
const int MAXN = 1e3+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

LL n,v,X,x[MAXN],S[MAXN],d[MAXN][MAXN][2];
pii p[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%lld%lld%lld", &n,&v,&X)==3) {
        FOR(i,1,n) scanf("%d%d", &p[i].fi,&p[i].se);
        sort(p+1,p+n+1);
        FOR(i,1,n) S[i]=S[i-1]+p[i].se, x[i]=p[i].fi;
        FOR(i,1,n) d[i][i][0]=d[i][i][1]=abs(X-x[i])*S[n];
        FOR(len,1,n)FOR(i,1,n-len) {
            int j=i+len;
            LL t1=(S[n]-(S[j]-S[i]));
            d[i][j][0]=min(d[i+1][j][0]+(x[i+1]-x[i])*t1,
                           d[i+1][j][1]+(x[j]-x[i])*t1);
            LL t2=(S[n]-(S[j-1]-S[i-1]));
            d[i][j][1]=min(d[i][j-1][0]+(x[j]-x[i])*t2,
                           d[i][j-1][1]+(x[j]-x[j-1])*t2);
        }
        printf("%d\n", min(d[1][n][0], d[1][n][1])*v);
    }

    return 0;
}






































