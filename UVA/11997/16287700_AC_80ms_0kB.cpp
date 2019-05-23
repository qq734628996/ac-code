#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
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
const int MAXN = 1e3+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

struct Item {
    int S, b;
    bool operator<(const Item& rhs) const {
        return S > rhs.S;
    }
};
void Merge(int* A, int* B, int* C, int n)
{
    priority_queue<Item> pq;
    REP(i,n) pq.push((Item){A[i]+B[0], 0});
    REP(i,n) {
        Item t = pq.top(); pq.pop();
        C[i] = t.S;
        int b = t.b;
        if (b+1 < n) pq.push((Item){C[i]-B[b]+B[b+1], b+1});
    }
}

int n, a[MAXN], ans[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        REP(i,n) scanf("%d", &ans[i]);
        sort(ans, ans+n);
        REP(i,n-1) {
            REP(j,n) scanf("%d", &a[j]);
            sort(a, a+n);
            Merge(ans, a, ans, n);
        }
        SHOW1(ans,n)
    }

    return 0;
}












































































