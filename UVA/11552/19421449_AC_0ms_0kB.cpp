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

int K,n,a[MAXN][33],d[MAXN][33];
char s[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &K,s);
        int len=strlen(s);
        n=len/K;
        REP(i,n) {
            REP(j,27) a[i][j]=0;
            REP(j,K) a[i][s[i*K+j]-'a']=1;
            REP(j,26) a[i][26]+=a[i][j];
        }
        REP(j,26) d[0][j]=a[0][j]?a[0][26]:INF;
        FOR(i,1,n-1)REP(j,26) {
            d[i][j]=INF;
            if (a[i][j]) {
                if (a[i][26]==1) {
                    REP(k,26) d[i][j]=min(d[i][j], d[i-1][k]+(k!=j));
                } else {
                    REP(k,26) d[i][j]=min(d[i][j], d[i-1][k]+a[i][26]-(k!=j&&a[i][k]));
                }
            }
        }
        int ans=INF;
        REP(i,26) ans=min(ans, d[n-1][i]);
        printf("%d\n", ans);
    }

    return 0;
}






































