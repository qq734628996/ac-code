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

int n,m,a[333],w[333][333],d[333][33];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&m)==2) {
        FOR(i,1,n) scanf("%d", &a[i]);
        memset(w,0,sizeof(w));
        FOR(i,1,n)FOR(j,i+1,n) w[i][j]=w[i][j-1]+a[j]-a[(i+j)/2];
        memset(d,INF,sizeof(d));
        FOR(i,1,n) d[i][1]=w[1][i];
        FOR(j,2,m)FOR(i,j,n)FOR(k,j-1,i-1) {
            d[i][j]=min(d[i][j], d[k][j-1]+w[k+1][i]);
        }
        printf("%d\n", d[n][m]);
    }

    return 0;
}






































