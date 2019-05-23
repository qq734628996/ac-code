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
const int MAXN  = 1e4+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, a[MAXN];
vector<pii> ans;

void Swap(int l, int r)
{
    int mi = l+(r-l)/2+1;
        //DEBUG(l) DEBUG(r) DEBUG(mi)
    while (mi <= r) swap(a[mi++], a[l++]);
    //FOR(i,1,n) printf("%d ", a[i]); puts("");
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]);
        ans.clear();
        FOR(i,1,n) {
            int j = i-1;
            while (a[++j] != i);
            if (j != i) {
                int mi = i + (n-i+1)/2;
                if (j > mi) {
                    Swap(2*mi-j+1, j);
                    ans.push_back(pii(2*mi-j+1, j));
                } else if (j < mi) {
                    Swap(j, 2*mi-j-1);
                    ans.push_back(pii(j, 2*mi-j-1));
                }
                Swap(i, 2*mi-i-1);
                ans.push_back(pii(i, 2*mi-i-1));
            }
        }
        printf("%d\n", SZ(ans));
        REP(i,SZ(ans)) printf("%d %d\n", ans[i].first, ans[i].second);
    }

    return 0;
}











































































