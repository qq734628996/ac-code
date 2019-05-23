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
const int MAXN = 1e2+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 2520;

int m,n,tme,vis[MAXN][MAXN][3],a[MAXN][MAXN],b[MAXN][MAXN];
char s[MAXN][MAXN];
#define vld(i,j) (0<=i&&i<m&&0<=j&&j<n)
const int r[]={0,1,0,-1};
const int c[]={1,0,-1,0};
struct node {
    int x,y,t,st;
};

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d%d", &m,&n,&tme);
        REP(i,m) scanf("%s", s[i]);
        int sx,sy;
        REP(i,m)REP(j,n) {
            if (s[i][j]=='D') {
                a[i][j]=kase;
                REP(k,4) {
                    int x=i, y=j;
                    while (true) {
                        x+=r[k];
                        y+=c[k];
                        if (!vld(x,y) || s[x][y]=='X' || s[x][y]=='E') break;
                        a[x][y]=kase;
                    }
                }
            }
            if (s[i][j]=='E') {
                b[i][j]=kase;
                REP(k,4) {
                    int x=i, y=j;
                    while (true) {
                        x+=r[k];
                        y+=c[k];
                        if (!vld(x,y) || s[x][y]=='X' || s[x][y]=='D') break;
                        b[x][y]=kase;
                    }
                }
            }
            if (s[i][j]=='S') sx=i, sy=j, s[i][j]='.';
        }
        queue<node> Q;
        Q.push((node){sx,sy,0,0});
        vis[sx][sy][0]=kase;
        int ans=-1;
        while (!Q.empty()) {
            node t=Q.front(); Q.pop();
            if (t.t>tme) break;
            int i=t.x, j=t.y;
            if (t.st!=1 && a[i][j]==kase) t.st+=1;
            if (t.st!=2 && b[i][j]==kase) t.st+=2;
            if (t.st==3) { ans=t.t; break; }
            REP(k,4) {
                int x=i+r[k], y=j+c[k];
                if (vld(x,y) && s[x][y]=='.' && vis[x][y][t.st]!=kase) {
                    vis[x][y][t.st]=kase;
                    Q.push((node){x,y,t.t+1,t.st});
                }
            }
        }
        printf("Case %d:\n%d\n", kase,ans);
    }

	return 0;
}










































