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
const int MAXN  = 8e5, INF = ~0U>>1, MOD = ~0U>>1;



int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    string s;
    int n;
    cin >> s >> n;
    set<string> S;
    for (int i = 0; i < SZ(s); i++) {
        for (int j = 1; j+i <= SZ(s); j++) {
            S.insert(s.substr(i,j));
            if (SZ(S) > n) {
                auto it = --S.end();
                string tmp = *it;
                S.erase(--S.end());
                if (tmp == string(s.substr(i,j))) break;
            }
        }
    }
    auto it = --S.end();
    cout << *it << endl;

    return 0;
}
















































































