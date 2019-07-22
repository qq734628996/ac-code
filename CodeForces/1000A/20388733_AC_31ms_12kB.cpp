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

int n;
string s[MAXN],t[MAXN];
bool cmp(string& i, string& j)
{
    if (SZ(i)!=SZ(j)) return SZ(i)<SZ(j);
    return i<j;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    cin>>n;
    REP(i,n) cin>>s[i];
    REP(i,n) cin>>t[i];
    sort(s,s+n);
    sort(t,t+n);
    int ans=0;
    map<string,int> mp;
    int cnt=0;
    REP(i,n) {
        if (SZ(s[i])==1) {
            cnt++;
            mp[s[i]]++;
            mp[t[i]]--;
        } else if (s[i]!=t[i]) ans++;
    }
    for (auto& i:mp) if (i.se>0) ans+=i.se;
    printf("%d\n", ans);

    return 0;
}

































