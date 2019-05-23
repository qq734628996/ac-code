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
const int MAXN = 1e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,a[MAXN],b[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,n) scanf("%d", &a[i]);
        REP(i,n) scanf("%d", &b[i]);
        sort(a,a+n);
        sort(b,b+n);
        vector<int> V;
        int ans=0;
        REP(i,n) {
            int j=lower_bound(b,b+n-i+SZ(V),a[i])-b;
            if (j>0) {
                ans++;
                FOR(k,j-1,n-i+SZ(V)-2) swap(b[k],b[k+1]);
            } else if (b[j]==a[i]) V.pb(a[i]);
            else ans--;
        }
        map<int,int> mp;
        REP(i,SZ(V)) mp[b[i]]++;
        REP(i,SZ(V)) {
            if (!mp.count(V[i])) ans--;
            else if (--mp[V[i]]==0) mp.erase(V[i]);
        }
        printf("%d\n", ans*200);
    }

    return 0;
}









































