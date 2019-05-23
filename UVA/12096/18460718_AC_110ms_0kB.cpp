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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

#define INS(x) inserter(x,x.begin())
typedef set<int> S;
map<S,int> mp;
vector<S> V;
int ID(S s)
{
    if (mp.count(s)) return mp[s];
    V.pb(s);
    return mp[s]=SZ(V)-1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        mp.clear();
        V.clear();
        stack<int> stk;
        int n; scanf("%d", &n);
        REP(i,n) {
            char op[11];
            scanf("%s", op);
            if (op[0]=='P') stk.push(ID(S()));
            else if (op[0]=='D') stk.push(stk.top());
            else {
                S& x=V[stk.top()]; stk.pop();
                S& y=V[stk.top()]; stk.pop();
                S ans;
                if (op[0]=='U') set_union(ALL(x),ALL(y),INS(ans));
                else if (op[0]=='I') set_intersection(ALL(x),ALL(y),INS(ans));
                else ans=y, ans.insert(ID(x));
                stk.push(ID(ans));
            }
            printf("%d\n", SZ(V[stk.top()]));
        }
        puts("***");
    }

    return 0;
}












































