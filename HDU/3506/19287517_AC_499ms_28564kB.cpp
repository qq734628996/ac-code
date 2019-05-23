#include <bits/stdc++.h>

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
const int MAXN = 2e3+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,a[MAXN],S[MAXN],f[MAXN][MAXN],g[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        FOR(i,1,n) scanf("%d", &a[i]), a[i+n]=a[i];
        FOR(i,1,2*n) {
            S[i]=S[i-1]+a[i];
            g[i][i]=i;
        }
        FOR(len,1,n)FOR(i,1,2*n-len) {
            int j=i+len;
            int w=S[j]-S[i-1];
            f[i][j]=INF;
            FOR(k,g[i][j-1],g[i+1][j]) {
                if (f[i][j]>f[i][k]+f[k+1][j]+w) {
                    f[i][j]=f[i][k]+f[k+1][j]+w;
                    g[i][j]=k;
                }
            }
        }
        int ans=INF;
        FOR(i,1,n) ans=min(ans,f[i][i+n-1]);
        printf("%d\n", ans);
    }

    return 0;
}






































