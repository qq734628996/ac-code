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
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int a[30], n;
string buf;

inline void rev(int st, int ed)
{
    while (st < ed) swap(a[st++], a[ed--]);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (getline(cin, buf)) {
        cout << buf << endl;
        stringstream ss(buf);
        for (n = 0; ss >> a[n];n++);
        int len = n;
        while (n > 1) {
            int ma = n-1;
            REP(i,n) if (a[i] > a[ma]) ma = i;
            if (ma == n-1) { n--; continue; }
            if (ma) { printf("%d ", len-ma); rev(0, ma); }
            printf("%d ", len-n+1); rev(0, n-1);
            n--;
        }
        puts("0");
    }

    return 0;
}












































































