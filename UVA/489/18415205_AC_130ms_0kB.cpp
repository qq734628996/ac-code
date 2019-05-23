#include <bits/stdc++.h>
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
const int MAXN = 1e2+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int kase;
    while (~scanf("%d", &kase), ~kase) {
        printf("Round %d\n", kase);
        string s,t; cin>>s>>t;
        set<char> S;
        for (auto&i:s) S.insert(i);
        int cnt=0;
        for (auto&i:t) {
            if (S.count(i)) S.erase(i);
            else cnt++;
            if (!SZ(S) || cnt>=7) break;
        }
        if (!SZ(S)) puts("You win.");
        else if (cnt>=7) puts("You lose.");
        else puts("You chickened out.");
    }

    return 0;
}














































