#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 205, INF = ~0U>>1, MOD = ~0U>>1, EPS = 1e-8;

int n,m;
vector<pair<int,int> >E[MAXN];
int d[MAXN],inq[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n,&m)) {
        REP(i,n)E[i].clear();
        REP(i,n)d[i]=1e9;
        REP(i,n)inq[i]=0;

        while (m--) {
            int x,y,z;scanf("%d%d%d", &x,&y,&z);
            E[x].push_back(make_pair(y,z));
            E[y].push_back(make_pair(x,z));
        }

        int s,t;scanf("%d%d",&s,&t);

        queue<int> Q;
        Q.push(s),d[s]=0,inq[s]=1;
        while (!Q.empty()) {
            int t = Q.front(); Q.pop();
            REP(i,SZ(E[t]))if(d[E[t][i].first] > d[t] + E[t][i].second) {
                d[E[t][i].first] = d[t]+E[t][i].second;
                if (inq[E[t][i].first]) continue;
                Q.push(E[t][i].first);
            }
        }

        printf("%d\n", d[t]==1e9 ? -1 : d[t]);
    }

    return 0;
}

































