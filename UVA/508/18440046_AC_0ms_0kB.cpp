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

int dis(string s, string t)
{
    if (SZ(s)>SZ(t)) swap(s,t);
    if (s==t.substr(0,SZ(s))) return SZ(t)-SZ(s);
    return INF;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    string s,t;
    map<char, string> dic;
    while (cin>>s, s[0]!='*') {
        if (SZ(s)==1) cin>>t;
        else t=s.substr(1);
        dic[s[0]]=t;
    }
    map<string, vector<string>> tex;
    while (cin>>s, s[0]!='*') {
        t.clear();
        for (auto& i:s) t+=dic[i];
        if (!tex.count(t)) tex[t]=vector<string>();
        tex[t].pb(s);
    }
    while (cin>>s, s[0]!='*') {
        if (tex.count(s)) {
            cout<<tex[s][0];
            if (SZ(tex[s])>1) cout<<'!';
            cout<<endl;
        } else {
            int mi=INF;
            for (auto& i:tex) mi=min(mi,dis(i.fi,s));
            for (auto& i:tex) if (mi==dis(i.fi,s)) {
                cout<<i.se[0]<<'?'<<endl;
                break;
            }
        }
    }

    return 0;
}












































