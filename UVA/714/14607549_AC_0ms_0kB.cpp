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
const int MAXN  = 5e2+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, k, a[MAXN];
LL s[MAXN];
vector<int> ans;

bool jdg(LL x)
{
    int i = 0, j = 1, cnt = 0;
    for ( ; j <= n; j++) {
        if (s[j] - s[i] > x) {
            if (j-i <= 1) return false;
            cnt++;
            i = --j;
        }
    }
    return cnt <= k-1;
}

void getans(LL x)
{
    ans.clear(); k--;
    int i = n-1, j = n;
    for ( ; i > 0; i--) {
        if (s[j]-s[i] > x) {
            k--;
            ans.push_back(j = ++i);
        } else if (i == k && i) {
            k--;
            ans.push_back(j = i);
        }
    }
    reverse(ALL(ans));
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        FOR(i,1,n) scanf("%d", &a[i]);
        FOR(i,1,n) s[i] = s[i-1] + a[i];
        LL l = 0, r = (LL)n*10000000;
        while (l < r) {
            LL m = l + (r-l)/2;
            if (jdg(m)) r = m;
            else l = m+1;
        }
        getans(r);
        int j = 0;
        FOR(i,1,n) {
            if (i > 1) putchar(' ');
            printf("%d", a[i]);
            if (j < SZ(ans) && i==ans[j]) {
                printf(" /");
                j++;
            }
        }
        puts("");
    }

    return 0;
}











































































