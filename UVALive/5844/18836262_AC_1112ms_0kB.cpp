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
const int MAXN = 2e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int K;
string s,t;
map<char,string> mp;
bool dfs(int i, int j)
{
    if (i==SZ(s)) return j==SZ(t);
    if (mp.count(s[i])) {
        string& r=mp[s[i]];
        if (SZ(r)+j>SZ(t)) return false;
        REP(k,SZ(r)) if (r[k]!=t[j+k]) return false;
        return dfs(i+1,j+SZ(r));
    }
    FOR(k,1,K) {
        if (j+k>SZ(t)) break;
        mp[s[i]]=t.substr(j,k);
        if (dfs(i+1,j+k)) return true;
        mp.erase(s[i]);
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &K);
        cin>>s>>t;
        mp.clear();
        printf("%d\n", dfs(0,0));
    }

    return 0;
}









































