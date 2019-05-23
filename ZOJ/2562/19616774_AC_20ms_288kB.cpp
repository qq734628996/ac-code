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
const int MAXN = 1e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

typedef unsigned long long ull;
int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
ull n,ans,ans_num;
void dfs(int dep, ull now, int num, int up)
{
    if (dep>=16 || now>n) return;
    if (num>ans_num || (num==ans_num && ans>now)) {
        ans=now;
        ans_num=num;
    }
    FOR(i,1,up) {
        if (now*p[dep]>n) break;
        dfs(dep+1,now*=p[dep],num*(i+1),i);
    }
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%llu", &n)==1) {
        ans_num=0;
        dfs(0,1,1,60);
        printf("%llu\n", ans);
    }

    return 0;
}





































