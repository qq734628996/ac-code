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
const int MAXN = 5e4+9, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10007;

#include <ext/rope>
using namespace __gnu_cxx;
rope<char>* a[MAXN];
int n,op,v,p,k,cnt,tot;
char s[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &n);
    a[tot] = new rope<char>;
    while (n--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%s", &p,s);
            ++tot;
            a[tot] = new rope<char>(*a[tot-1]);
            a[tot]->insert(p-cnt,s);
        } else if (op == 2) {
            scanf("%d%d", &p,&k);
            ++tot;
            a[tot] = new rope<char>(*a[tot-1]);
            a[tot]->erase(p-cnt-1,k-cnt);
        } else {
            scanf("%d%d%d", &v,&p,&k);
            auto res = a[v-cnt]->substr(p-cnt-1,k-cnt);
            cnt += count(ALL(res),'c');
            cout << res << endl;
        }
    }

    return 0;
}









































































