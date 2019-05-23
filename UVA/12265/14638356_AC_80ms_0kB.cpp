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
typedef pair<int, int> pii;
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, m, h[MAXN], ans[MAXN<<2];
char s[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        REP(i,n) scanf("%s", s[i]);
        memset(h, 0, sizeof(h));
        memset(ans, 0, sizeof(ans));
        REP(i,n) {
            REP(j,m) h[j] = (s[i][j] == '#' ? 0 : h[j] + 1);
            //SHOW1(h,m)
            stack<pii> S;
            REP(j,m) {
                if (!h[j]) while (!S.empty()) S.pop();
                else {
                    pii tmp(0,0);
                    while (!S.empty() && S.top().second > h[j]) tmp = S.top(), S.pop();
                    if (tmp.first || tmp.second) {
                        tmp.second = h[j];
                        if (S.empty() || S.top().second-S.top().first < tmp.second-tmp.first)
                            S.push(tmp);
                    }
                    if (S.empty() || S.top().second-S.top().first < h[j]-j)
                        S.push(pii(j, h[j]));
                //printf("c=%d,h=%d,j=%d\n", S.top().first, S.top().second, j);
                    ans[2*(j-S.top().first+1+S.top().second)]++;
                }
            }
        }
        FOR(i,1,(n+m)*2)if(ans[i])printf("%d x %d\n", ans[i], i);
    }

    return 0;
}











































































