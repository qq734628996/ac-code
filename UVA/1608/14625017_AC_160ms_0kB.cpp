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
const int MAXN  = 2e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, a[MAXN], fst[MAXN], lst[MAXN];
unordered_map<int, int> mp;

bool jdg(int l, int r)
{
    if (r <= l) return true;
    int i = l, j = r, id = -1;
    while (i <= j) {
        if (lst[i] < l && r < fst[i]) { id = i; break; }
        if (lst[j] < l && r < fst[j]) { id = j; break; }
        i++; j--;
    }
    if (!(~id)) return false;
    return jdg(l, id-1) && jdg(id+1, r);
}

inline void scanInt(int&x) {
    char ch;
    while (ch = getchar(), ch < '0' || ch > '9');
    x = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0';
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanInt(T);
    while (T--) {
        scanInt(n);
        REP(i,n) scanInt(a[i]);
        mp.clear();
        REP(i,n) {
            if (!mp.count(a[i])) lst[i] = -1;
            else lst[i] = mp[a[i]];
            mp[a[i]] = i;
        }
        mp.clear();
        for (int i = n-1; i >= 0; i--) {
            if (!mp.count(a[i])) fst[i] = n;
            else fst[i] = mp[a[i]];
            mp[a[i]] = i;
        }
        if (jdg(0, n-1)) printf("non-");
        puts("boring");
    }

    return 0;
}











































































