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
const int MAXN  = 1e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, k, cnt;
char s[MAXN];

bool vld()
{
    int l = 0, r = n-1;
    while (l < r) {
        if (s[l++] != s[r--]) cnt++;
    }
    return cnt <= k;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d%s", &n, &k, s);
    if (vld()) {
        int l = 0, r = n-1;
        while (l < r) {
            if (s[l] != s[r]) {
                if (k > cnt && s[l] != '9' && s[r] != '9') {
                    s[l] = s[r] = '9';
                    k--;
                } else s[l] = s[r] = max(s[l], s[r]);
            } else {
                if (k > cnt && (s[l]=='9' || s[r]=='9')) {
                    if (!(s[l]=='9' && s[r]=='9')) {
                        s[l] = s[r] = '9';
                        k--;
                    }
                } else if (k-1 > cnt) {
                    s[l] = s[r] = '9';
                    k -= 2;
                }
            }
            l++; r--;
        }
        if (k > cnt) s[l] = '9';
        puts(s);
    } else puts("-1");

    return 0;
}











































































