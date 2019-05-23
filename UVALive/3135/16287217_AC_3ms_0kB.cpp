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
    int Qnum, Period, Time;
    bool operator<(const Item& o) const {
        return Time > o.Time || (Time == o.Time && Qnum > o.Qnum);
    }
} x;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    priority_queue<Item> pq;
    char s[20];
    while (scanf("%s", s), s[0] != '#') {
        scanf("%d%d", &x.Qnum, &x.Period);
        x.Time = x.Period;
        pq.push(x);
    }
    int k; scanf("%d", &k);
    while (k--) {
        Item t = pq.top(); pq.pop();
        printf("%d\n", t.Qnum);
        t.Time += t.Period;
        pq.push(t);
    }

    return 0;
}












































































