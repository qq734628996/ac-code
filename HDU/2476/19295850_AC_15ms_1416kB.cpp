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
const int MAXN = 1e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

char s[MAXN],t[MAXN];
int d[MAXN][MAXN],ans[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%s%s", s,t)==2) {
        int len=strlen(s);
        REP(j,len)ROF(i,0,j) {
            d[i][j]=d[i+1][j]+1;
            FOR(k,i+1,j) if (t[i]==t[k]) d[i][j]=min(d[i][j],d[i+1][k]+d[k+1][j]);
        }
        REP(i,len) {
            ans[i]=d[0][i];
            if (s[i]==t[i]) ans[i]=i?ans[i-1]:0;
            else {
                FOR(j,0,i-1) ans[i]=min(ans[i],ans[j]+d[j+1][i]);
            }
        }
        printf("%d\n", ans[len-1]);
    }

    return 0;
}






































