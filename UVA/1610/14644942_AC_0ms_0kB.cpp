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
const int MAXN  = 1e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int n;
vector<string> V;
string str, ans;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (cin >> n, n) {
        V.clear();
        REP(i,n) { cin >> str; V.push_back(str); }
        sort(ALL(V));
        string &a = V[n/2-1], &b = V[n/2];
        ans.clear();
        bool flag = true;
        for (int d = 0; flag; d++) {
            ans.push_back('A');
            REP(i,26) {
                ans[d] = 'A'+i;
                if (a<=ans && ans<b) { flag = false; break; }
            }
            if (flag) ans[d] = d>=SZ(a) ? 'A' : a[d];
        }
        cout << ans << endl;
    }

    return 0;
}











































































