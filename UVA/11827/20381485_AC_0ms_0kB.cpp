#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e2+9, MAXM = 3e3+9;

LL gcd(LL a, LL b){ return b==0?a:gcd(b,a%b); }
LL a[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; cin>>T; cin.get();
    while (T--) {
        string buf; getline(cin,buf);
        stringstream ss(buf);
        bool first=true;
        int cnt=0;
        while (ss>>a[cnt]) cnt++;
        LL ans=1;
        REP(i,cnt)REP(j,i) ans=max(ans,gcd(a[i],a[j]));
        cout<<ans<<endl;
    }

    return 0;
}

































