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

char s[MAXN],t[MAXN];
int n,m,d[MAXN][MAXN];
string ans[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%s", s+1)==1) {
        n=m=strlen(s+1);
        memcpy(t,s,sizeof(s));
        reverse(t+1,t+1+m);
        FOR(i,0,n)FOR(j,0,n) ans[i][j]=" ";
        FOR(i,1,n)FOR(j,1,m) {
            if (s[i]==t[j]) {
                d[i][j]=d[i-1][j-1]+1;
                ans[i][j]=ans[i-1][j-1]+s[i];
            } else {
                d[i][j]=max(d[i-1][j], d[i][j-1]);
                if (d[i-1][j]>d[i][j-1]) ans[i][j]=ans[i-1][j];
                else if (d[i][j-1]>d[i-1][j]) ans[i][j]=ans[i][j-1];
                else ans[i][j]=min(ans[i-1][j], ans[i][j-1]);
            }
        }
        if (d[n][m]&1) {
            FOR(i,1,(d[n][m]+1)/2) cout<<ans[n][n][i];
            FOR(i,1,d[n][m]/2) cout<<ans[n][n][d[n][n]/2-i+1];
        } else {
            FOR(i,1,d[n][m]/2) cout<<ans[n][n][i];
            FOR(i,1,d[n][m]/2) cout<<ans[n][n][d[n][n]/2-i+1];
        }
        cout<<endl;
    }

    return 0;
}






































