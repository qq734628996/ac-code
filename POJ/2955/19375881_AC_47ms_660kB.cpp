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
const int MAXN = 1e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

char s[MAXN];
int n,a[MAXN],d[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%s", s+1)==1 && s[1]!='e') {
        n=strlen(s+1);
        FOR(i,1,n) {
            switch (s[i]) {
                case '(': a[i]=-2; break;
                case '[': a[i]=-1; break;
                case ']': a[i]=1; break;
                case ')': a[i]=2; break;
            }
        }
        FOR(len,1,n)FOR(i,1,n-len) {
            int j=i+len;
            d[i][j]=d[i+1][j-1];
            if (a[i]<0 && a[i]+a[j]==0) d[i][j]+=2;
            FOR(k,i,j) d[i][j]=max(d[i][j], d[i][k]+d[k+1][j]);
        }
        printf("%d\n", d[1][n]);
    }

    return 0;
}






































